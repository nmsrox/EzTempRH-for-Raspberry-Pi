/*******************************************************************************
* File Name: Thermistor.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the ThermistorCalc
*  Component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Thermistor.h"


/*******************************************************************************
* Function Name: Thermistor_GetResistance
********************************************************************************
*
* Summary:
*  The digital values of the voltages across the reference resistor and the
*  thermistor are passed to this function as parameters. The function returns
*  the resistance, based on the voltage values.
*
* Parameters:
*  vReference: the voltage across the reference resistor;
*  vThermistor: the voltage across the thermistor.
*  The ratio of these two voltages is used by this function. Therefore, the
*  units for both parameters must be the same.
*
* Return:
*  The return value is the resistance across the thermistor. The value returned
*  is the resistance in Ohms.
*
*******************************************************************************/
uint32 Thermistor_GetResistance(int16 vReference, int16 vThermistor)
                                      
{
    int32 resT;
    int16 temp;

    /* Calculate thermistor resistance from the voltages */
    resT = Thermistor_REF_RESISTOR * ((int32)vThermistor);
    if (vReference < 0)
    {
        temp = -vReference;
        temp = (int16)((uint16)((uint16)temp >> 1u));
        temp = -temp;
    }
    else
    {
        temp = (int16)((uint16)((uint16)vReference >> 1u));
    }
    resT += temp;
    resT /= vReference;

    /* The ordering of Reference resistor value is specifically designed to keep the result from overflowing */
    return ((uint32)((uint32)resT << Thermistor_REF_RES_SHIFT));
}


/*******************************************************************************
* Function Name: Thermistor_GetTemperature
********************************************************************************
*
* Summary:
*  The value of the thermistor resistance is passed to this function as a
*  parameter. The function returns the temperature, based on the resistance
*  value. The method used to calculate the temperature is dependent on whether
*  Equation or LUT was selected in the Customizer.
*
* Parameters:
*  resT: the resistance across the thermistor in Ohms.
*
* Return:
*  The return value is the temperature in 1/100ths of degrees C. For example,
*  the return value is 2345, when the actual temperature is 23.45 degrees C.
*
*******************************************************************************/
int16 Thermistor_GetTemperature(uint32 resT) 
{
    int16 tempTR;
    static const uint32 CYCODE Thermistor_LUT[] = { 43440u, 43238u, 43036u, 42836u, 42637u, 42439u, 42241u, 42045u, 41850u,
 41656u, 41463u, 41271u, 41080u, 40890u, 40701u, 40513u, 40326u, 40140u, 39955u, 39771u, 39588u, 39406u, 39225u, 39045u,
 38865u, 38687u, 38510u, 38333u, 38158u, 37983u, 37809u, 37636u, 37464u, 37293u, 37123u, 36954u, 36785u, 36618u, 36451u,
 36286u, 36121u, 35957u, 35793u, 35631u, 35469u, 35309u, 35149u, 34990u, 34832u, 34674u, 34518u, 34362u, 34207u, 34053u,
 33899u, 33746u, 33595u, 33444u, 33293u, 33144u, 32995u, 32847u, 32700u, 32553u, 32408u, 32263u, 32118u, 31975u, 31832u,
 31690u, 31549u, 31408u, 31268u, 31129u, 30991u, 30853u, 30716u, 30579u, 30444u, 30309u, 30174u, 30041u, 29908u, 29775u,
 29644u, 29513u, 29383u, 29253u, 29124u, 28996u, 28868u, 28741u, 28614u, 28489u, 28364u, 28239u, 28115u, 27992u, 27869u,
 27747u, 27626u, 27505u, 27385u, 27265u, 27146u, 27028u, 26910u, 26793u, 26676u, 26560u, 26444u, 26329u, 26215u, 26101u,
 25988u, 25875u, 25763u, 25652u, 25541u, 25430u, 25320u, 25211u, 25102u, 24994u, 24886u, 24779u, 24672u, 24566u, 24460u,
 24355u, 24251u, 24146u, 24043u, 23940u, 23837u, 23735u, 23634u, 23532u, 23432u, 23332u, 23232u, 23133u, 23034u, 22936u,
 22839u, 22741u, 22645u, 22549u, 22453u, 22357u, 22263u, 22168u, 22074u, 21981u, 21888u, 21795u, 21703u, 21611u, 21520u,
 21429u, 21339u, 21249u, 21160u, 21071u, 20982u, 20894u, 20806u, 20719u, 20632u, 20545u, 20459u, 20373u, 20288u, 20203u,
 20119u, 20035u, 19951u, 19868u, 19785u, 19703u, 19621u, 19539u, 19458u, 19377u, 19296u, 19216u, 19136u, 19057u, 18978u,
 18899u, 18821u, 18743u, 18666u, 18589u, 18512u, 18436u, 18360u, 18284u, 18209u, 18134u, 18059u, 17985u, 17911u, 17837u,
 17764u, 17691u, 17619u, 17547u, 17475u, 17403u, 17332u, 17261u, 17191u, 17121u, 17051u, 16981u, 16912u, 16843u, 16775u,
 16706u, 16639u, 16571u, 16504u, 16437u, 16370u, 16304u, 16238u, 16172u, 16107u, 16041u, 15977u, 15912u, 15848u, 15784u,
 15720u, 15657u, 15594u, 15531u, 15469u, 15407u, 15345u, 15283u, 15222u, 15161u, 15100u, 15040u, 14980u, 14920u, 14860u,
 14801u, 14742u, 14683u, 14624u, 14566u, 14508u, 14450u, 14393u, 14336u, 14279u, 14222u, 14166u, 14109u, 14054u, 13998u,
 13943u, 13887u, 13832u, 13778u, 13723u, 13669u, 13615u, 13562u, 13508u, 13455u, 13402u, 13349u, 13297u, 13245u, 13193u,
 13141u, 13090u, 13038u, 12987u, 12936u, 12886u, 12835u, 12785u, 12735u, 12686u, 12636u, 12587u, 12538u, 12489u, 12441u,
 12392u, 12344u, 12296u, 12248u, 12201u, 12154u, 12107u, 12060u, 12013u, 11967u, 11920u, 11874u, 11828u, 11783u, 11737u,
 11692u, 11647u, 11602u, 11558u, 11513u, 11469u, 11425u, 11381u, 11337u, 11294u, 11251u, 11208u, 11165u, 11122u, 11080u,
 11037u, 10995u, 10953u, 10911u, 10870u, 10829u, 10787u, 10746u, 10705u, 10665u, 10624u, 10584u, 10544u, 10504u, 10464u,
 10424u, 10385u, 10346u, 10307u, 10268u, 10229u, 10190u, 10152u, 10114u, 10076u, 10038u, 10000u, 9962u, 9925u, 9888u,
 9851u, 9814u, 9777u, 9740u, 9704u, 9668u, 9631u, 9595u, 9560u, 9524u, 9488u, 9453u, 9418u, 9383u, 9348u, 9313u, 9278u,
 9244u, 9210u, 9175u, 9141u, 9107u, 9074u, 9040u, 9007u, 8973u, 8940u, 8907u, 8874u, 8842u, 8809u, 8777u, 8744u, 8712u,
 8680u, 8648u, 8616u, 8585u, 8553u, 8522u, 8491u, 8459u, 8428u, 8398u, 8367u, 8336u, 8306u, 8276u, 8245u, 8215u, 8185u,
 8156u, 8126u, 8096u, 8067u, 8038u, 8008u, 7979u, 7950u, 7921u, 7893u, 7864u, 7836u, 7807u, 7779u, 7751u, 7723u, 7695u,
 7667u, 7640u, 7612u, 7585u, 7558u, 7530u, 7503u, 7476u, 7450u, 7423u, 7396u, 7370u, 7343u, 7317u, 7291u, 7265u, 7239u,
 7213u, 7187u, 7162u, 7136u, 7111u, 7085u, 7060u, 7035u, 7010u, 6985u, 6960u, 6935u, 6911u, 6886u, 6862u, 6838u, 6813u,
 6789u, 6765u, 6741u, 6718u, 6694u, 6670u, 6647u, 6623u, 6600u, 6577u, 6554u, 6531u, 6508u, 6485u, 6462u, 6439u, 6417u,
 6394u, 6372u, 6350u, 6328u, 6305u, 6283u, 6261u, 6240u, 6218u, 6196u, 6175u, 6153u, 6132u, 6110u, 6089u, 6068u, 6047u,
 6026u, 6005u, 5984u, 5964u, 5943u, 5922u, 5902u, 5881u, 5861u, 5841u, 5821u, 5801u, 5781u, 5761u, 5741u, 5721u, 5702u,
 5682u, 5662u, 5643u, 5624u, 5604u, 5585u, 5566u, 5547u, 5528u, 5509u, 5490u, 5472u, 5453u, 5434u, 5416u, 5397u, 5379u,
 5361u, 5342u, 5324u, 5306u, 5288u, 5270u, 5252u, 5234u, 5217u, 5199u, 5181u, 5164u, 5146u, 5129u, 5112u, 5095u, 5077u,
 5060u, 5043u, 5026u, 5009u, 4992u, 4976u, 4959u, 4942u, 4926u, 4909u, 4893u, 4876u, 4860u, 4844u, 4827u, 4811u, 4795u,
 4779u, 4763u, 4747u, 4732u, 4716u, 4700u, 4684u, 4669u, 4653u, 4638u, 4623u, 4607u, 4592u, 4577u, 4562u, 4546u, 4531u,
 4516u, 4501u, 4487u, 4472u, 4457u, 4442u, 4428u, 4413u, 4399u, 4384u, 4370u, 4355u, 4341u, 4327u, 4312u, 4298u, 4284u,
 4270u, 4256u, 4242u, 4228u, 4215u, 4201u, 4187u, 4173u, 4160u, 4146u, 4133u, 4119u, 4106u, 4093u, 4079u, 4066u, 4053u,
 4040u, 4026u, 4013u, 4000u, 3987u, 3975u, 3962u, 3949u, 3936u, 3923u, 3911u, 3898u, 3886u, 3873u, 3861u, 3848u, 3836u,
 3823u, 3811u, 3799u, 3787u, 3774u, 3762u, 3750u, 3738u, 3726u, 3714u, 3703u, 3691u, 3679u, 3667u, 3655u, 3644u, 3632u,
 3621u, 3609u, 3598u, 3586u, 3575u, 3563u, 3552u, 3541u, 3530u, 3518u, 3507u, 3496u, 3485u, 3474u, 3463u, 3452u, 3441u,
 3430u, 3419u, 3409u, 3398u, 3387u, 3377u, 3366u, 3355u, 3345u, 3334u, 3324u, 3313u, 3303u, 3293u, 3282u, 3272u, 3262u,
 3252u, 3241u, 3231u, 3221u, 3211u, 3201u, 3191u, 3181u, 3171u, 3161u, 3152u, 3142u, 3132u, 3122u, 3113u, 3103u, 3093u,
 3084u, 3074u, 3065u, 3055u, 3046u, 3036u, 3027u };


    #if (Thermistor_IMPLEMENTATION == Thermistor_EQUATION_METHOD)

        float32 stEqn;
        float32 logrT;

        /* Calculate thermistor resistance from the voltages */
        #if(!CY_PSOC3)
            logrT = (float32)log((float64)resT);
        #else
            logrT = log((float32)resT);
        #endif  /* (!CY_PSOC3) */

        /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
        #if(!CY_PSOC3)
            stEqn = (float32)(Thermistor_THA + (Thermistor_THB * logrT) + 
                             (Thermistor_THC * pow((float64)logrT, (float32)3)));
        #else
            stEqn = (float32)(Thermistor_THA + (Thermistor_THB * logrT) + 
                             (Thermistor_THC * pow(logrT, (float32)3)));
        #endif  /* (!CY_PSOC3) */

        tempTR = (int16)((float32)((((1.0 / stEqn) - Thermistor_K2C) * (float32)Thermistor_SCALE) + 0.5));

    #else /* Thermistor_IMPLEMENTATION == Thermistor_LUT_METHOD */

        uint16 mid;
        uint16 first = 0u;
        uint16 last = Thermistor_LUT_SIZE - 1u;

        /* Calculate temperature from the resistance of thermistor by using the LUT */
        while (first < last)
        {
            mid = (first + last) >> 1u;

            if ((0u == mid) || ((Thermistor_LUT_SIZE - 1u) == mid) || (resT == Thermistor_LUT[mid]))
            {
                last = mid;
                break;
            }
            else if (Thermistor_LUT[mid] > resT)
            {
                first = mid + 1u;
            }
            else /* (Thermistor_LUT[mid] < resT) */
            {
                last = mid - 1u;
            }
        }

        /* Calculation the closest entry in the LUT */
        if ((Thermistor_LUT[last] > resT) && (last < (Thermistor_LUT_SIZE - 1u)) &&
           ((Thermistor_LUT[last] - resT) > (resT - Thermistor_LUT[last + 1u])))
        {
            last++;
        }
        else if ((Thermistor_LUT[last] < resT) && (last > 0u) &&
                ((Thermistor_LUT[last - 1u] - resT) < (resT - Thermistor_LUT[last])))
        {
            last--;
        }
        else
        {
            /* Closest entry in the LUT already found */
        }

        tempTR = Thermistor_MIN_TEMP + (int16)((uint16)(last * Thermistor_ACCURACY));

    #endif /* (Thermistor_IMPLEMENTATION == Thermistor_EQUATION_METHOD) */

    return (tempTR);
}


/* [] END OF FILE */

/*******************************************************************************
* File Name: RH_T.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RH_T_H) /* Pins RH_T_H */
#define CY_PINS_RH_T_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RH_T_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RH_T_Write(uint8 value) ;
void    RH_T_SetDriveMode(uint8 mode) ;
uint8   RH_T_ReadDataReg(void) ;
uint8   RH_T_Read(void) ;
uint8   RH_T_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RH_T_DRIVE_MODE_BITS        (3)
#define RH_T_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RH_T_DRIVE_MODE_BITS))
#define RH_T_DRIVE_MODE_SHIFT       (0x00u)
#define RH_T_DRIVE_MODE_MASK        (0x07u << RH_T_DRIVE_MODE_SHIFT)

#define RH_T_DM_ALG_HIZ         (0x00u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_DIG_HIZ         (0x01u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_RES_UP          (0x02u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_RES_DWN         (0x03u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_OD_LO           (0x04u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_OD_HI           (0x05u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_STRONG          (0x06u << RH_T_DRIVE_MODE_SHIFT)
#define RH_T_DM_RES_UPDWN       (0x07u << RH_T_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define RH_T_MASK               RH_T__MASK
#define RH_T_SHIFT              RH_T__SHIFT
#define RH_T_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RH_T_PS                     (* (reg32 *) RH_T__PS)
/* Port Configuration */
#define RH_T_PC                     (* (reg32 *) RH_T__PC)
/* Data Register */
#define RH_T_DR                     (* (reg32 *) RH_T__DR)
/* Input Buffer Disable Override */
#define RH_T_INP_DIS                (* (reg32 *) RH_T__PC2)


#if defined(RH_T__INTSTAT)  /* Interrupt Registers */

    #define RH_T_INTSTAT                (* (reg32 *) RH_T__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins RH_T_H */


/* [] END OF FILE */

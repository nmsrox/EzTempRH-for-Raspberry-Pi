EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:caimanics_cypress
LIBS:caimanics_honeywell
LIBS:TempHRpi-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "12 sep 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CY8C4100-28SSOP U1
U 1 1 53BBA7E6
P 2350 1850
F 0 "U1" H 2000 2650 60  0000 C CNN
F 1 "CY8C4100-28SSOP" V 2350 1850 60  0000 C CNN
F 2 "~" H 1900 2500 60  0000 C CNN
F 3 "~" H 1900 2500 60  0000 C CNN
	1    2350 1850
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 53BBA879
P 1850 3650
F 0 "C2" H 1850 3750 40  0000 L CNN
F 1 "1uF" H 1856 3565 40  0000 L CNN
F 2 "~" H 1888 3500 30  0000 C CNN
F 3 "~" H 1850 3650 60  0000 C CNN
	1    1850 3650
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 53BBA888
P 2100 3650
F 0 "C3" H 2100 3750 40  0000 L CNN
F 1 ".1uF" H 2106 3565 40  0000 L CNN
F 2 "~" H 2138 3500 30  0000 C CNN
F 3 "~" H 2100 3650 60  0000 C CNN
	1    2100 3650
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 53BBA8AE
P 2350 3650
F 0 "C4" H 2350 3750 40  0000 L CNN
F 1 "1uF" H 2356 3565 40  0000 L CNN
F 2 "~" H 2388 3500 30  0000 C CNN
F 3 "~" H 2350 3650 60  0000 C CNN
	1    2350 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 3250 1850 3450
Wire Wire Line
	2100 3250 2100 3450
Wire Wire Line
	2350 3250 2350 3450
Wire Wire Line
	1850 3850 1850 3950
Wire Wire Line
	2350 3850 2350 3950
Connection ~ 2350 3950
Wire Wire Line
	2100 3850 2100 3950
Connection ~ 2100 3950
Text Label 1850 3250 3    60   ~ 0
Vddd
Text Label 2100 3250 3    60   ~ 0
Vddd
Text Label 2350 3250 3    60   ~ 0
Vccd
Text Label 2650 3950 2    60   ~ 0
Vss
Wire Wire Line
	3400 1200 3100 1200
Wire Wire Line
	3400 1400 3100 1400
$Comp
L R R3
U 1 1 53BBACA5
P 1750 5300
F 0 "R3" V 1830 5300 40  0000 C CNN
F 1 "R" V 1757 5301 40  0000 C CNN
F 2 "~" V 1680 5300 30  0000 C CNN
F 3 "~" H 1750 5300 30  0000 C CNN
	1    1750 5300
	1    0    0    -1  
$EndComp
$Comp
L THERMISTOR TH1
U 1 1 53BBACB4
P 1750 5800
F 0 "TH1" V 1850 5850 50  0000 C CNN
F 1 "THERMISTOR" V 1650 5800 50  0000 C CNN
F 2 "~" H 1750 5800 60  0000 C CNN
F 3 "~" H 1750 5800 60  0000 C CNN
	1    1750 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1800 3100 1800
Wire Wire Line
	1300 1600 1600 1600
Wire Wire Line
	1300 1700 1600 1700
Wire Wire Line
	1300 1800 1600 1800
Wire Wire Line
	1300 1900 1600 1900
Wire Wire Line
	1300 2400 1600 2400
Wire Wire Line
	1300 2500 1600 2500
Wire Wire Line
	3400 1500 3100 1500
Text Label 1300 1600 0    60   ~ 0
TH_H
Text Label 1300 1700 0    60   ~ 0
TH_T
Text Label 1300 1800 0    60   ~ 0
HR_T
Text Label 1300 1900 0    60   ~ 0
HR_L
Text Label 3400 1800 2    60   ~ 0
TH_L
Text Label 3400 2000 2    60   ~ 0
EN
Text Label 3400 2400 2    60   ~ 0
TX
Text Label 3400 2500 2    60   ~ 0
RX
NoConn ~ 1600 1200
NoConn ~ 1600 1300
NoConn ~ 1600 1400
NoConn ~ 1600 1500
NoConn ~ 1600 2200
NoConn ~ 1600 2300
NoConn ~ 3100 2300
NoConn ~ 3100 2200
NoConn ~ 3100 1900
NoConn ~ 3100 1700
NoConn ~ 3100 1600
Text Label 3400 1200 2    60   ~ 0
Vss
Text Label 3400 1300 2    60   ~ 0
Vddd
Text Label 3400 1400 2    60   ~ 0
Vccd
Text Label 3400 1500 2    60   ~ 0
XRES
Text Label 1300 2400 0    60   ~ 0
SWDIO
Text Label 1300 2500 0    60   ~ 0
SWDCK
Wire Wire Line
	1450 5000 2050 5000
Wire Wire Line
	1750 4900 1750 5050
Wire Wire Line
	1450 6100 2050 6100
Wire Wire Line
	1750 6050 1750 6200
Wire Wire Line
	1750 6200 2050 6200
Connection ~ 1750 6100
Text Label 2050 4900 2    60   ~ 0
EN
Text Label 2050 5550 2    60   ~ 0
TH_T
Wire Wire Line
	2050 4900 1750 4900
Connection ~ 1750 5000
Text Label 2050 5000 2    60   ~ 0
TH_H
Text Label 2050 6100 2    60   ~ 0
TH_L
Text Label 2050 6200 2    60   ~ 0
Vss
Wire Wire Line
	3400 2000 3100 2000
$Comp
L C C5
U 1 1 53BBBDB9
P 1450 5550
F 0 "C5" H 1450 5650 40  0000 L CNN
F 1 "C" H 1456 5465 40  0000 L CNN
F 2 "~" H 1488 5400 30  0000 C CNN
F 3 "~" H 1450 5550 60  0000 C CNN
	1    1450 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5000 1450 5350
Wire Wire Line
	1450 5750 1450 6100
$Comp
L CONN_4 P1
U 1 1 53BBC032
P 4750 3000
F 0 "P1" V 4700 3000 50  0000 C CNN
F 1 "CONN_4" V 4800 3000 50  0000 C CNN
F 2 "" H 4750 3000 60  0000 C CNN
F 3 "" H 4750 3000 60  0000 C CNN
	1    4750 3000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5400 2850 5100 2850
Wire Wire Line
	5400 2950 5100 2950
Wire Wire Line
	5400 3050 5100 3050
Wire Wire Line
	5400 3150 5100 3150
$Comp
L C C1
U 1 1 53BBC0FF
P 1600 3650
F 0 "C1" H 1600 3750 40  0000 L CNN
F 1 "2.2uF" H 1606 3565 40  0000 L CNN
F 2 "~" H 1638 3500 30  0000 C CNN
F 3 "~" H 1600 3650 60  0000 C CNN
	1    1600 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3250 1600 3450
Wire Wire Line
	1600 3850 1600 3950
Connection ~ 1850 3950
Text Label 1600 3250 3    60   ~ 0
Vddd
$Comp
L CONN_5 P3
U 1 1 53BBC20A
P 4650 4300
F 0 "P3" V 4600 4300 50  0000 C CNN
F 1 "CONN_5" V 4700 4300 50  0000 C CNN
F 2 "" H 4650 4300 60  0000 C CNN
F 3 "" H 4650 4300 60  0000 C CNN
	1    4650 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5400 4100 5050 4100
Wire Wire Line
	5400 4200 5050 4200
Wire Wire Line
	5400 4300 5050 4300
Wire Wire Line
	5400 4400 5050 4400
Wire Wire Line
	5400 4500 5050 4500
Text Label 5400 2850 2    60   ~ 0
Vddd
Text Label 5400 3150 2    60   ~ 0
Vss
Text Label 5400 2950 2    60   ~ 0
TX
Text Label 5400 3050 2    60   ~ 0
RX
Text Label 5400 4100 2    60   ~ 0
Vddd
Text Label 5400 4500 2    60   ~ 0
Vss
Text Label 5400 4200 2    60   ~ 0
XRES
Text Label 5400 4300 2    60   ~ 0
SWDCK
Text Label 5400 4400 2    60   ~ 0
SWDIO
$Comp
L HIH5030 U2
U 1 1 53BBD4DF
P 2600 5300
F 0 "U2" H 2800 5100 60  0000 C CNN
F 1 "HIH5030" H 2600 5700 60  0000 C CNN
F 2 "~" H 2600 5300 60  0000 C CNN
F 3 "~" H 2600 5300 60  0000 C CNN
	1    2600 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5650 2700 5950
Wire Wire Line
	2600 5650 2600 6150
Wire Wire Line
	2500 5650 2500 6650
Text Label 2950 6650 2    60   ~ 0
Vss
Text Label 2600 5950 1    60   ~ 0
HR_T
Text Label 2700 5950 1    60   ~ 0
HR_H
Wire Wire Line
	2700 5650 2800 5650
Wire Wire Line
	2800 5650 2800 5950
Text Label 2800 5950 1    60   ~ 0
EN
NoConn ~ 3100 2100
Wire Wire Line
	1300 2000 1600 2000
Wire Wire Line
	1300 2100 1600 2100
Text Label 1300 2000 0    60   ~ 0
ADC_P
Text Label 1300 2100 0    60   ~ 0
ADC_M
Wire Wire Line
	3400 2400 3100 2400
Wire Wire Line
	3400 2500 3100 2500
Wire Wire Line
	3400 1300 3100 1300
Wire Wire Line
	5400 1600 5100 1600
Wire Wire Line
	5400 1700 5100 1700
Wire Wire Line
	5400 1800 5100 1800
Wire Wire Line
	5400 1900 5100 1900
Text Label 5400 1600 2    60   ~ 0
EN
Text Label 5400 1700 2    60   ~ 0
ADC_P
Text Label 5400 1800 2    60   ~ 0
ADC_M
Text Label 5400 1900 2    60   ~ 0
Vss
$Comp
L CONN_5 P2
U 1 1 541068E4
P 4700 1700
F 0 "P2" V 4650 1700 50  0000 C CNN
F 1 "CONN_5" V 4750 1700 50  0000 C CNN
F 2 "" H 4700 1700 60  0000 C CNN
F 3 "" H 4700 1700 60  0000 C CNN
	1    4700 1700
	-1   0    0    -1  
$EndComp
Text Label 5400 1500 2    60   ~ 0
Vddd
Wire Wire Line
	5400 1500 5100 1500
$Comp
L C C6
U 1 1 54106932
P 2700 6400
F 0 "C6" H 2700 6500 40  0000 L CNN
F 1 "C" H 2706 6315 40  0000 L CNN
F 2 "~" H 2738 6250 30  0000 C CNN
F 3 "~" H 2700 6400 60  0000 C CNN
	1    2700 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 6150 2700 6150
Wire Wire Line
	2700 6150 2700 6200
Wire Wire Line
	2700 6600 2700 6650
Wire Wire Line
	2500 6650 2950 6650
Connection ~ 2700 6650
Wire Wire Line
	2050 5550 1750 5550
Text Notes 4550 3900 0    60   ~ 0
Programmer header
Text Notes 4500 2600 0    60   ~ 0
Serial port to Raspberry Pi
Text Notes 4550 1300 0    60   ~ 0
External ADC signal
Text Notes 1550 3150 0    60   ~ 0
Bypass capacitors
Text Notes 1550 4750 0    60   ~ 0
Sensors
Wire Notes Line
	1200 4500 1200 6900
Wire Notes Line
	1200 6900 3200 6900
Wire Notes Line
	3200 6900 3200 4500
Wire Notes Line
	3200 4500 1200 4500
Wire Wire Line
	1600 3950 2650 3950
Wire Notes Line
	1200 4150 1200 2900
Wire Notes Line
	1200 2900 2900 2900
Wire Notes Line
	2900 2900 2900 4150
Wire Notes Line
	2900 4150 1200 4150
Wire Notes Line
	4300 1100 4300 2100
Wire Notes Line
	4300 2100 5700 2100
Wire Notes Line
	5700 2100 5700 1100
Wire Notes Line
	5700 1100 4300 1100
Wire Notes Line
	4300 2400 4300 3400
Wire Notes Line
	4300 3400 6000 3400
Wire Notes Line
	6000 3400 6000 2400
Wire Notes Line
	6000 2400 4300 2400
Wire Notes Line
	4300 3700 4300 4700
Wire Notes Line
	4300 4700 5700 4700
Wire Notes Line
	5700 4700 5700 3700
Wire Notes Line
	5700 3700 4300 3700
Text Notes 7400 7550 0    60   ~ 0
EzTemp&RH for Raspberry Pi
Text Notes 7100 7050 0    60   ~ 0
Copyright (c) 2014 - CAIMANICS (Pablo Bacho)\nPublished under the MIT License
$EndSCHEMATC

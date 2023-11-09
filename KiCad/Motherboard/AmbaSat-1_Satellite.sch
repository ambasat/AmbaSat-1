EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 1
Title "AmbaSat-1"
Date "2021-11-16"
Rev "KiCad_1.0"
Comp ""
Comment1 "Sprite class satellite (ChipSat/Femtosatellite)"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5100 4750 5100 4550
Wire Wire Line
	6100 4400 6100 4900
Wire Wire Line
	3050 2650 2400 2650
Wire Wire Line
	3050 2750 2750 2750
Wire Wire Line
	2750 2750 2750 2850
Wire Wire Line
	2750 2850 2400 2850
Wire Wire Line
	3050 2950 2650 2950
Wire Wire Line
	2650 2950 2650 3050
Wire Wire Line
	2650 3050 2650 3150
Wire Wire Line
	2650 3150 2650 3250
Wire Wire Line
	3050 3050 2650 3050
Wire Wire Line
	3050 3150 2650 3150
Connection ~ 2650 3050
Connection ~ 2650 3150
Wire Wire Line
	5100 5100 5100 5450
Text Label 5400 1750 0    70   ~ 0
RESET
Text Label 4950 6650 0    70   ~ 0
RESET
Wire Wire Line
	3050 2250 2650 2250
Text Label 2700 2250 0    70   ~ 0
SS
Wire Wire Line
	7200 2300 6850 2300
Text Label 6900 2300 0    70   ~ 0
SS
Text Label 3850 7050 0    70   ~ 0
SS
Wire Wire Line
	3050 2350 2650 2350
Text Label 2700 2350 0    70   ~ 0
MOSI
Wire Wire Line
	7200 2100 6850 2100
Text Label 6900 2100 0    70   ~ 0
MOSI
Text Label 1800 6850 0    70   ~ 0
MOSI
Wire Wire Line
	3050 2450 2650 2450
Text Label 2700 2450 0    70   ~ 0
MISO
Wire Wire Line
	7200 2000 6850 2000
Text Label 6900 2000 0    70   ~ 0
MISO
Text Label 1800 6750 0    70   ~ 0
MISO
Wire Wire Line
	4450 1950 4850 1950
Text Label 4500 1950 0    70   ~ 0
RX
Text Label 3850 6850 0    70   ~ 0
RX
Wire Wire Line
	4450 2050 4850 2050
Text Label 4500 2050 0    70   ~ 0
TX
Text Label 3850 6750 0    70   ~ 0
TX
Wire Wire Line
	4450 1650 4850 1650
Text Label 4500 1650 0    70   ~ 0
SCL
Text Label 1800 7150 0    70   ~ 0
SCL
Text Label 9400 4500 0    70   ~ 0
SCL
Wire Wire Line
	4450 1550 4850 1550
Text Label 4500 1550 0    70   ~ 0
SDA
Text Label 1800 7050 0    70   ~ 0
SDA
Text Label 9400 4400 0    70   ~ 0
SDA
Wire Wire Line
	4450 2150 4850 2150
Text Label 4500 2150 0    70   ~ 0
DIO0
Wire Wire Line
	8550 2100 8200 2100
Text Label 8250 2100 0    70   ~ 0
DIO0
Text Label 3850 6950 0    70   ~ 0
VIN
Wire Wire Line
	3200 4750 3100 4750
Wire Wire Line
	3200 4950 3100 4950
Wire Wire Line
	3100 4950 3100 4750
Text Label 2050 4750 0    70   ~ 0
VIN
Wire Wire Line
	4450 2250 4850 2250
Text Label 4500 2250 0    70   ~ 0
D3
Text Label 1800 6950 0    70   ~ 0
D3
Wire Wire Line
	4450 1150 4850 1150
Text Label 4500 1150 0    70   ~ 0
A0
Wire Wire Line
	8550 2000 8200 2000
Text Label 8250 2000 0    70   ~ 0
DIO1
Wire Wire Line
	4450 1350 4850 1350
Text Label 4500 1350 0    70   ~ 0
DIO1
Wire Wire Line
	3050 2550 2650 2550
Text Label 2700 2550 0    70   ~ 0
SCK
Wire Wire Line
	7200 2200 6850 2200
Text Label 6900 2200 0    70   ~ 0
SCK
Text Label 1800 6650 0    70   ~ 0
SCK
Wire Wire Line
	7700 4800 7450 4800
Wire Wire Line
	7450 4800 7450 4900
$Comp
L AmbaSat-1_Satellite-Symbols:RESONATOR-4MHZSMD-4.5X2 Y1
U 1 1 427827AE
P 2400 2750
F 0 "Y1" V 2200 2750 70  0000 C CNN
F 1 "4MHz" V 2600 2750 70  0000 C CNN
F 2 "AmbaSat-1_Satellite:RESONATOR-SMD-4.5X2.0" H 2400 2750 50  0001 C CNN
F 3 "" H 2400 2750 50  0001 C CNN
	1    2400 2750
	0    1    1    0   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C1
U 1 1 C8E3AF05
P 4450 6650
F 0 "C1" V 4300 6650 59  0000 C CNN
F 1 "100nF" V 4600 6650 59  0000 C CNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 4450 6650 50  0001 C CNN
F 3 "" H 4450 6650 50  0001 C CNN
	1    4450 6650
	0    1    1    0   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:LP2985AIM5-3.3 U3
U 1 1 AFB3254D
P 3700 4950
F 0 "U3" H 3410 5270 59  0000 L BNN
F 1 "LP2985AIM5-3.3" H 3700 4600 59  0000 C CNN
F 2 "AmbaSat-1_Satellite:SOT23-5P95_280X145L45X40M" H 3700 4950 50  0001 C CNN
F 3 "" H 3700 4950 50  0001 C CNN
	1    3700 4950
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C5
U 1 1 E380C306
P 5100 4950
F 0 "C5" H 5150 5000 59  0000 L BNN
F 1 "10uF" H 5150 4800 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 5100 4950 50  0001 C CNN
F 3 "" H 5100 4950 50  0001 C CNN
	1    5100 4950
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:LSM9DS1 U1
U 1 1 94FABF20
P 8300 5000
F 0 "U1" H 7800 5750 59  0000 L CNN
F 1 "LSM9DS1" H 8100 4250 59  0000 L CNN
F 2 "AmbaSat-1_Satellite:PQFN24P43_300X350X102L35X23M" H 8300 5000 50  0001 C CNN
F 3 "" H 8300 5000 50  0001 C CNN
	1    8300 5000
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C6
U 1 1 CFDC1CA0
P 6100 5050
F 0 "C6" H 6150 5100 59  0000 L BNN
F 1 "10uF" H 6150 4900 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 6100 5050 50  0001 C CNN
F 3 "" H 6100 5050 50  0001 C CNN
	1    6100 5050
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C7
U 1 1 C15D389E
P 6550 5050
F 0 "C7" H 6600 5100 59  0000 L BNN
F 1 "100nF" H 6600 4900 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 6550 5050 50  0001 C CNN
F 3 "" H 6550 5050 50  0001 C CNN
	1    6550 5050
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C9
U 1 1 F5E906B6
P 7450 5050
F 0 "C9" H 7500 5100 59  0000 L BNN
F 1 "100nF" H 7500 4900 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 7450 5050 50  0001 C CNN
F 3 "" H 7450 5050 50  0001 C CNN
	1    7450 5050
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:PINHD-1X8 JP1
U 1 1 0B60073D
P 1450 6950
F 0 "JP1" H 1350 6500 59  0000 C CNN
F 1 "PINHD-1X8" H 1350 7550 59  0000 C CNN
F 2 "AmbaSat-1_Satellite:1X08" H 1450 6950 50  0001 C CNN
F 3 "" H 1450 6950 50  0001 C CNN
	1    1450 6950
	-1   0    0    1   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:PINHD-1X6 JP2
U 1 1 BAFA783C
P 3500 6850
F 0 "JP2" H 3400 6500 59  0000 C CNN
F 1 "PINHD-1X6" H 3400 7350 59  0000 C CNN
F 2 "AmbaSat-1_Satellite:1X06" H 3500 6850 50  0001 C CNN
F 3 "" H 3500 6850 50  0001 C CNN
	1    3500 6850
	-1   0    0    1   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:R R3
U 1 1 DF39756A
P 9000 3800
F 0 "R3" H 8800 3800 59  0000 L CNN
F 1 "1K" V 9000 3800 39  0000 C CNN
F 2 "AmbaSat-1_Satellite:RESC160X80X55L25M" H 9000 3800 50  0001 C CNN
F 3 "" H 9000 3800 50  0001 C CNN
	1    9000 3800
	-1   0    0    1   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:R R4
U 1 1 C5ADFEB6
P 9350 3800
F 0 "R4" H 9150 3800 59  0000 L CNN
F 1 "1K" V 9350 3800 39  0000 C CNN
F 2 "AmbaSat-1_Satellite:RESC160X80X55L25M" H 9350 3800 50  0001 C CNN
F 3 "" H 9350 3800 50  0001 C CNN
	1    9350 3800
	-1   0    0    1   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:HEADER-1X1ROUND JP3
U 1 1 8182258E
P 8500 2750
F 0 "JP3" V 8900 2750 59  0000 C CNN
F 1 "HEADER-1X1ROUND" H 8250 2550 59  0001 L BNN
F 2 "AmbaSat-1_Satellite:1X01_ROUND" H 8500 2750 50  0001 C CNN
F 3 "" H 8500 2750 50  0001 C CNN
	1    8500 2750
	0    1    1    0   
$EndComp
Text Notes 8800 7100 0    39   ~ 0
Derived from https://github.com/ambasat/AmbaSat-1\n© 2020 AmbaSat Ltd\nAuthors: John Mowbray, \nMartin Platt, Sudu Malli\nWeb: ambasat.com
Wire Wire Line
	2100 2750 2000 2750
Wire Wire Line
	2000 2750 2000 2950
Wire Wire Line
	2650 7250 2650 7600
Wire Wire Line
	2150 7350 2150 7600
Wire Wire Line
	2150 7600 2400 7600
Wire Wire Line
	2400 7600 2400 7500
Wire Wire Line
	4100 7150 4100 7250
Wire Wire Line
	7000 4700 7000 4900
Wire Wire Line
	7700 4700 7000 4700
Wire Wire Line
	6100 4400 6550 4400
Wire Wire Line
	7700 4500 7600 4500
Wire Wire Line
	7600 4500 7600 4400
Connection ~ 7600 4400
Wire Wire Line
	7600 4400 7700 4400
Wire Wire Line
	6550 4400 6550 4900
Connection ~ 6550 4400
Wire Wire Line
	6550 4400 7600 4400
Wire Wire Line
	6100 4300 6100 4400
Connection ~ 6100 4400
Wire Wire Line
	6100 5600 6100 5700
Wire Wire Line
	6100 5600 6550 5600
Wire Wire Line
	7700 5500 7600 5500
Wire Wire Line
	7600 5500 7600 5600
Connection ~ 7600 5600
Wire Wire Line
	7600 5600 7700 5600
Wire Wire Line
	7450 5200 7450 5600
Connection ~ 7450 5600
Wire Wire Line
	7450 5600 7600 5600
Wire Wire Line
	7000 5200 7000 5600
Connection ~ 7000 5600
Wire Wire Line
	7000 5600 7450 5600
Wire Wire Line
	6550 5200 6550 5600
Connection ~ 6550 5600
Wire Wire Line
	6550 5600 7000 5600
Wire Wire Line
	6100 5200 6100 5600
Connection ~ 6100 5600
$Comp
L AmbaSat-1_Satellite-Symbols:C C4
U 1 1 674C1B16
P 2300 4950
F 0 "C4" H 2350 5000 59  0000 L BNN
F 1 "10uF" H 2350 4800 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 2300 4950 50  0001 C CNN
F 3 "" H 2300 4950 50  0001 C CNN
	1    2300 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 4750 2300 4800
Wire Wire Line
	2300 4750 2000 4750
Wire Wire Line
	5100 4750 5100 4800
Connection ~ 5100 4750
Wire Wire Line
	1650 6650 2150 6650
Wire Wire Line
	1650 6750 2150 6750
Wire Wire Line
	1650 6850 2150 6850
Wire Wire Line
	1650 6950 2150 6950
Wire Wire Line
	1650 7050 2150 7050
Wire Wire Line
	1650 7150 2150 7150
Wire Wire Line
	1650 7250 2650 7250
Wire Wire Line
	1650 7350 2150 7350
Wire Wire Line
	3700 6650 4300 6650
Wire Wire Line
	3700 6750 4100 6750
Wire Wire Line
	3700 6850 4100 6850
Wire Wire Line
	3700 6950 4100 6950
Wire Wire Line
	3700 7050 4100 7050
Wire Wire Line
	3700 7150 4100 7150
Wire Wire Line
	9000 3550 9350 3550
Wire Wire Line
	9350 3550 9350 3500
Connection ~ 9350 3550
Wire Wire Line
	9000 4400 9700 4400
Wire Wire Line
	9350 4500 9700 4500
Wire Wire Line
	8900 4400 9000 4400
Connection ~ 9000 4400
Wire Wire Line
	8900 4500 9350 4500
Connection ~ 9350 4500
Wire Wire Line
	8900 4600 9000 4600
Wire Wire Line
	9000 4600 9000 4700
Wire Wire Line
	9000 4900 9500 4900
Wire Wire Line
	9500 4900 9500 4800
Wire Wire Line
	8900 4700 9000 4700
Connection ~ 9000 4700
Wire Wire Line
	9000 4700 9000 4800
Wire Wire Line
	8900 4800 9000 4800
Connection ~ 9000 4800
Wire Wire Line
	9000 4800 9000 4900
Wire Wire Line
	8900 4900 9000 4900
Connection ~ 9000 4900
$Comp
L AmbaSat-1_Satellite-Symbols:C C8
U 1 1 428FE661
P 7000 5050
F 0 "C8" H 7050 5100 59  0000 L BNN
F 1 "10nF" H 7050 4900 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 7000 5050 50  0001 C CNN
F 3 "" H 7000 5050 50  0001 C CNN
	1    7000 5050
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0101
U 1 1 619160AC
P 1500 1100
F 0 "#PWR0101" H 1500 1275 20  0001 C CNN
F 1 "3V3" H 1503 1253 50  0000 C CNN
F 2 "" H 1500 1100 60  0001 C CNN
F 3 "" H 1500 1100 60  0001 C CNN
	1    1500 1100
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0102
U 1 1 619170D6
P 5250 1300
F 0 "#PWR0102" H 5250 1475 20  0001 C CNN
F 1 "3V3" H 5253 1453 50  0000 C CNN
F 2 "" H 5250 1300 60  0001 C CNN
F 3 "" H 5250 1300 60  0001 C CNN
	1    5250 1300
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0103
U 1 1 6191BAA5
P 9150 1850
F 0 "#PWR0103" H 9150 2025 20  0001 C CNN
F 1 "3V3" H 9153 2003 50  0000 C CNN
F 2 "" H 9150 1850 60  0001 C CNN
F 3 "" H 9150 1850 60  0001 C CNN
	1    9150 1850
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0104
U 1 1 61924D1D
P 9350 3500
F 0 "#PWR0104" H 9350 3675 20  0001 C CNN
F 1 "3V3" H 9353 3653 50  0000 C CNN
F 2 "" H 9350 3500 60  0001 C CNN
F 3 "" H 9350 3500 60  0001 C CNN
	1    9350 3500
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0105
U 1 1 619297F6
P 6100 4300
F 0 "#PWR0105" H 6100 4475 20  0001 C CNN
F 1 "3V3" H 6103 4453 50  0000 C CNN
F 2 "" H 6100 4300 60  0001 C CNN
F 3 "" H 6100 4300 60  0001 C CNN
	1    6100 4300
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0106
U 1 1 6192E1EC
P 5100 4550
F 0 "#PWR0106" H 5100 4725 20  0001 C CNN
F 1 "3V3" H 5103 4703 50  0000 C CNN
F 2 "" H 5100 4550 60  0001 C CNN
F 3 "" H 5100 4550 60  0001 C CNN
	1    5100 4550
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0107
U 1 1 619377D5
P 9500 4800
F 0 "#PWR0107" H 9500 4975 20  0001 C CNN
F 1 "3V3" H 9503 4953 50  0000 C CNN
F 2 "" H 9500 4800 60  0001 C CNN
F 3 "" H 9500 4800 60  0001 C CNN
	1    9500 4800
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:3V3 #PWR0108
U 1 1 6193C0F9
P 2400 7500
F 0 "#PWR0108" H 2400 7675 20  0001 C CNN
F 1 "3V3" H 2403 7653 50  0000 C CNN
F 2 "" H 2400 7500 60  0001 C CNN
F 3 "" H 2400 7500 60  0001 C CNN
	1    2400 7500
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0110
U 1 1 61941CFD
P 2000 2950
F 0 "#PWR0110" H 2000 2700 50  0001 C CNN
F 1 "GND" H 2005 2777 50  0000 C CNN
F 2 "" H 2000 2950 50  0001 C CNN
F 3 "" H 2000 2950 50  0001 C CNN
	1    2000 2950
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0111
U 1 1 61946548
P 2650 3250
F 0 "#PWR0111" H 2650 3000 50  0001 C CNN
F 1 "GND" H 2655 3077 50  0000 C CNN
F 2 "" H 2650 3250 50  0001 C CNN
F 3 "" H 2650 3250 50  0001 C CNN
	1    2650 3250
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0112
U 1 1 6194F82C
P 2300 5450
F 0 "#PWR0112" H 2300 5200 50  0001 C CNN
F 1 "GND" H 2305 5277 50  0000 C CNN
F 2 "" H 2300 5450 50  0001 C CNN
F 3 "" H 2300 5450 50  0001 C CNN
	1    2300 5450
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0113
U 1 1 6195D153
P 5100 5500
F 0 "#PWR0113" H 5100 5250 50  0001 C CNN
F 1 "GND" H 5105 5327 50  0000 C CNN
F 2 "" H 5100 5500 50  0001 C CNN
F 3 "" H 5100 5500 50  0001 C CNN
	1    5100 5500
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0114
U 1 1 619664B8
P 6100 5700
F 0 "#PWR0114" H 6100 5450 50  0001 C CNN
F 1 "GND" H 6105 5527 50  0000 C CNN
F 2 "" H 6100 5700 50  0001 C CNN
F 3 "" H 6100 5700 50  0001 C CNN
	1    6100 5700
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0115
U 1 1 61973FC1
P 9150 2350
F 0 "#PWR0115" H 9150 2100 50  0001 C CNN
F 1 "GND" H 9155 2177 50  0000 C CNN
F 2 "" H 9150 2350 50  0001 C CNN
F 3 "" H 9150 2350 50  0001 C CNN
	1    9150 2350
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0117
U 1 1 6198B1F8
P 2650 7600
F 0 "#PWR0117" H 2650 7350 50  0001 C CNN
F 1 "GND" H 2655 7427 50  0000 C CNN
F 2 "" H 2650 7600 50  0001 C CNN
F 3 "" H 2650 7600 50  0001 C CNN
	1    2650 7600
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0118
U 1 1 6199498E
P 4100 7250
F 0 "#PWR0118" H 4100 7000 50  0001 C CNN
F 1 "GND" H 4105 7077 50  0000 C CNN
F 2 "" H 4100 7250 50  0001 C CNN
F 3 "" H 4100 7250 50  0001 C CNN
	1    4100 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2150 3050 2150
Wire Wire Line
	2300 2150 2250 2150
Wire Wire Line
	9000 3550 9000 3650
Wire Wire Line
	9350 3550 9350 3650
Wire Wire Line
	9000 3950 9000 4400
Wire Wire Line
	9350 3950 9350 4500
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0109
U 1 1 61940C11
P 1800 2200
F 0 "#PWR0109" H 1800 1950 50  0001 C CNN
F 1 "GND" H 1805 2027 50  0000 C CNN
F 2 "" H 1800 2200 50  0001 C CNN
F 3 "" H 1800 2200 50  0001 C CNN
	1    1800 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 2150 1800 2200
Wire Wire Line
	1850 2150 1800 2150
$Comp
L AmbaSat-1_Satellite-Symbols:C C12
U 1 1 6191A62A
P 4300 5250
F 0 "C12" H 4350 5300 59  0000 L BNN
F 1 "10nF" H 4350 5100 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 4300 5250 50  0001 C CNN
F 3 "" H 4300 5250 50  0001 C CNN
	1    4300 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5050 4300 5050
Wire Wire Line
	4300 5050 4300 5100
Wire Wire Line
	4300 5400 4300 5450
$Comp
L AmbaSat-1_Satellite-Symbols:C C11
U 1 1 61939D4F
P 4700 4950
F 0 "C11" H 4750 5000 59  0000 L BNN
F 1 "100nF" H 4750 4800 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 4700 4950 50  0001 C CNN
F 3 "" H 4700 4950 50  0001 C CNN
	1    4700 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 4750 4700 4750
Wire Wire Line
	4700 4800 4700 4750
Connection ~ 4700 4750
Wire Wire Line
	4700 4750 5100 4750
Wire Wire Line
	4700 5100 4700 5450
Wire Wire Line
	4300 5450 4700 5450
Wire Wire Line
	4700 5450 5100 5450
Connection ~ 4700 5450
Wire Wire Line
	5100 5450 5100 5500
Connection ~ 5100 5450
$Comp
L AmbaSat-1_Satellite-Symbols:C C10
U 1 1 619763E3
P 2750 4950
F 0 "C10" H 2800 5000 59  0000 L BNN
F 1 "100nF" H 2800 4800 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 2750 4950 50  0001 C CNN
F 3 "" H 2750 4950 50  0001 C CNN
	1    2750 4950
	1    0    0    -1  
$EndComp
Connection ~ 3100 4750
Wire Wire Line
	2750 4800 2750 4750
Wire Wire Line
	2750 4750 3100 4750
Wire Wire Line
	3200 5150 3100 5150
Wire Wire Line
	3100 5150 3100 5400
Wire Wire Line
	3100 5400 2750 5400
Wire Wire Line
	2750 5100 2750 5400
Wire Wire Line
	2300 5100 2300 5400
Wire Wire Line
	2300 4750 2750 4750
Connection ~ 2300 4750
Connection ~ 2750 4750
Wire Wire Line
	2750 5400 2300 5400
Connection ~ 2750 5400
Connection ~ 2300 5400
Wire Wire Line
	2300 5400 2300 5450
$Comp
L AmbaSat-1_Satellite-Symbols:R R5
U 1 1 619A7C97
P 9200 5300
F 0 "R5" V 9300 5300 59  0000 C CNN
F 1 " 10k" V 9200 5300 39  0000 C CNN
F 2 "AmbaSat-1_Satellite:RESC160X80X55L25M" H 9200 5300 50  0001 C CNN
F 3 "" H 9200 5300 50  0001 C CNN
	1    9200 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8900 5300 9050 5300
Wire Wire Line
	9350 5300 9500 5300
Wire Wire Line
	9500 5300 9500 4900
Connection ~ 9500 4900
NoConn ~ 8900 5100
NoConn ~ 8900 5200
NoConn ~ 8900 5500
NoConn ~ 8900 5600
Text Notes 9100 5550 0    50   ~ 0
Poorly documented pin.\nDon't leave floating.
Wire Wire Line
	4450 1750 5250 1750
$Comp
L AmbaSat-1_Satellite-Symbols:R R2
U 1 1 8606AE8F
P 5250 1500
F 0 "R2" H 5050 1500 59  0000 L CNN
F 1 " 10k" V 5250 1500 39  0000 C CNN
F 2 "AmbaSat-1_Satellite:RESC160X80X55L25M" H 5250 1500 50  0001 C CNN
F 3 "" H 5250 1500 50  0001 C CNN
	1    5250 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 1300 5250 1350
Wire Wire Line
	5250 1650 5250 1750
Connection ~ 5250 1750
Wire Wire Line
	5250 1750 5800 1750
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR01
U 1 1 61A19F5B
P 6650 2700
F 0 "#PWR01" H 6650 2450 50  0001 C CNN
F 1 "GND" H 6655 2527 50  0000 C CNN
F 2 "" H 6650 2700 50  0001 C CNN
F 3 "" H 6650 2700 50  0001 C CNN
	1    6650 2700
	1    0    0    -1  
$EndComp
NoConn ~ 7200 2400
NoConn ~ 8200 1900
NoConn ~ 7200 2500
$Comp
L AmbaSat-1_Satellite-Symbols:LED D1
U 1 1 C78C3FBD
P 2050 2150
F 0 "D1" H 2050 2050 59  0000 C CNN
F 1 "LEDCHIP-LED0805" V 1850 2000 59  0001 L BNN
F 2 "AmbaSat-1_Satellite:LEDC200X125X85L40M" H 2050 2150 50  0001 C CNN
F 3 "" H 2050 2150 50  0001 C CNN
	1    2050 2150
	-1   0    0    1   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:R R1
U 1 1 B0CEE264
P 2450 2150
F 0 "R1" V 2600 2150 59  0000 C BNN
F 1 "1K" V 2450 2150 39  0000 C CNN
F 2 "AmbaSat-1_Satellite:RESC160X80X55L25M" H 2450 2150 50  0001 C CNN
F 3 "" H 2450 2150 50  0001 C CNN
	1    2450 2150
	0    -1   -1   0   
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:RFM95 U4
U 1 1 D235792D
P 7200 1900
F 0 "U4" H 7350 2150 59  0000 C CNN
F 1 "RFM95" H 7200 1900 50  0001 C CNN
F 2 "AmbaSat-1_Satellite:RFM95" H 7200 1900 50  0001 C CNN
F 3 "" H 7200 1900 50  0001 C CNN
	1    7200 1900
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:ATMEGA328P-AU U2
U 1 1 7A6AF24E
P 3750 2050
F 0 "U2" H 3300 3200 59  0000 C CNN
F 1 "ATMEGA328P-AU" H 3750 700 59  0000 C CNN
F 2 "AmbaSat-1_Satellite:QFP32P80_900X900X120L60X37M" H 3750 2050 50  0001 C CNN
F 3 "" H 3750 2050 50  0001 C CNN
	1    3750 2050
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C2
U 1 1 61A7E774
P 1500 1350
F 0 "C2" H 1550 1400 59  0000 L BNN
F 1 "10uF" H 1550 1200 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 1500 1350 50  0001 C CNN
F 3 "" H 1500 1350 50  0001 C CNN
	1    1500 1350
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C14
U 1 1 61A7E77E
P 1950 1350
F 0 "C14" H 2000 1400 59  0000 L BNN
F 1 "100nF" H 2000 1200 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 1950 1350 50  0001 C CNN
F 3 "" H 1950 1350 50  0001 C CNN
	1    1950 1350
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:C C3
U 1 1 61A869D3
P 2400 1350
F 0 "C3" H 2450 1400 59  0000 L BNN
F 1 "100nF" H 2450 1200 59  0000 L BNN
F 2 "AmbaSat-1_Satellite:CAPC160X80X90L40M" H 2400 1350 50  0001 C CNN
F 3 "" H 2400 1350 50  0001 C CNN
	1    2400 1350
	1    0    0    -1  
$EndComp
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR02
U 1 1 61A94F3F
P 1500 1600
F 0 "#PWR02" H 1500 1350 50  0001 C CNN
F 1 "GND" H 1505 1427 50  0000 C CNN
F 2 "" H 1500 1600 50  0001 C CNN
F 3 "" H 1500 1600 50  0001 C CNN
	1    1500 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1100 1500 1150
Wire Wire Line
	1500 1500 1500 1550
Wire Wire Line
	1500 1150 1950 1150
Connection ~ 1500 1150
Wire Wire Line
	1500 1150 1500 1200
Wire Wire Line
	2400 1200 2400 1150
Connection ~ 2400 1150
Wire Wire Line
	2400 1150 2950 1150
Wire Wire Line
	1950 1200 1950 1150
Connection ~ 1950 1150
Wire Wire Line
	1950 1150 2400 1150
Wire Wire Line
	2400 1500 2400 1550
Wire Wire Line
	2400 1550 1950 1550
Connection ~ 1500 1550
Wire Wire Line
	1500 1550 1500 1600
Wire Wire Line
	1950 1500 1950 1550
Connection ~ 1950 1550
Wire Wire Line
	1950 1550 1500 1550
Wire Wire Line
	3050 1250 2950 1250
Wire Wire Line
	2950 1250 2950 1150
Connection ~ 2950 1150
Wire Wire Line
	2950 1150 3050 1150
Wire Wire Line
	3050 1350 2950 1350
Wire Wire Line
	2950 1350 2950 1250
Connection ~ 2950 1250
NoConn ~ 3050 1550
NoConn ~ 3050 1650
NoConn ~ 3050 1850
NoConn ~ 3050 2050
NoConn ~ 4450 2650
NoConn ~ 4450 2550
NoConn ~ 4450 2450
NoConn ~ 4450 2350
NoConn ~ 4450 1450
NoConn ~ 4450 1250
Wire Wire Line
	8300 2700 8500 2700
Wire Wire Line
	8500 2750 8500 2700
Connection ~ 8500 2700
Wire Wire Line
	8500 2700 8550 2700
Wire Wire Line
	8200 2200 8700 2200
Wire Wire Line
	8200 2500 8800 2500
Wire Wire Line
	8800 2500 8800 2300
Wire Wire Line
	9150 2300 9150 2350
Wire Wire Line
	7200 1900 6650 1900
Wire Wire Line
	6650 1900 6650 2600
Wire Wire Line
	6650 2600 7200 2600
Wire Wire Line
	6650 2700 6650 2600
Connection ~ 6650 2600
Connection ~ 8950 3000
Wire Wire Line
	8950 3000 8950 3050
$Comp
L AmbaSat-1_Satellite-Symbols:GND #PWR0116
U 1 1 61978A12
P 8950 3050
F 0 "#PWR0116" H 8950 2800 50  0001 C CNN
F 1 "GND" H 8955 2877 50  0000 C CNN
F 2 "" H 8950 3050 50  0001 C CNN
F 3 "" H 8950 3050 50  0001 C CNN
	1    8950 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3000 8950 2900
Wire Wire Line
	8850 3000 8950 3000
Wire Wire Line
	8850 2900 8950 2900
$Comp
L AmbaSat-1_Satellite-Symbols:U.FL P1
U 1 1 C1A26F23
P 8750 2700
F 0 "P1" H 8500 2700 59  0000 L CNN
F 1 "U.FL" H 8750 2700 50  0001 C CNN
F 2 "AmbaSat-1_Satellite:U.FL" H 8750 2700 50  0001 C CNN
F 3 "" H 8750 2700 50  0001 C CNN
	1    8750 2700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8200 2600 8300 2600
Wire Wire Line
	8300 2600 8300 2700
Wire Wire Line
	9150 1850 9150 1900
Wire Wire Line
	8800 2300 9150 2300
Wire Wire Line
	8700 2200 8700 1900
Wire Wire Line
	8700 1900 9150 1900
NoConn ~ 8200 2300
NoConn ~ 8200 2400
$Comp
L AmbaSat-1_Satellite-Symbols:HEADER-1X1ROUND JP4
U 1 1 61951005
P 5250 1800
F 0 "JP4" V 5650 1800 59  0000 C CNN
F 1 "HEADER-1X1ROUND" H 5000 1600 59  0001 L BNN
F 2 "AmbaSat-1_Satellite:TESTPOINT_TH" H 5250 1800 50  0001 C CNN
F 3 "" H 5250 1800 50  0001 C CNN
	1    5250 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 1750 5250 1800
Wire Wire Line
	4600 6650 5350 6650
Text Notes 6300 7000 0    39   ~ 0
This version © 2021 and licensed under CERN-OHL-S v2\nAuthor: Jay Francis\nSource: https://github.com/robojay/AmbaSat-1/tree/kicad_conversion
$EndSCHEMATC

EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:L L1
U 1 1 6171A573
P 2700 1150
F 0 "L1" V 2890 1150 50  0000 C CNN
F 1 "L" V 2799 1150 50  0000 C CNN
F 2 "" H 2700 1150 50  0001 C CNN
F 3 "~" H 2700 1150 50  0001 C CNN
	1    2700 1150
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D2
U 1 1 6171AB80
P 4800 1100
F 0 "D2" V 4846 1021 50  0000 R CNN
F 1 "D" V 4755 1021 50  0000 R CNN
F 2 "" H 4800 1100 50  0001 C CNN
F 3 "~" H 4800 1100 50  0001 C CNN
	1    4800 1100
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 6171B199
P 4800 2600
F 0 "D3" V 4839 2483 50  0000 R CNN
F 1 "LED" V 4748 2483 50  0000 R CNN
F 2 "" H 4800 2600 50  0001 C CNN
F 3 "~" H 4800 2600 50  0001 C CNN
	1    4800 2600
	0    -1   -1   0   
$EndComp
$Comp
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 6171E136
P 1500 6200
F 0 "A1" H 1500 7381 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 1500 7290 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 1500 6200 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 1500 6200 50  0001 C CNN
	1    1500 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1150 2500 1150
Text Label 4800 2100 0    50   ~ 0
VCC_5V
$Comp
L Motor:Stepper_Motor_unipolar_6pin M1
U 1 1 6175475A
P 1350 3700
F 0 "M1" H 1538 3824 50  0000 L CNN
F 1 "Stepper_Motor_unipolar_6pin" V 1550 2650 50  0000 L CNN
F 2 "" H 1360 3690 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 1360 3690 50  0001 C CNN
	1    1350 3700
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C5
U 1 1 61759D00
P 4400 1850
F 0 "C5" H 4250 1950 50  0000 L CNN
F 1 "0.1uF" H 4150 1750 50  0000 L CNN
F 2 "" H 4400 1850 50  0001 C CNN
F 3 "~" H 4400 1850 50  0001 C CNN
	1    4400 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 6175A2CB
P 4400 1400
F 0 "C4" H 4300 1500 50  0000 L CNN
F 1 "0.33uF" H 4450 1500 50  0000 L CNN
F 2 "" H 4400 1400 50  0001 C CNN
F 3 "~" H 4400 1400 50  0001 C CNN
	1    4400 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1350 4800 1250
Wire Wire Line
	4800 950  4800 800 
Wire Wire Line
	4800 1250 4400 1250
Wire Wire Line
	4400 1250 4400 1300
Connection ~ 4800 1250
Wire Wire Line
	4800 1950 4800 2000
Wire Wire Line
	4400 1950 4400 2000
Wire Wire Line
	4400 2000 4800 2000
Connection ~ 4800 2000
Wire Wire Line
	4800 2000 4800 2150
Wire Wire Line
	4800 2750 4800 2800
$Comp
L Device:C_Small C20
U 1 1 6176F1CD
P 9500 1250
F 0 "C20" H 9592 1296 50  0000 L CNN
F 1 "100nF" H 9592 1205 50  0000 L CNN
F 2 "" H 9500 1250 50  0001 C CNN
F 3 "~" H 9500 1250 50  0001 C CNN
	1    9500 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C23
U 1 1 6176F628
P 9950 1250
F 0 "C23" H 10042 1296 50  0000 L CNN
F 1 "470nF" H 10042 1205 50  0000 L CNN
F 2 "" H 9950 1250 50  0001 C CNN
F 3 "~" H 9950 1250 50  0001 C CNN
	1    9950 1250
	1    0    0    -1  
$EndComp
$Comp
L BTN8962TA:BTN8962TA U2
U 1 1 617716A0
P 8150 1250
F 0 "U2" H 8494 1296 50  0000 L CNN
F 1 "BTN8962TA" H 7800 1650 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-263-7_TabPin4" H 8150 1250 50  0001 C CNN
F 3 "" H 8150 1250 50  0001 C CNN
	1    8150 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 61773DE9
P 7500 1000
F 0 "R8" V 7350 1000 50  0000 C CNN
F 1 "10k" V 7450 1000 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7500 1000 50  0001 C CNN
F 3 "~" H 7500 1000 50  0001 C CNN
	1    7500 1000
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 61775AA2
P 7450 1750
F 0 "R7" H 7391 1704 50  0000 R CNN
F 1 "0.51k" H 7391 1795 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7450 1750 50  0001 C CNN
F 3 "~" H 7450 1750 50  0001 C CNN
	1    7450 1750
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R4
U 1 1 61775F17
P 6950 1650
F 0 "R4" H 6891 1604 50  0000 R CNN
F 1 "1k" H 6891 1695 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 6950 1650 50  0001 C CNN
F 3 "~" H 6950 1650 50  0001 C CNN
	1    6950 1650
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C8
U 1 1 6177624F
P 7200 1650
F 0 "C8" H 7292 1696 50  0000 L CNN
F 1 "1nF" H 7292 1605 50  0000 L CNN
F 2 "" H 7200 1650 50  0001 C CNN
F 3 "~" H 7200 1650 50  0001 C CNN
	1    7200 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C11
U 1 1 6177655D
P 7800 1750
F 0 "C11" H 7892 1796 50  0000 L CNN
F 1 "100nF" H 7892 1705 50  0000 L CNN
F 2 "" H 7800 1750 50  0001 C CNN
F 3 "~" H 7800 1750 50  0001 C CNN
	1    7800 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R9
U 1 1 6177DFDF
P 7500 1200
F 0 "R9" V 7350 1200 50  0000 C CNN
F 1 "10k" V 7450 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7500 1200 50  0001 C CNN
F 3 "~" H 7500 1200 50  0001 C CNN
	1    7500 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	8250 850  8250 800 
Wire Wire Line
	8250 800  8550 800 
Wire Wire Line
	9500 800  9500 1150
Wire Wire Line
	8250 1700 8250 1650
Wire Wire Line
	9500 1350 9500 1700
Wire Wire Line
	9500 800  9950 800 
Wire Wire Line
	9950 800  9950 1150
Wire Wire Line
	9950 1700 9500 1700
Wire Wire Line
	9950 1350 9950 1700
Connection ~ 9500 800 
Connection ~ 9500 1700
$Comp
L Device:C_Small C14
U 1 1 617712C9
P 8550 1050
F 0 "C14" H 8642 1096 50  0000 L CNN
F 1 "220nF" H 8642 1005 50  0000 L CNN
F 2 "" H 8550 1050 50  0001 C CNN
F 3 "~" H 8550 1050 50  0001 C CNN
	1    8550 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 950  8550 800 
Wire Wire Line
	8550 1150 8550 1250
Wire Wire Line
	8550 1250 8450 1250
Wire Wire Line
	7850 1050 7600 1000
Text Label 7400 1050 2    50   ~ 0
L1_INH
Text Label 7400 1200 2    50   ~ 0
L1_IN
Wire Wire Line
	7850 1450 7800 1450
Wire Wire Line
	7800 1450 7800 1650
Wire Wire Line
	7800 1850 7800 2000
Wire Wire Line
	7800 1450 7450 1450
Wire Wire Line
	7450 1450 7450 1650
Wire Wire Line
	7450 2000 7800 2000
Wire Wire Line
	7450 1850 7450 2000
Connection ~ 7800 1450
Wire Wire Line
	7850 1350 7200 1350
Wire Wire Line
	7200 1350 7200 1550
Wire Wire Line
	7200 1350 6950 1350
Wire Wire Line
	6950 1350 6950 1550
Connection ~ 7200 1350
Text Label 6950 1350 2    50   ~ 0
L1_IS
Wire Wire Line
	6950 1750 6950 2000
Wire Wire Line
	6950 2000 7200 2000
Connection ~ 7450 2000
Wire Wire Line
	7200 1750 7200 2000
Connection ~ 7200 2000
Wire Wire Line
	7200 2000 7450 2000
$Comp
L power:GND #PWR0101
U 1 1 617A523C
P 4800 2800
F 0 "#PWR0101" H 4800 2550 50  0001 C CNN
F 1 "GND" H 4805 2627 50  0000 C CNN
F 2 "" H 4800 2800 50  0001 C CNN
F 3 "" H 4800 2800 50  0001 C CNN
	1    4800 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1900 2500 1900
Connection ~ 2500 1900
$Comp
L Device:C_Small C15
U 1 1 617D945E
P 8550 1450
F 0 "C15" H 8642 1496 50  0000 L CNN
F 1 "220nF" H 8642 1405 50  0000 L CNN
F 2 "" H 8550 1450 50  0001 C CNN
F 3 "~" H 8550 1450 50  0001 C CNN
	1    8550 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 1350 8550 1250
Connection ~ 8550 1250
Wire Wire Line
	8550 1550 8550 1700
Wire Wire Line
	8250 1700 8550 1700
Connection ~ 8550 1700
Wire Wire Line
	8550 1700 9500 1700
Wire Wire Line
	8550 800  9500 800 
Connection ~ 8550 800 
Text Label 8850 1250 0    50   ~ 0
L1_Motor
Wire Wire Line
	8550 1250 8850 1250
$Comp
L Device:Rotary_Encoder SW1
U 1 1 617E4674
P 5050 6700
F 0 "SW1" V 5039 6470 50  0000 R CNN
F 1 "Rotary_Encoder" V 4948 6470 50  0000 R CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E-Switch_Vertical_H20mm" H 4900 6860 50  0001 C CNN
F 3 "~" H 5050 6960 50  0001 C CNN
	1    5050 6700
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C7
U 1 1 617E556E
P 6050 7050
F 0 "C7" V 5821 7050 50  0000 C CNN
F 1 "10nF" H 5950 7150 50  0000 C CNN
F 2 "" H 6050 7050 50  0001 C CNN
F 3 "~" H 6050 7050 50  0001 C CNN
	1    6050 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 617E6428
P 5400 7350
F 0 "#PWR0102" H 5400 7100 50  0001 C CNN
F 1 "GND" H 5405 7177 50  0000 C CNN
F 2 "" H 5400 7350 50  0001 C CNN
F 3 "" H 5400 7350 50  0001 C CNN
	1    5400 7350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 617392D7
P 2500 1450
F 0 "C1" H 2592 1496 50  0000 L CNN
F 1 "C_Small" H 2592 1405 50  0000 L CNN
F 2 "" H 2500 1450 50  0001 C CNN
F 3 "~" H 2500 1450 50  0001 C CNN
	1    2500 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 61739E9D
P 3350 1450
F 0 "C3" H 3442 1496 50  0000 L CNN
F 1 "2200uF" H 3442 1405 50  0000 L CNN
F 2 "" H 3350 1450 50  0001 C CNN
F 3 "~" H 3350 1450 50  0001 C CNN
	1    3350 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 1150 2500 1350
Wire Wire Line
	2500 1550 2500 1900
Wire Wire Line
	2950 1550 2950 1900
Wire Wire Line
	3350 1150 3350 1350
Wire Wire Line
	3350 1900 2950 1900
Wire Wire Line
	3350 1550 3350 1900
Connection ~ 2950 1900
$Comp
L power:GND #PWR0103
U 1 1 6171FD2F
P 850 2000
F 0 "#PWR0103" H 850 1750 50  0001 C CNN
F 1 "GND" H 855 1827 50  0000 C CNN
F 2 "" H 850 2000 50  0001 C CNN
F 3 "" H 850 2000 50  0001 C CNN
	1    850  2000
	1    0    0    -1  
$EndComp
Connection ~ 850  1150
$Comp
L power:VCC #PWR0104
U 1 1 6171F94B
P 850 1150
F 0 "#PWR0104" H 850 1000 50  0001 C CNN
F 1 "VCC" H 867 1323 50  0000 C CNN
F 2 "" H 850 1150 50  0001 C CNN
F 3 "" H 850 1150 50  0001 C CNN
	1    850  1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 1200 7850 1150
$Comp
L power:GND #PWR0105
U 1 1 6179416D
P 7450 2050
F 0 "#PWR0105" H 7450 1800 50  0001 C CNN
F 1 "GND" H 7455 1877 50  0000 C CNN
F 2 "" H 7450 2050 50  0001 C CNN
F 3 "" H 7450 2050 50  0001 C CNN
	1    7450 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2050 7450 2000
Wire Wire Line
	850  1150 850  1900
$Comp
L Transistor_FET:IRF4905 Q1
U 1 1 6179A1BC
P 1600 1250
F 0 "Q1" V 1942 1250 50  0000 C CNN
F 1 "IRF4905" V 1851 1250 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-2_TabPin1" H 1800 1175 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irf4905.pdf?fileId=5546d462533600a4015355e32165197c" H 1600 1250 50  0001 L CNN
	1    1600 1250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R1
U 1 1 6179B4C9
P 1600 1700
F 0 "R1" H 1659 1746 50  0000 L CNN
F 1 "1k" H 1659 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 1600 1700 50  0001 C CNN
F 3 "~" H 1600 1700 50  0001 C CNN
	1    1600 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R3
U 1 1 6179B76C
P 4800 2250
F 0 "R3" H 4859 2296 50  0000 L CNN
F 1 "2k" H 4859 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 4800 2250 50  0001 C CNN
F 3 "~" H 4800 2250 50  0001 C CNN
	1    4800 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2450 4800 2350
$Comp
L Device:R_Small R2
U 1 1 6179F1AA
P 1900 1300
F 0 "R2" H 1959 1346 50  0000 L CNN
F 1 "1M" H 1959 1255 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 1900 1300 50  0001 C CNN
F 3 "~" H 1900 1300 50  0001 C CNN
	1    1900 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener_Small D1
U 1 1 617A012F
P 2200 1300
F 0 "D1" V 2154 1368 50  0000 L CNN
F 1 "12V" V 2245 1368 50  0000 L CNN
F 2 "" V 2200 1300 50  0001 C CNN
F 3 "~" V 2200 1300 50  0001 C CNN
	1    2200 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	1600 1450 1600 1500
Wire Wire Line
	1600 1800 1600 1900
Wire Wire Line
	2200 1150 2200 1200
Wire Wire Line
	2200 1500 1900 1500
Wire Wire Line
	2200 1400 2200 1500
Connection ~ 1600 1500
Wire Wire Line
	1600 1500 1600 1600
Wire Wire Line
	1900 1150 1900 1200
Wire Wire Line
	1900 1400 1900 1500
Wire Wire Line
	1900 1150 2200 1150
Connection ~ 1900 1500
Wire Wire Line
	1900 1500 1600 1500
Wire Wire Line
	850  1900 1600 1900
Connection ~ 850  1900
Wire Wire Line
	850  1900 850  2000
Connection ~ 1600 1900
Wire Wire Line
	700  1900 850  1900
Wire Notes Line
	1350 2050 1350 850 
Wire Notes Line
	3100 850  3100 2050
Wire Wire Line
	2850 1150 2950 1150
$Comp
L Device:C_Small C2
U 1 1 61739B9C
P 2950 1450
F 0 "C2" H 3042 1496 50  0000 L CNN
F 1 "C_Small" H 3042 1405 50  0000 L CNN
F 2 "" H 2950 1450 50  0001 C CNN
F 3 "~" H 2950 1450 50  0001 C CNN
	1    2950 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1350 2950 1150
Connection ~ 2950 1150
Wire Wire Line
	2950 1150 3350 1150
Wire Wire Line
	1600 1900 2500 1900
Wire Wire Line
	850  1150 1400 1150
Wire Notes Line
	1350 850  3100 850 
Wire Notes Line
	1350 2050 3100 2050
Wire Wire Line
	1800 1150 1900 1150
Connection ~ 1900 1150
Wire Wire Line
	2200 1150 2500 1150
Connection ~ 2200 1150
Connection ~ 2500 1150
Wire Wire Line
	6200 6800 5600 6800
Wire Wire Line
	5350 6600 6050 6600
$Comp
L Device:C_Small C6
U 1 1 6180DD2F
P 5600 7050
F 0 "C6" V 5371 7050 50  0000 C CNN
F 1 "10nF" H 5500 7150 50  0000 C CNN
F 2 "" H 5600 7050 50  0001 C CNN
F 3 "~" H 5600 7050 50  0001 C CNN
	1    5600 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 6700 5400 6700
Wire Wire Line
	5400 6700 5400 7250
Wire Wire Line
	5600 6800 5600 6950
Wire Wire Line
	5600 7250 5400 7250
Wire Wire Line
	5600 7150 5600 7250
Connection ~ 5600 6800
Wire Wire Line
	5600 6800 5350 6800
Connection ~ 5400 7250
Wire Wire Line
	5400 7250 5400 7350
Wire Wire Line
	6050 6600 6050 6950
Wire Wire Line
	6050 7250 5600 7250
Wire Wire Line
	6050 7150 6050 7250
Connection ~ 6050 6600
Wire Wire Line
	6050 6600 6200 6600
Connection ~ 5600 7250
Text Label 6200 6600 0    50   ~ 0
Pull_Up_Ard_B
Text Label 6200 6800 0    50   ~ 0
Pull_Up_Ard_A
Text Label 9950 800  0    50   ~ 0
VCC_Filtered
Text Label 4800 800  2    50   ~ 0
VCC_Filtered
Text Label 3350 1150 0    50   ~ 0
VCC_Filtered
Text Notes 1250 650  0    50   ~ 0
C 0.1uF - 0.01 uF\nFerrite Bead Impedance 50 to 100 ohm @ range of interest: 0.5 uH - 5 uH
$Comp
L Device:C_Small C21
U 1 1 61786B81
P 9550 2950
F 0 "C21" H 9642 2996 50  0000 L CNN
F 1 "100nF" H 9642 2905 50  0000 L CNN
F 2 "" H 9550 2950 50  0001 C CNN
F 3 "~" H 9550 2950 50  0001 C CNN
	1    9550 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C24
U 1 1 61786B87
P 10000 2950
F 0 "C24" H 10092 2996 50  0000 L CNN
F 1 "470nF" H 10092 2905 50  0000 L CNN
F 2 "" H 10000 2950 50  0001 C CNN
F 3 "~" H 10000 2950 50  0001 C CNN
	1    10000 2950
	1    0    0    -1  
$EndComp
$Comp
L BTN8962TA:BTN8962TA U3
U 1 1 61786B8D
P 8200 2950
F 0 "U3" H 8544 2996 50  0000 L CNN
F 1 "BTN8962TA" H 7850 3350 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-263-7_TabPin4" H 8200 2950 50  0001 C CNN
F 3 "" H 8200 2950 50  0001 C CNN
	1    8200 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R11
U 1 1 61786B93
P 7550 2700
F 0 "R11" V 7400 2700 50  0000 C CNN
F 1 "10k" V 7500 2700 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7550 2700 50  0001 C CNN
F 3 "~" H 7550 2700 50  0001 C CNN
	1    7550 2700
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R10
U 1 1 61786B99
P 7500 3450
F 0 "R10" H 7441 3404 50  0000 R CNN
F 1 "0.51k" H 7441 3495 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7500 3450 50  0001 C CNN
F 3 "~" H 7500 3450 50  0001 C CNN
	1    7500 3450
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R5
U 1 1 61786B9F
P 7000 3350
F 0 "R5" H 6941 3304 50  0000 R CNN
F 1 "1k" H 6941 3395 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7000 3350 50  0001 C CNN
F 3 "~" H 7000 3350 50  0001 C CNN
	1    7000 3350
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C9
U 1 1 61786BA5
P 7250 3350
F 0 "C9" H 7342 3396 50  0000 L CNN
F 1 "1nF" H 7342 3305 50  0000 L CNN
F 2 "" H 7250 3350 50  0001 C CNN
F 3 "~" H 7250 3350 50  0001 C CNN
	1    7250 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C12
U 1 1 61786BAB
P 7850 3450
F 0 "C12" H 7942 3496 50  0000 L CNN
F 1 "100nF" H 7942 3405 50  0000 L CNN
F 2 "" H 7850 3450 50  0001 C CNN
F 3 "~" H 7850 3450 50  0001 C CNN
	1    7850 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R12
U 1 1 61786BB1
P 7550 2900
F 0 "R12" V 7400 2900 50  0000 C CNN
F 1 "10k" V 7500 2900 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7550 2900 50  0001 C CNN
F 3 "~" H 7550 2900 50  0001 C CNN
	1    7550 2900
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 2550 8300 2500
Wire Wire Line
	8300 2500 8600 2500
Wire Wire Line
	9550 2500 9550 2850
Wire Wire Line
	8300 3400 8300 3350
Wire Wire Line
	9550 3050 9550 3400
Wire Wire Line
	9550 2500 10000 2500
Wire Wire Line
	10000 2500 10000 2850
Wire Wire Line
	10000 3400 9550 3400
Wire Wire Line
	10000 3050 10000 3400
Connection ~ 9550 2500
Connection ~ 9550 3400
$Comp
L Device:C_Small C16
U 1 1 61786BC2
P 8600 2750
F 0 "C16" H 8692 2796 50  0000 L CNN
F 1 "220nF" H 8692 2705 50  0000 L CNN
F 2 "" H 8600 2750 50  0001 C CNN
F 3 "~" H 8600 2750 50  0001 C CNN
	1    8600 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 2650 8600 2500
Wire Wire Line
	8600 2850 8600 2950
Wire Wire Line
	8600 2950 8500 2950
Wire Wire Line
	7900 2750 7650 2700
Text Label 7450 2750 2    50   ~ 0
L2_INH
Text Label 7450 2900 2    50   ~ 0
L2_IN
Wire Wire Line
	7900 3150 7850 3150
Wire Wire Line
	7850 3150 7850 3350
Wire Wire Line
	7850 3550 7850 3700
Wire Wire Line
	7850 3150 7500 3150
Wire Wire Line
	7500 3150 7500 3350
Wire Wire Line
	7500 3700 7850 3700
Wire Wire Line
	7500 3550 7500 3700
Connection ~ 7850 3150
Wire Wire Line
	7900 3050 7250 3050
Wire Wire Line
	7250 3050 7250 3250
Wire Wire Line
	7250 3050 7000 3050
Wire Wire Line
	7000 3050 7000 3250
Connection ~ 7250 3050
Text Label 7000 3050 2    50   ~ 0
L2_IS
Wire Wire Line
	7000 3450 7000 3700
Wire Wire Line
	7000 3700 7250 3700
Connection ~ 7500 3700
Wire Wire Line
	7250 3450 7250 3700
Connection ~ 7250 3700
Wire Wire Line
	7250 3700 7500 3700
$Comp
L Device:C_Small C17
U 1 1 61786BE2
P 8600 3150
F 0 "C17" H 8692 3196 50  0000 L CNN
F 1 "220nF" H 8692 3105 50  0000 L CNN
F 2 "" H 8600 3150 50  0001 C CNN
F 3 "~" H 8600 3150 50  0001 C CNN
	1    8600 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3050 8600 2950
Connection ~ 8600 2950
Wire Wire Line
	8600 3250 8600 3400
Wire Wire Line
	8300 3400 8600 3400
Connection ~ 8600 3400
Wire Wire Line
	8600 3400 9550 3400
Wire Wire Line
	8600 2500 9550 2500
Connection ~ 8600 2500
Text Label 8900 2950 0    50   ~ 0
L2_Motor
Wire Wire Line
	8600 2950 8900 2950
Wire Wire Line
	7650 2900 7900 2850
$Comp
L power:GND #PWR0106
U 1 1 61786BF3
P 7500 3750
F 0 "#PWR0106" H 7500 3500 50  0001 C CNN
F 1 "GND" H 7505 3577 50  0000 C CNN
F 2 "" H 7500 3750 50  0001 C CNN
F 3 "" H 7500 3750 50  0001 C CNN
	1    7500 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 3750 7500 3700
Text Label 10000 2500 0    50   ~ 0
VCC_Filtered
$Comp
L Device:C_Small C22
U 1 1 617A500C
P 9600 4800
F 0 "C22" H 9692 4846 50  0000 L CNN
F 1 "100nF" H 9692 4755 50  0000 L CNN
F 2 "" H 9600 4800 50  0001 C CNN
F 3 "~" H 9600 4800 50  0001 C CNN
	1    9600 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C25
U 1 1 617A5012
P 10050 4800
F 0 "C25" H 10142 4846 50  0000 L CNN
F 1 "470nF" H 10142 4755 50  0000 L CNN
F 2 "" H 10050 4800 50  0001 C CNN
F 3 "~" H 10050 4800 50  0001 C CNN
	1    10050 4800
	1    0    0    -1  
$EndComp
$Comp
L BTN8962TA:BTN8962TA U4
U 1 1 617A5018
P 8250 4800
F 0 "U4" H 8594 4846 50  0000 L CNN
F 1 "BTN8962TA" H 7900 5200 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-263-7_TabPin4" H 8250 4800 50  0001 C CNN
F 3 "" H 8250 4800 50  0001 C CNN
	1    8250 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R14
U 1 1 617A501E
P 7600 4550
F 0 "R14" V 7450 4550 50  0000 C CNN
F 1 "10k" V 7550 4550 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7600 4550 50  0001 C CNN
F 3 "~" H 7600 4550 50  0001 C CNN
	1    7600 4550
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R13
U 1 1 617A5024
P 7550 5300
F 0 "R13" H 7491 5254 50  0000 R CNN
F 1 "0.51k" H 7491 5345 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7550 5300 50  0001 C CNN
F 3 "~" H 7550 5300 50  0001 C CNN
	1    7550 5300
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R6
U 1 1 617A502A
P 7050 5200
F 0 "R6" H 6991 5154 50  0000 R CNN
F 1 "1k" H 6991 5245 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7050 5200 50  0001 C CNN
F 3 "~" H 7050 5200 50  0001 C CNN
	1    7050 5200
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C10
U 1 1 617A5030
P 7300 5200
F 0 "C10" H 7392 5246 50  0000 L CNN
F 1 "1nF" H 7392 5155 50  0000 L CNN
F 2 "" H 7300 5200 50  0001 C CNN
F 3 "~" H 7300 5200 50  0001 C CNN
	1    7300 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C13
U 1 1 617A5036
P 7900 5300
F 0 "C13" H 7992 5346 50  0000 L CNN
F 1 "100nF" H 7992 5255 50  0000 L CNN
F 2 "" H 7900 5300 50  0001 C CNN
F 3 "~" H 7900 5300 50  0001 C CNN
	1    7900 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R15
U 1 1 617A503C
P 7600 4750
F 0 "R15" V 7450 4750 50  0000 C CNN
F 1 "10k" V 7550 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" H 7600 4750 50  0001 C CNN
F 3 "~" H 7600 4750 50  0001 C CNN
	1    7600 4750
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 4400 8350 4350
Wire Wire Line
	8350 4350 8650 4350
Wire Wire Line
	9600 4350 9600 4700
Wire Wire Line
	8350 5250 8350 5200
Wire Wire Line
	9600 4900 9600 5250
Wire Wire Line
	9600 4350 10050 4350
Wire Wire Line
	10050 4350 10050 4700
Wire Wire Line
	10050 5250 9600 5250
Wire Wire Line
	10050 4900 10050 5250
Connection ~ 9600 4350
Connection ~ 9600 5250
$Comp
L Device:C_Small C18
U 1 1 617A504D
P 8650 4600
F 0 "C18" H 8742 4646 50  0000 L CNN
F 1 "220nF" H 8742 4555 50  0000 L CNN
F 2 "" H 8650 4600 50  0001 C CNN
F 3 "~" H 8650 4600 50  0001 C CNN
	1    8650 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4500 8650 4350
Wire Wire Line
	8650 4700 8650 4800
Wire Wire Line
	8650 4800 8550 4800
Wire Wire Line
	7950 4600 7700 4550
Text Label 7500 4600 2    50   ~ 0
L3_INH
Text Label 7500 4750 2    50   ~ 0
L3_IN
Wire Wire Line
	7950 5000 7900 5000
Wire Wire Line
	7900 5000 7900 5200
Wire Wire Line
	7900 5400 7900 5550
Wire Wire Line
	7900 5000 7550 5000
Wire Wire Line
	7550 5000 7550 5200
Wire Wire Line
	7550 5550 7900 5550
Wire Wire Line
	7550 5400 7550 5550
Connection ~ 7900 5000
Wire Wire Line
	7950 4900 7300 4900
Wire Wire Line
	7300 4900 7300 5100
Wire Wire Line
	7300 4900 7050 4900
Wire Wire Line
	7050 4900 7050 5100
Connection ~ 7300 4900
Text Label 7050 4900 2    50   ~ 0
L3_IS
Wire Wire Line
	7050 5300 7050 5550
Wire Wire Line
	7050 5550 7300 5550
Connection ~ 7550 5550
Wire Wire Line
	7300 5300 7300 5550
Connection ~ 7300 5550
Wire Wire Line
	7300 5550 7550 5550
$Comp
L Device:C_Small C19
U 1 1 617A506D
P 8650 5000
F 0 "C19" H 8742 5046 50  0000 L CNN
F 1 "220nF" H 8742 4955 50  0000 L CNN
F 2 "" H 8650 5000 50  0001 C CNN
F 3 "~" H 8650 5000 50  0001 C CNN
	1    8650 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4900 8650 4800
Connection ~ 8650 4800
Wire Wire Line
	8650 5100 8650 5250
Wire Wire Line
	8350 5250 8650 5250
Connection ~ 8650 5250
Wire Wire Line
	8650 5250 9600 5250
Wire Wire Line
	8650 4350 9600 4350
Connection ~ 8650 4350
Text Label 8950 4800 0    50   ~ 0
L3_Motor
Wire Wire Line
	8650 4800 8950 4800
Wire Wire Line
	7700 4750 7950 4700
$Comp
L power:GND #PWR0107
U 1 1 617A507E
P 7550 5600
F 0 "#PWR0107" H 7550 5350 50  0001 C CNN
F 1 "GND" H 7555 5427 50  0000 C CNN
F 2 "" H 7550 5600 50  0001 C CNN
F 3 "" H 7550 5600 50  0001 C CNN
	1    7550 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 5600 7550 5550
Text Label 10050 4350 0    50   ~ 0
VCC_Filtered
Text Label 1050 3600 2    50   ~ 0
L1_Motor
Text Label 1050 3700 2    50   ~ 0
L2_Motor
Text Label 1050 3800 2    50   ~ 0
L3_Motor
Text Label 1250 4000 3    50   ~ 0
L1_Sense
Text Label 1450 4000 3    50   ~ 0
L3_Sense
Text Label 1350 4000 3    50   ~ 0
L2_Sense
$Comp
L Regulator_Linear:LF15_TO220 U1
U 1 1 6171B659
P 4800 1650
F 0 "U1" V 4754 1754 50  0000 L CNN
F 1 "LF15_TO220" V 4845 1754 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TO-263-2_TabPin1" H 4800 1875 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/c4/0e/7e/2a/be/bc/4c/bd/CD00000546.pdf/files/CD00000546.pdf/jcr:content/translations/en.CD00000546.pdf" H 4800 1600 50  0001 C CNN
	1    4800 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 1500 4400 1650
Wire Wire Line
	4500 1650 4400 1650
Connection ~ 4400 1650
Wire Wire Line
	4400 1650 4400 1750
$EndSCHEMATC

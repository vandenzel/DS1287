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
L Maxim:DS12885T+ U1
U 1 1 5DD0A7D3
P 3200 3600
F 0 "U1" H 3200 5265 50  0000 C CNN
F 1 "DS12885T+" H 3200 5174 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2200 4400 50  0001 C CNN
F 3 "" H 2200 4400 50  0001 C CNN
	1    3200 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x12_Male J2
U 1 1 5DD0A997
P 8200 2700
F 0 "J2" H 8200 1850 50  0000 L CNN
F 1 "Conn_01x12_Male" H 8200 1950 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 8200 2700 50  0001 C CNN
F 3 "~" H 8200 2700 50  0001 C CNN
	1    8200 2700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7000 2100 7300 2100
Wire Wire Line
	7300 2400 7000 2400
Wire Wire Line
	7300 2500 7000 2500
Wire Wire Line
	7300 2600 7000 2600
Wire Wire Line
	7300 2700 7000 2700
Wire Wire Line
	7300 2800 7000 2800
Wire Wire Line
	7300 2900 7000 2900
Wire Wire Line
	7300 3000 7000 3000
Wire Wire Line
	7300 3100 7000 3100
Wire Wire Line
	7300 3200 7000 3200
Wire Wire Line
	8000 2100 7700 2100
Wire Wire Line
	8000 2200 7700 2200
Wire Wire Line
	8000 2600 7700 2600
Wire Wire Line
	8000 2800 7700 2800
Wire Wire Line
	8000 3000 7700 3000
Wire Wire Line
	8000 3100 7700 3100
Wire Wire Line
	8000 3200 7700 3200
Text Notes 6700 2100 0    50   ~ 0
1
Text Notes 6650 3200 0    50   ~ 0
12
Text Notes 8250 3200 0    50   ~ 0
13
Text Notes 8250 2100 0    50   ~ 0
24
Text Label 7300 2100 2    50   ~ 0
MOT
Text Label 7300 2400 2    50   ~ 0
AD0
Text Label 7300 2500 2    50   ~ 0
AD1
Text Label 7300 2600 2    50   ~ 0
AD2
Text Label 7300 2700 2    50   ~ 0
AD3
Text Label 7300 2800 2    50   ~ 0
AD4
Text Label 7300 2900 2    50   ~ 0
AD5
Text Label 7300 3000 2    50   ~ 0
AD6
Text Label 7300 3100 2    50   ~ 0
AD7
Text Label 7300 3200 2    50   ~ 0
GND
Text Label 7700 3200 0    50   ~ 0
~CS
Text Label 7700 3100 0    50   ~ 0
AS
Text Label 7700 3000 0    50   ~ 0
R~W
Wire Wire Line
	8000 2700 7700 2700
Text Label 7700 2800 0    50   ~ 0
DS
Text Label 7700 2700 0    50   ~ 0
~RESET
Text Label 7700 2600 0    50   ~ 0
~IRQ
Text Label 7700 2200 0    50   ~ 0
SQW
Text Label 7700 2100 0    50   ~ 0
VCC
Wire Wire Line
	3700 2600 4000 2600
Wire Wire Line
	3700 3100 4000 3100
Wire Wire Line
	2400 2200 2700 2200
Wire Wire Line
	2400 2300 2700 2300
Wire Wire Line
	2400 2500 2700 2500
Wire Wire Line
	2400 2600 2700 2600
Wire Wire Line
	2400 2700 2700 2700
Wire Wire Line
	2400 2800 2700 2800
Wire Wire Line
	2400 2900 2700 2900
Wire Wire Line
	2400 3000 2700 3000
Wire Wire Line
	2400 3100 2700 3100
Wire Wire Line
	2400 3200 2700 3200
Wire Wire Line
	2400 3300 2700 3300
Wire Wire Line
	2400 3400 2700 3400
Wire Wire Line
	2400 3500 2700 3500
Wire Wire Line
	2400 3600 2700 3600
Wire Wire Line
	2400 3800 2700 3800
Text Label 2400 2200 0    50   ~ 0
~RESET
Text Label 2400 2300 0    50   ~ 0
~IRQ
Text Label 2400 2500 0    50   ~ 0
AD0
Text Label 2400 2600 0    50   ~ 0
AD1
Text Label 2400 2700 0    50   ~ 0
AD2
Text Label 2400 2800 0    50   ~ 0
AD3
Text Label 2400 2900 0    50   ~ 0
AD4
Text Label 2400 3000 0    50   ~ 0
AD5
Text Label 2400 3100 0    50   ~ 0
AD6
Text Label 2400 3200 0    50   ~ 0
AD7
Text Label 2400 3300 0    50   ~ 0
AS
Text Label 2400 3400 0    50   ~ 0
DS
Text Label 2400 3500 0    50   ~ 0
~CS
Text Label 2400 3600 0    50   ~ 0
R~W
Text Label 2400 3800 0    50   ~ 0
SQW
Text Label 4000 2200 2    50   ~ 0
VCC
Text Label 4000 2400 2    50   ~ 0
VBAT
Text Label 4000 2600 2    50   ~ 0
MOT
Text Label 4000 2800 2    50   ~ 0
X1
Text Label 4000 2900 2    50   ~ 0
X2
Text Label 4000 3100 2    50   ~ 0
~RCLR
Text Label 4000 3700 2    50   ~ 0
GND
Text Label 4000 3800 2    50   ~ 0
GND
$Comp
L power:VCC #PWR0101
U 1 1 5DD12B20
P 4100 2100
F 0 "#PWR0101" H 4100 1950 50  0001 C CNN
F 1 "VCC" H 4117 2273 50  0000 C CNN
F 2 "" H 4100 2100 50  0001 C CNN
F 3 "" H 4100 2100 50  0001 C CNN
	1    4100 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5DD12B5D
P 4100 3900
F 0 "#PWR0102" H 4100 3650 50  0001 C CNN
F 1 "GND" H 4105 3727 50  0000 C CNN
F 2 "" H 4100 3900 50  0001 C CNN
F 3 "" H 4100 3900 50  0001 C CNN
	1    4100 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3700 4100 3800
Wire Wire Line
	3700 3700 4100 3700
Wire Wire Line
	3700 3800 4100 3800
Connection ~ 4100 3800
Wire Wire Line
	4100 3800 4100 3900
Wire Wire Line
	4100 2200 4100 2100
Wire Wire Line
	3700 2200 4100 2200
NoConn ~ 7000 2200
NoConn ~ 7000 2300
NoConn ~ 8000 2300
NoConn ~ 8000 2400
NoConn ~ 8000 2500
NoConn ~ 8000 2900
$Comp
L Device:Crystal Y1
U 1 1 5DD1BE95
P 4300 2850
F 0 "Y1" V 4346 2719 50  0000 R CNN
F 1 "Crystal" V 4255 2719 50  0000 R CNN
F 2 "Crystal:Crystal_C26-LF_D2.1mm_L6.5mm_Horizontal" H 4300 2850 50  0001 C CNN
F 3 "~" H 4300 2850 50  0001 C CNN
	1    4300 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4300 2700 4300 2600
Wire Wire Line
	4300 2600 4100 2600
Wire Wire Line
	4100 2600 4100 2800
Wire Wire Line
	3700 2800 4100 2800
Wire Wire Line
	4100 2900 4100 3100
Wire Wire Line
	4100 3100 4300 3100
Wire Wire Line
	4300 3100 4300 3000
Wire Wire Line
	3700 2900 4100 2900
NoConn ~ 4000 3100
$Comp
L Device:Battery_Cell BT1
U 1 1 5DD20572
P 4900 2700
F 0 "BT1" H 5018 2796 50  0000 L CNN
F 1 "CR1220" H 5018 2705 50  0000 L CNN
F 2 "Battery:BatteryHolder_Keystone_500" V 4900 2760 50  0001 C CNN
F 3 "~" V 4900 2760 50  0001 C CNN
	1    4900 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5DD229DE
P 4900 3900
F 0 "#PWR01" H 4900 3650 50  0001 C CNN
F 1 "GND" H 4905 3727 50  0000 C CNN
F 2 "" H 4900 3900 50  0001 C CNN
F 3 "" H 4900 3900 50  0001 C CNN
	1    4900 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3900 4900 2800
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5DD23B48
P 10700 900
F 0 "#FLG0101" H 10700 975 50  0001 C CNN
F 1 "PWR_FLAG" H 10700 1074 50  0000 C CNN
F 2 "" H 10700 900 50  0001 C CNN
F 3 "~" H 10700 900 50  0001 C CNN
	1    10700 900 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5DD23B64
P 10100 1000
F 0 "#FLG0102" H 10100 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 10100 1173 50  0000 C CNN
F 2 "" H 10100 1000 50  0001 C CNN
F 3 "~" H 10100 1000 50  0001 C CNN
	1    10100 1000
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 5DD25DC5
P 10100 900
F 0 "#PWR0103" H 10100 750 50  0001 C CNN
F 1 "VCC" H 10117 1073 50  0000 C CNN
F 2 "" H 10100 900 50  0001 C CNN
F 3 "" H 10100 900 50  0001 C CNN
	1    10100 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5DD25DDA
P 10700 1000
F 0 "#PWR0104" H 10700 750 50  0001 C CNN
F 1 "GND" H 10705 827 50  0000 C CNN
F 2 "" H 10700 1000 50  0001 C CNN
F 3 "" H 10700 1000 50  0001 C CNN
	1    10700 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 900  10100 1000
Wire Wire Line
	10700 900  10700 1000
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5DD2815B
P 9500 1000
F 0 "#FLG0103" H 9500 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 9500 1173 50  0000 C CNN
F 2 "" H 9500 1000 50  0001 C CNN
F 3 "~" H 9500 1000 50  0001 C CNN
	1    9500 1000
	-1   0    0    1   
$EndComp
Wire Wire Line
	9500 900  9500 1000
$Comp
L power:+BATT #PWR0105
U 1 1 5DD29341
P 4900 2100
F 0 "#PWR0105" H 4900 1950 50  0001 C CNN
F 1 "+BATT" H 4915 2273 50  0000 C CNN
F 2 "" H 4900 2100 50  0001 C CNN
F 3 "" H 4900 2100 50  0001 C CNN
	1    4900 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0106
U 1 1 5DD29363
P 9500 900
F 0 "#PWR0106" H 9500 750 50  0001 C CNN
F 1 "+BATT" H 9515 1073 50  0000 C CNN
F 2 "" H 9500 900 50  0001 C CNN
F 3 "" H 9500 900 50  0001 C CNN
	1    9500 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR02
U 1 1 5EFBA685
P 9500 2100
F 0 "#PWR02" H 9500 1950 50  0001 C CNN
F 1 "VCC" H 9517 2273 50  0000 C CNN
F 2 "" H 9500 2100 50  0001 C CNN
F 3 "" H 9500 2100 50  0001 C CNN
	1    9500 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR03
U 1 1 5EFBA69A
P 10100 2100
F 0 "#PWR03" H 10100 1950 50  0001 C CNN
F 1 "+BATT" H 10115 2273 50  0000 C CNN
F 2 "" H 10100 2100 50  0001 C CNN
F 3 "" H 10100 2100 50  0001 C CNN
	1    10100 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2100 4900 2400
Wire Wire Line
	3700 2400 4900 2400
Connection ~ 4900 2400
Wire Wire Line
	4900 2400 4900 2500
$Comp
L power:GND #PWR04
U 1 1 5EFBC92C
P 9500 2600
F 0 "#PWR04" H 9500 2350 50  0001 C CNN
F 1 "GND" H 9505 2427 50  0000 C CNN
F 2 "" H 9500 2600 50  0001 C CNN
F 3 "" H 9500 2600 50  0001 C CNN
	1    9500 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5EFBC941
P 10100 2600
F 0 "#PWR05" H 10100 2350 50  0001 C CNN
F 1 "GND" H 10105 2427 50  0000 C CNN
F 2 "" H 10100 2600 50  0001 C CNN
F 3 "" H 10100 2600 50  0001 C CNN
	1    10100 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5EFBC95F
P 9500 2350
F 0 "C1" H 9615 2396 50  0000 L CNN
F 1 "100n" H 9615 2305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9538 2200 50  0001 C CNN
F 3 "~" H 9500 2350 50  0001 C CNN
	1    9500 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5EFBC9BF
P 10100 2350
F 0 "C2" H 10215 2396 50  0000 L CNN
F 1 "100n" H 10215 2305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10138 2200 50  0001 C CNN
F 3 "~" H 10100 2350 50  0001 C CNN
	1    10100 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2100 9500 2200
Wire Wire Line
	10100 2100 10100 2200
Wire Wire Line
	10100 2500 10100 2600
Wire Wire Line
	9500 2500 9500 2600
$Comp
L Connector:Conn_01x12_Male J1
U 1 1 5DD0AA7D
P 6800 2600
F 0 "J1" H 6800 3350 50  0000 L CNN
F 1 "Conn_01x12_Male" H 6800 3250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 6800 2600 50  0001 C CNN
F 3 "~" H 6800 2600 50  0001 C CNN
	1    6800 2600
	1    0    0    -1  
$EndComp
$EndSCHEMATC

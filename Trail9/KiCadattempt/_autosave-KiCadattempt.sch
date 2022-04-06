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
L Connector_Generic:Conn_01x01 J3
U 1 1 61798423
P 1750 1450
F 0 "J3" V 1714 1362 50  0000 R CNN
F 1 "Neg" V 1623 1362 50  0000 R CNN
F 2 "" H 1750 1450 50  0001 C CNN
F 3 "~" H 1750 1450 50  0001 C CNN
	1    1750 1450
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 6179BBBA
P 2300 1450
F 0 "J3" V 2264 1362 50  0000 R CNN
F 1 "Solenoid Valve-Pos" V 2173 1362 50  0000 R CNN
F 2 "" H 2300 1450 50  0001 C CNN
F 3 "~" H 2300 1450 50  0001 C CNN
	1    2300 1450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D1
U 1 1 61796EDA
P 2050 1650
F 0 "D1" H 2050 1867 50  0000 C CNN
F 1 "D" H 2050 1776 50  0000 C CNN
F 2 "" H 2050 1650 50  0001 C CNN
F 3 "~" H 2050 1650 50  0001 C CNN
	1    2050 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1650 2200 1650
Wire Wire Line
	1900 1650 1750 1650
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 617ACF7A
P 2000 2250
F 0 "J1" V 1872 2062 50  0000 R CNN
F 1 "Relay connection" V 1963 2062 50  0000 R CNN
F 2 "" H 2000 2250 50  0001 C CNN
F 3 "~" H 2000 2250 50  0001 C CNN
	1    2000 2250
	0    -1   1    0   
$EndComp
Text Label 1950 2400 0    50   ~ 0
NO
Text Label 1950 2500 0    50   ~ 0
12vDC
Wire Wire Line
	2100 2050 2300 2050
Wire Wire Line
	2300 2050 2300 1650
Connection ~ 2300 1650
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 617B0EA1
P 800 1800
F 0 "J2" H 880 1792 50  0000 L CNN
F 1 "12DC" H 880 1701 50  0000 L CNN
F 2 "" H 800 1800 50  0001 C CNN
F 3 "~" H 800 1800 50  0001 C CNN
	1    800  1800
	-1   0    0    -1  
$EndComp
Text Label 850  2000 0    50   ~ 0
Pos
Text Label 850  1700 0    50   ~ 0
Neg
Wire Wire Line
	1000 1800 1300 1800
Wire Wire Line
	1750 1800 1750 1650
Connection ~ 1750 1650
Wire Wire Line
	1000 1900 1150 1900
Wire Wire Line
	2000 1900 2000 2050
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 617B9447
P 1950 2600
F 0 "J6" V 1914 2412 50  0000 R CNN
F 1 "Relay_Input" V 1823 2412 50  0000 R CNN
F 2 "" H 1950 2600 50  0001 C CNN
F 3 "~" H 1950 2600 50  0001 C CNN
	1    1950 2600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 617C2AB5
P 2200 2950
F 0 "#PWR?" H 2200 2700 50  0001 C CNN
F 1 "GND" H 2205 2777 50  0000 C CNN
F 2 "" H 2200 2950 50  0001 C CNN
F 3 "" H 2200 2950 50  0001 C CNN
	1    2200 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 2800 2050 2950
Wire Wire Line
	2050 2950 2200 2950
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 617D7072
P 3800 600
F 0 "J4" V 3764 512 50  0000 R CNN
F 1 "Neg" V 3673 512 50  0000 R CNN
F 2 "" H 3800 600 50  0001 C CNN
F 3 "~" H 3800 600 50  0001 C CNN
	1    3800 600 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 617D7078
P 4350 600
F 0 "J4" V 4314 512 50  0000 R CNN
F 1 "Solenoid Valve-Pos" V 4223 512 50  0000 R CNN
F 2 "" H 4350 600 50  0001 C CNN
F 3 "~" H 4350 600 50  0001 C CNN
	1    4350 600 
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D2
U 1 1 617D707E
P 4100 800
F 0 "D2" H 4100 1017 50  0000 C CNN
F 1 "D" H 4100 926 50  0000 C CNN
F 2 "" H 4100 800 50  0001 C CNN
F 3 "~" H 4100 800 50  0001 C CNN
	1    4100 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 800  4250 800 
Wire Wire Line
	3950 800  3800 800 
$Comp
L Connector_Generic:Conn_01x03 J5
U 1 1 617D7086
P 4050 1400
F 0 "J5" V 3922 1212 50  0000 R CNN
F 1 "Relay connection" V 4013 1212 50  0000 R CNN
F 2 "" H 4050 1400 50  0001 C CNN
F 3 "~" H 4050 1400 50  0001 C CNN
	1    4050 1400
	0    -1   1    0   
$EndComp
Text Label 4000 1550 0    50   ~ 0
NO
Text Label 4000 1650 0    50   ~ 0
12vDC
Wire Wire Line
	4150 1200 4350 1200
Wire Wire Line
	4350 1200 4350 800 
Connection ~ 4350 800 
Text Label 2900 1150 0    50   ~ 0
Pos
Text Label 2900 850  0    50   ~ 0
Neg
Wire Wire Line
	3800 950  3800 800 
Connection ~ 3800 800 
Wire Wire Line
	4050 1050 4050 1200
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 617D709E
P 4000 1750
F 0 "J10" V 3964 1562 50  0000 R CNN
F 1 "Relay_Input" V 3873 1562 50  0000 R CNN
F 2 "" H 4000 1750 50  0001 C CNN
F 3 "~" H 4000 1750 50  0001 C CNN
	1    4000 1750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 617D70A4
P 4250 2100
F 0 "#PWR?" H 4250 1850 50  0001 C CNN
F 1 "GND" H 4255 1927 50  0000 C CNN
F 2 "" H 4250 2100 50  0001 C CNN
F 3 "" H 4250 2100 50  0001 C CNN
	1    4250 2100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 1950 4100 2100
Wire Wire Line
	4100 2100 4250 2100
Wire Wire Line
	1300 950  1300 1800
Wire Wire Line
	1300 950  3800 950 
Connection ~ 1300 1800
Wire Wire Line
	1300 1800 1750 1800
Wire Wire Line
	1150 1050 1150 1900
Wire Wire Line
	1150 1050 4050 1050
Connection ~ 1150 1900
Wire Wire Line
	1150 1900 2000 1900
NoConn ~ 3950 1200
NoConn ~ 1900 2050
Wire Notes Line
	1800 2100 1800 2850
Wire Notes Line
	1800 2850 2300 2850
Wire Notes Line
	2300 2850 2300 2100
Wire Notes Line
	2300 2100 1800 2100
Wire Notes Line
	3850 1250 3850 2000
Wire Notes Line
	3850 2000 4350 2000
Wire Notes Line
	4350 2000 4350 1250
Wire Notes Line
	4350 1250 3850 1250
Wire Notes Line
	1700 1400 2350 1400
Wire Notes Line
	2350 1400 2350 1500
Wire Notes Line
	2350 1500 1700 1500
Wire Notes Line
	3750 550  4400 550 
Wire Notes Line
	4400 550  4400 650 
Wire Notes Line
	4400 650  3750 650 
$Comp
L Connector_Generic:Conn_01x09 J6
U 1 1 618066F6
P 9750 1150
F 0 "J6" H 9700 1750 50  0000 L CNN
F 1 "MAX31856A" H 9700 1650 50  0000 L CNN
F 2 "" H 9750 1150 50  0001 C CNN
F 3 "~" H 9750 1150 50  0001 C CNN
	1    9750 1150
	1    0    0    -1  
$EndComp
Text Label 9850 800  0    50   ~ 0
VIN
Text Label 9850 900  0    50   ~ 0
3VO
Text Label 9850 1000 0    50   ~ 0
GND
Text Label 9850 1100 0    50   ~ 0
SCK
Text Label 9850 1200 0    50   ~ 0
SDO
Text Label 9850 1300 0    50   ~ 0
SDI
Text Label 9850 1400 0    50   ~ 0
CS
Text Label 9850 1500 0    50   ~ 0
FLT
Text Label 9850 1600 0    50   ~ 0
DRDY
Wire Notes Line
	9700 700  10250 700 
Wire Notes Line
	10250 700  10250 1600
Wire Notes Line
	10250 1600 9750 1600
NoConn ~ 9550 850 
NoConn ~ 9550 1450
NoConn ~ 9550 1550
Text Label 10650 900  0    50   ~ 0
Thermocouple
Wire Notes Line
	10500 700  10500 950 
Wire Notes Line
	10500 950  11200 950 
Wire Notes Line
	11200 950  11200 700 
Wire Notes Line
	11200 700  10500 700 
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 6181D70A
P 10550 800
F 0 "J6" H 10500 1050 50  0000 L CNN
F 1 "TC" H 10500 950 50  0000 L CNN
F 2 "" H 10550 800 50  0001 C CNN
F 3 "~" H 10550 800 50  0001 C CNN
	1    10550 800 
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 61822E68
P 10150 800
F 0 "J6" H 10550 1050 50  0000 C CNN
F 1 "TC" H 10450 1050 50  0000 C CNN
F 2 "" H 10150 800 50  0001 C CNN
F 3 "~" H 10150 800 50  0001 C CNN
	1    10150 800 
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J7
U 1 1 61831935
P 9750 2300
F 0 "J7" H 9700 2900 50  0000 L CNN
F 1 "MAX31856A" H 9700 2800 50  0000 L CNN
F 2 "" H 9750 2300 50  0001 C CNN
F 3 "~" H 9750 2300 50  0001 C CNN
	1    9750 2300
	1    0    0    -1  
$EndComp
Text Label 9850 1950 0    50   ~ 0
VIN
Text Label 9850 2050 0    50   ~ 0
3VO
Text Label 9850 2150 0    50   ~ 0
GND
Text Label 9850 2250 0    50   ~ 0
SCK
Text Label 9850 2350 0    50   ~ 0
SDO
Text Label 9850 2450 0    50   ~ 0
SDI
Text Label 9850 2550 0    50   ~ 0
CS
Text Label 9850 2650 0    50   ~ 0
FLT
Text Label 9850 2750 0    50   ~ 0
DRDY
Wire Notes Line
	9700 1850 10250 1850
Wire Notes Line
	10250 1850 10250 2750
Wire Notes Line
	10250 2750 9750 2750
NoConn ~ 9550 2000
NoConn ~ 9550 2600
NoConn ~ 9550 2700
Text Label 10650 2050 0    50   ~ 0
Thermocouple
Wire Notes Line
	10500 1850 10500 2100
Wire Notes Line
	10500 2100 11200 2100
Wire Notes Line
	11200 2100 11200 1850
Wire Notes Line
	11200 1850 10500 1850
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 6183194F
P 10550 1950
F 0 "J7" H 10500 2200 50  0000 L CNN
F 1 "TC" H 10500 2100 50  0000 L CNN
F 2 "" H 10550 1950 50  0001 C CNN
F 3 "~" H 10550 1950 50  0001 C CNN
	1    10550 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 61831955
P 10150 1950
F 0 "J7" H 10550 2200 50  0000 C CNN
F 1 "TC" H 10450 2200 50  0000 C CNN
F 2 "" H 10150 1950 50  0001 C CNN
F 3 "~" H 10150 1950 50  0001 C CNN
	1    10150 1950
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J8
U 1 1 61834166
P 9750 3450
F 0 "J8" H 9700 4050 50  0000 L CNN
F 1 "MAX31856A" H 9700 3950 50  0000 L CNN
F 2 "" H 9750 3450 50  0001 C CNN
F 3 "~" H 9750 3450 50  0001 C CNN
	1    9750 3450
	1    0    0    -1  
$EndComp
Text Label 9850 3100 0    50   ~ 0
VIN
Text Label 9850 3200 0    50   ~ 0
3VO
Text Label 9850 3300 0    50   ~ 0
GND
Text Label 9850 3400 0    50   ~ 0
SCK
Text Label 9850 3500 0    50   ~ 0
SDO
Text Label 9850 3600 0    50   ~ 0
SDI
Text Label 9850 3700 0    50   ~ 0
CS
Text Label 9850 3800 0    50   ~ 0
FLT
Text Label 9850 3900 0    50   ~ 0
DRDY
Wire Notes Line
	9700 3000 10250 3000
Wire Notes Line
	10250 3000 10250 3900
Wire Notes Line
	10250 3900 9750 3900
NoConn ~ 9550 3150
NoConn ~ 9550 3750
NoConn ~ 9550 3850
Text Label 10650 3200 0    50   ~ 0
Thermocouple
Wire Notes Line
	10500 3000 10500 3250
Wire Notes Line
	10500 3250 11200 3250
Wire Notes Line
	11200 3250 11200 3000
Wire Notes Line
	11200 3000 10500 3000
$Comp
L Connector_Generic:Conn_01x02 J8
U 1 1 61834180
P 10550 3100
F 0 "J8" H 10500 3350 50  0000 L CNN
F 1 "TC" H 10500 3250 50  0000 L CNN
F 2 "" H 10550 3100 50  0001 C CNN
F 3 "~" H 10550 3100 50  0001 C CNN
	1    10550 3100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J8
U 1 1 61834186
P 10150 3100
F 0 "J8" H 10550 3350 50  0000 C CNN
F 1 "TC" H 10450 3350 50  0000 C CNN
F 2 "" H 10150 3100 50  0001 C CNN
F 3 "~" H 10150 3100 50  0001 C CNN
	1    10150 3100
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J9
U 1 1 618375B7
P 9750 4350
F 0 "J9" H 9700 4650 50  0000 L CNN
F 1 "BuzzerModule" H 9700 4550 50  0000 L CNN
F 2 "" H 9750 4350 50  0001 C CNN
F 3 "~" H 9750 4350 50  0001 C CNN
	1    9750 4350
	1    0    0    -1  
$EndComp
Wire Notes Line
	9700 4200 10450 4200
Wire Notes Line
	10450 4200 10450 4500
Wire Notes Line
	10450 4500 9750 4500
$Comp
L Connector_Generic:Conn_02x04_Row_Letter_First J10
U 1 1 618397B0
P 9750 5250
F 0 "J10" H 9800 5567 50  0000 C CNN
F 1 "ESP8266" H 9800 5476 50  0000 C CNN
F 2 "" H 9750 5250 50  0001 C CNN
F 3 "~" H 9750 5250 50  0001 C CNN
	1    9750 5250
	1    0    0    -1  
$EndComp
Wire Notes Line
	9750 5100 10450 5100
Wire Notes Line
	10450 5100 10450 5500
Wire Notes Line
	10450 5500 9750 5500
$Comp
L power:GND #PWR?
U 1 1 6183CF7F
P 10050 5000
F 0 "#PWR?" H 10050 4750 50  0001 C CNN
F 1 "GND" H 10055 4827 50  0000 C CNN
F 2 "" H 10050 5000 50  0001 C CNN
F 3 "" H 10050 5000 50  0001 C CNN
	1    10050 5000
	1    0    0    1   
$EndComp
Wire Wire Line
	10050 5150 10050 5000
$Comp
L Device:R R1
U 1 1 618403BA
P 9150 5250
F 0 "R1" V 9357 5250 50  0000 C CNN
F 1 "10k" V 9266 5250 50  0000 C CNN
F 2 "" V 9080 5250 50  0001 C CNN
F 3 "~" H 9150 5250 50  0001 C CNN
	1    9150 5250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9300 5250 9550 5250
$Comp
L Device:R R2
U 1 1 618454AD
P 10050 5750
F 0 "R2" H 10120 5796 50  0000 L CNN
F 1 "1k" H 10120 5705 50  0000 L CNN
F 2 "" V 9980 5750 50  0001 C CNN
F 3 "~" H 10050 5750 50  0001 C CNN
	1    10050 5750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 61848376
P 9650 5900
F 0 "R3" V 9857 5900 50  0000 C CNN
F 1 "2.2k" V 9766 5900 50  0000 C CNN
F 2 "" V 9580 5900 50  0001 C CNN
F 3 "~" H 9650 5900 50  0001 C CNN
	1    9650 5900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9800 5900 10050 5900
Wire Wire Line
	10050 5600 10050 5450
NoConn ~ 9550 5350
NoConn ~ 10050 5250
Wire Wire Line
	9550 5450 9000 5450
Wire Wire Line
	9000 5450 9000 5250
Wire Wire Line
	10050 5350 10200 5350
Wire Wire Line
	10200 5350 10200 5550
Wire Wire Line
	10200 5550 9000 5550
Wire Wire Line
	9000 5550 9000 5450
Connection ~ 9000 5450
Text Label 9850 4300 0    50   ~ 0
VCC
Text Label 9850 4400 0    50   ~ 0
EN
Text Label 9850 4500 0    50   ~ 0
GND
$Comp
L Connector_Generic:Conn_2Rows-37Pins J11
U 1 1 618551A2
P 6100 5700
F 0 "J11" V 6700 5750 50  0000 R CNN
F 1 "AM" V 6650 6100 50  0000 R CNN
F 2 "" H 6100 5700 50  0001 C CNN
F 3 "~" H 6100 5700 50  0001 C CNN
	1    6100 5700
	0    1    -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J11
U 1 1 6185DC53
P 7000 4750
F 0 "J11" H 7350 4950 50  0000 C CNN
F 1 "AM" H 7300 4850 50  0000 C CNN
F 2 "" H 7000 4750 50  0001 C CNN
F 3 "~" H 7000 4750 50  0001 C CNN
	1    7000 4750
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J11
U 1 1 61861467
P 5200 4700
F 0 "J11" H 5280 4692 50  0000 L CNN
F 1 "AM" H 5280 4601 50  0000 L CNN
F 2 "" H 5200 4700 50  0001 C CNN
F 3 "~" H 5200 4700 50  0001 C CNN
	1    5200 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J11
U 1 1 618643BF
P 5200 3850
F 0 "J11" H 5280 3842 50  0000 L CNN
F 1 "AM" H 5280 3751 50  0000 L CNN
F 2 "" H 5200 3850 50  0001 C CNN
F 3 "~" H 5200 3850 50  0001 C CNN
	1    5200 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J11
U 1 1 61865A95
P 5200 3000
F 0 "J11" H 5280 2992 50  0000 L CNN
F 1 "AM" H 5280 2901 50  0000 L CNN
F 2 "" H 5200 3000 50  0001 C CNN
F 3 "~" H 5200 3000 50  0001 C CNN
	1    5200 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J11
U 1 1 61866DBE
P 7000 3900
F 0 "J11" H 7250 4200 50  0000 C CNN
F 1 "AM" H 7300 4100 50  0000 C CNN
F 2 "" H 7000 3900 50  0001 C CNN
F 3 "~" H 7000 3900 50  0001 C CNN
	1    7000 3900
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x10 J11
U 1 1 61867990
P 7000 2950
F 0 "J11" H 7300 3050 50  0000 C CNN
F 1 "AM" H 7300 2950 50  0000 C CNN
F 2 "" H 7000 2950 50  0001 C CNN
F 3 "~" H 7000 2950 50  0001 C CNN
	1    7000 2950
	-1   0    0    -1  
$EndComp
Text Label 5850 3550 0    50   ~ 0
ArduinoMega
Wire Notes Line
	6250 2200 6250 2700
Wire Notes Line
	6250 2700 6650 2700
Wire Notes Line
	6650 2700 6650 2200
Wire Notes Line
	6650 2200 6250 2200
Wire Notes Line
	5600 2350 5600 2650
Wire Notes Line
	5600 2650 5800 2650
Wire Notes Line
	5800 2650 5800 2350
Wire Notes Line
	5800 2350 5600 2350
Wire Notes Line
	7050 5750 5150 5750
Wire Notes Line style solid
	5150 2500 7050 2500
Wire Notes Line style solid
	5150 2500 5150 5750
Wire Notes Line style solid
	7050 5750 7050 2500
$EndSCHEMATC

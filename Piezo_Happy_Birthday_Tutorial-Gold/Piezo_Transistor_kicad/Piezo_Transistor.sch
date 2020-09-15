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
L Transistor_BJT:2N3904 Q?
U 1 1 5F600043
P 7050 2500
F 0 "Q?" H 7240 2546 50  0000 L CNN
F 1 "2N3904" H 7240 2455 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7250 2425 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 7050 2500 50  0001 L CNN
	1    7050 2500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US 220ohm
U 1 1 5F600830
P 7050 2950
F 0 "220ohm" H 6982 2904 50  0000 R CNN
F 1 "R_Small_US" H 6982 2995 50  0000 R CNN
F 2 "" H 7050 2950 50  0001 C CNN
F 3 "~" H 7050 2950 50  0001 C CNN
	1    7050 2950
	-1   0    0    1   
$EndComp
$Comp
L Device:Speaker LS?
U 1 1 5F60586E
P 6350 2200
F 0 "LS?" H 6520 2196 50  0000 L CNN
F 1 "Speaker" H 6520 2105 50  0000 L CNN
F 2 "" H 6350 2000 50  0001 C CNN
F 3 "~" H 6340 2150 50  0001 C CNN
	1    6350 2200
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F6064FD
P 5750 3300
F 0 "#PWR?" H 5750 3150 50  0001 C CNN
F 1 "+5V" H 5765 3473 50  0000 C CNN
F 2 "" H 5750 3300 50  0001 C CNN
F 3 "" H 5750 3300 50  0001 C CNN
	1    5750 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F606C0F
P 6450 3700
F 0 "#PWR?" H 6450 3450 50  0001 C CNN
F 1 "GND" H 6455 3527 50  0000 C CNN
F 2 "" H 6450 3700 50  0001 C CNN
F 3 "" H 6450 3700 50  0001 C CNN
	1    6450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2850 5750 3300
Wire Wire Line
	6450 2400 6850 2400
Wire Wire Line
	7050 2700 7050 2850
$Comp
L MCU_Module:Arduino_UNO_R3 A?
U 1 1 5F6084F6
P 5850 4600
F 0 "A?" H 5850 5781 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 5850 5690 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 5850 4600 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 5850 4600 50  0001 C CNN
	1    5850 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4850 2400 4850 4400
Wire Wire Line
	4850 2400 6350 2400
Wire Wire Line
	6150 5100 6150 5300
Wire Wire Line
	6150 5300 7050 5300
Wire Wire Line
	7050 5300 7050 3050
$Comp
L power:GND #PWR?
U 1 1 5F613A3B
P 7800 3450
F 0 "#PWR?" H 7800 3200 50  0001 C CNN
F 1 "GND" H 7805 3277 50  0000 C CNN
F 2 "" H 7800 3450 50  0001 C CNN
F 3 "" H 7800 3450 50  0001 C CNN
	1    7800 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2400 7800 2400
Wire Wire Line
	7800 2400 7800 3450
$EndSCHEMATC

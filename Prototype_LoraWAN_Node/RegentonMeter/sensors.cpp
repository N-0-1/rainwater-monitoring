/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-Prototype-LoRaWAN-node.
  --------------------------------------------------------------------*/
/**
 * @file sensors.cpp
 * @brief Sensor implementation for the LoRaWAN node prototype.
 *
 * @details
 * Implements the sensor simulation functions used by the
 * prototype shield.
 *
 * The red push button emulates a flow meter by generating
 * pulse events. Two potentiometers emulate:
 * - Battery voltage
 * - Water tank level
 *
 * The converted values are stored in global variables and
 * used by the LoRaWAN application payload encoder.
 */

#include "sensors.h"


volatile uint8_t flow_mL = 0;  
volatile uint16_t level_cM = 0;  
volatile uint32_t battery_cV = 0;

void flowMeter()
{
	static int prevRed = RELEASED;
  int currRed = digitalRead(PIN_SWITCH_RED);
  // Count on the edge: Released -> Pressed
  if (currRed != prevRed) 
  {
    if (currRed == PRESSED) 
    {
      flow_mL++;  // exactly one increment per press
    }
    prevRed = currRed;
  }
}

uint16_t levelMeter()
{
  potWhiteValue = analogRead(PIN_POT_WHITE); //  the 10-bit ADC code (from 0 to 1023)
  float level_m = potWhiteValue * (1.5 / 1023.0); // 1.5 meter is the reference max level
  level_cM = level_m * 100; // centimeters
  return level_cM;
}

uint32_t batteryVoltage()
{
  potRedValue = analogRead(PIN_POT_RED); //  the 10-bit ADC code (from 0 to 1023)
  float voltage = potRedValue * (5.0 / 1023.0); // 5.0 is the reference voltage
  battery_cV = voltage * 100; // centivolts 
  return battery_cV;
}

void readSensors()
{
	flowMeter();
  levelMeter();
  batteryVoltage();
}

void debugSensors()
{
    debugSerial.println("-- LOOP");
    // print the value of POT_RED to the serial monitor (0...1023)
    String pRed = (String) potRedValue;
    debugSerial.println(pRed);
    // print the value of POT_WHITE to the serial monitor (0...1023)
    String pWhite = (String) potWhiteValue;
    debugSerial.println(pWhite);
    // print the number of pulses coutnted from switch_RED to the serial monitor (0...5)
    String sRed = (String) flow_mL;
    debugSerial.println(sRed);
}
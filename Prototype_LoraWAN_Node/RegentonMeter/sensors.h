/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-Prototype-LoRaWAN-node.
  --------------------------------------------------------------------*/
/**
 * @file sensors.h
 * @brief Sensor interface for the LoRaWAN node prototype.
 *
 * @details
 * This module provides access to the sensor values used by the
 * LoRaWAN prototype node. The prototype does not use actual flow,
 * level, or battery sensors. Instead, the custom shield contains
 * push buttons and potentiometers that emulate sensor behavior.
 *
 * Sensor mapping:
 * - Red push button -> Flow meter pulse generator
 * - White potentiometer -> Water level sensor
 * - Red potentiometer -> Battery voltage sensor
 *
 * The sensor values are converted into engineering units and stored
 * in global variables for use by the application and payload encoder.
 *
 * @author Nasser Abdulal
 *
 */

#ifndef SENSORS_H
#define SENSORS_H

#include <stdint.h> // uint8_t, uint16_t, and uint32_t type
//#include <hanNodeDevice.h>
#include "ThingsNetworkConfig.h"
#include "hanNodeDevice.h"


 
/**
 * @var flow_mL
 * @brief Simulated flow meter reading.
 *
 * @details
 * Stores the accumulated flow volume in millilitres.
 * Each press of the red push button generates one pulse
 * and increments the value by one unit.
 */
extern volatile uint8_t flow_mL;
/**
 * @var level_cM
 * @brief Simulated water level.
 *
 * @details
 * Water level calculated from the white potentiometer.
 * The value is expressed in centimetres and represents
 * a tank level ranging from 0 cm to 150 cm.
 */
extern volatile uint16_t level_cM;
/**
 * @var battery_cV
 * @brief Simulated battery voltage.
 *
 * @details
 * Battery voltage calculated from the red potentiometer.
 * The value is expressed in centivolts.
 */
extern volatile uint32_t battery_cV;

/**
 * @brief Simulates a flow meter pulse counter.
 *
 * @details
 * Reads the red push button and detects a rising edge
 * transition from RELEASED to PRESSED.
 *
 * Each detected edge increments the global flow counter,
 * emulating the pulse output of a water flow meter.
 */
void flowMeter();
/**
 * @brief Reads the simulated water level sensor.
 *
 * @details
 * Acquires the ADC value from the white potentiometer and
 * converts it to a water level measurement.
 *
 * Conversion range:
 * - ADC range: 0..1023
 * - Physical range: 0.0..1.5 m
 * - Returned range: 0..150 cm
 *
 * @return Water level in centimetres.
 */
uint16_t levelMeter();
/**
 * @brief Reads the simulated battery voltage sensor.
 *
 * @details
 * Acquires the ADC value from the red potentiometer and
 * converts it into a battery voltage measurement.
 *
 * Conversion range:
 * - ADC range: 0..1023
 * - Voltage range: 0.0..5.0 V
 * - Returned range: 0..500 cV
 *
 * @return Battery voltage in centivolts.
 */
uint32_t batteryVoltage();
/**
 * @brief Updates all sensor measurements.
 *
 * @details
 * Executes all sensor acquisition routines and updates:
 * - flow_mL
 * - level_cM
 * - battery_cV
 *
 * This function should be called periodically from the
 * main application loop.
 */
void readSensors();
/**
 * @brief Outputs sensor debug information.
 *
 * @details
 * Sends raw potentiometer values and the accumulated flow
 * counter to the serial debug interface.
 *
 * Intended for prototype verification and troubleshooting.
 */
void debugSensors();

#endif
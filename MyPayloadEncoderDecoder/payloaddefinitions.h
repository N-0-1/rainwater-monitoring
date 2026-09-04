/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/

/**
 * @file payloaddefinitions.h
 * @brief Shared payload definitions used by the encoder and decoder.
 * @author Remko Welling
 * @author Nasser Abdulal
 * @version 1.0.0
 *
 */

#ifndef PAYLOADDEFINITIONS_H
#define PAYLOADDEFINITIONS_H

#include <stdint.h>

/**
 * @brief Number of sensors in the payload.
 * @warning Must match the number of entries in the sensor definition table.
 */
constexpr uint8_t NUMBER_OF_SENSORS = 3;

/**
 * @brief Describes a sensor within the payload.
 */
struct SensorDefinition
{
    uint8_t size;       /**< Sensor size in bytes */
    const char* name;   /**< Human-readable sensor name */
};

/**
 * @brief Sensor identifiers.
 * @note Add or remove sensors
 */
enum SensorId
{
    FLOW_METER,      /**< Flow meter sensor */
    LEVEL_METER,     /**< Level meter sensor */
    BATTERY_VOLTAGE  /**< Battery voltage sensor */
};

/**
* @brief Sensor layout shared by encoder and decoder.
* @note Add or remove sensors
*/
extern const SensorDefinition sensors[NUMBER_OF_SENSORS];

#endif
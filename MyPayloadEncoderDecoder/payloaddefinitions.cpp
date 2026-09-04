#include "payloaddefinitions.h"

/**
 * @brief Sensor definitions shared by the encoder and decoder.
 *
 * @details
 * This table defines the payload structure used for encoding and
 * decoding sensor values.
 *
 * @warning
 * Any change to this table requires the TTN payload formatter
 * (decodeUplink JavaScript function) to be updated to match the
 * new payload layout.
 */
const SensorDefinition sensors[NUMBER_OF_SENSORS] =
    {
        {1, "Flow Meter"},
        {2, "Level Meter"},
        {4, "Battery Voltage"}
};
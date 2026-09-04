/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/
  
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
 * @note the cuurent choice for the size of sensor valuse 
 * based on the well to show the dynamic work of the payloadEncoder & payloadDecoder
 */
const SensorDefinition sensors[NUMBER_OF_SENSORS] =
{
    {1, "Flow Meter"},
    {2, "Level Meter"},
    {4, "Battery Voltage"}
};

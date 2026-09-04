/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/

/**
 * @file mypayloaddecoder.h
 * @brief Decodes LoRaWAN payloads from a rain-tank meter.
 * @author Remko Welling
 * @author Nasser Abdulal
 * @version 1.0.0
 */

#ifndef MY_PAYLOAD_DECODER_H
#define MY_PAYLOAD_DECODER_H

#include <stdint.h> // uint8_t, uint16_t, and uint32_t type
#include "payloaddefinitions.h" // NUMBER_OF_SENSORS, sensors[i]

/**
 * @brief Decodes sensor values from a LoRaWAN payload.
 * @details This class decodes sensor values from a payload for use in a LoRaWAN application.
 * The class is implemented using both .h and .cpp files where the setters and getters are
 * placed in the .h file.
 */
class myPayloadDecoder 
{
private:
    uint8_t *_buffer;           /**< buffer containing payload with sensor data*/
    uint8_t _bufferSize;        /**< Size of payload for housekeeping.*/

    uint32_t _sensorValues[NUMBER_OF_SENSORS];     /**< An array to store the measured values from sensors after decoding the payload*/
	
    /**
     * @brief Extract 32-bit unsigned value from payload at given position
     * @param buf Buffer containing payload
     * @param idx position in buffer at which value is starting
     * @return Extracted sensor value
	 */
    uint32_t extract_uint32(const uint8_t *buf, const unsigned char idx = 0);

    /**
     * @brief Extract 16-bit unsigned value from payload at given position
     * @param buf Buffer containing payload
     * @param idx position in buffer at which value is starting
     * @return Extracted sensor value
	 */
    uint16_t extract_uint16(const uint8_t *buf, const unsigned char idx = 0);
	
	/**
     * @brief Extract 8-bit unsigned value from payload at given position
     * @param buf Buffer containing payload
     * @param idx position in buffer at which value is starting
     * @return Extracted sensor value
	 */
	uint8_t extract_uint8 (const uint8_t *buf, const unsigned char idx = 0);

public:
    /**
     * @brief Constructs a payload decoder object.
     */
    myPayloadDecoder();
	/**
     * @brief Destroys the payload decoder object.
     */
    ~myPayloadDecoder();

    /** 
	 * @brief set pointer to buffer containing the payload
     * @param payload Pointer to the payload buffer.
	 */
    void setPayload(uint8_t *payload){_buffer = payload;}

    /**
	 * @brief set size of payload.
     * @param size Payload size in bytes.
	 */
    void setPayloadSize(uint8_t size){_bufferSize = size;}

    /**
	 * @brief decode payload and put individual values in member variables.
     * @pre payload and size shall be set.
	 * @post Decoded sensor values are stored in the internal sensor value array.
	 */
    void decodePayload();

    /**
     * @brief Returns the decoded value of the requested sensor.
     * @param sensor Sensor identifier.
	 * @pre decodePayload() has been called successfully. 
     * @return Current sensor value.
     */
    uint32_t getSensorValue(SensorId sensor) const;
};

#endif // MY_PAYLOAD_DECODER_H

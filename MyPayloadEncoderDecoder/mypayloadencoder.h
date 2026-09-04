/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/

/**
 * @file mypayloadencoder.h
 * @brief Encodes LoRaWAN payloads from a rain-tank meter.
 * @author Remko Welling
 * @author Nasser Abdulal
 * @version 1.0.0
 */

#ifndef MYPAYLOADENCODER_H
#define MYPAYLOADENCODER_H

#include <stdint.h> // uint8_t, uint16_t, and uint32_t type
#include "payloaddefinitions.h" // NUMBER_OF_SENSORS, sensors[i]

/**
 * @brief Total payload size in bytes.
 */
uint8_t calculatePayloadSize();

/** 
 * @brief Encodes sensor values into a LoRaWAN payload.
 * @details This class will encode variables for the LoRaWAN application into a single payload
 * The class is implemented using both .h and .cpp files.
 */
class myPayloadEncoder
{
private:  
    
	uint32_t _sensorValues[NUMBER_OF_SENSORS];

    uint8_t *_buffer;             /**< buffer containing payload with sensor data */
    uint8_t _bufferSize;         /**< Size of payload for housekeeping */

    /**
	 * @brief add uint32 to payload
     * @param idx_in start location in _buffer
     * @param value uint32_t value
     * @return First free location at which new data can be stored in _buffer
	 */
    unsigned char add_uint32 (unsigned char idx_in, uint32_t value);
	
    /**
	 * @brief add uint16 to payload
     * @param idx_in start location in _buffer
     * @param value uint16_t value
     * @return First free location at which new data can be stored in _buffer
	 */
    unsigned char add_uint16 (unsigned char idx_in, const uint16_t value);
	
	/**
     * @brief Add uint8 to payload.
     * @param idx_in Start location in _buffer.
     * @param value uint8_t value.
     * @return First free location in _buffer.
     */
    unsigned char add_uint8(unsigned char idx_in, const uint8_t value);
    
public:
    /**
     * @brief Constructs a payload encoder object.
     */
    myPayloadEncoder();
	/**
     * @brief Destroys the payload encoder object.
     */
    ~myPayloadEncoder();
	
	/**
     * @brief Sets the value of a sensor.
     * @param sensor Sensor identifier.
     * @param value Sensor value.
     */
   void setSensorValue(SensorId sensor, uint32_t value);

    /**
	 * @brief compose the payload
     * @pre All sensor values must be set.
	 * @post Buffer is populated with encoded data.
	 */
    void composePayload();

    /**
	 * @brief Return the payload size.
     * @details (this is a "Getter")
     * @return buffer size in bytes
	 */
    uint8_t getPayloadSize(){return _bufferSize;};

    /**
	 * @brief get payload.
     * @details (this is a "Getter")
     * @return Pointer to the encoded payload buffer.
	 */
    uint8_t *getPayload(){return _buffer;};
};

#endif // MYPAYLOADENCODER_H

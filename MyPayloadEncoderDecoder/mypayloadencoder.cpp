/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/

#include "mypayloadencoder.h"
#include <stdlib.h> // For malloc() and free()


uint8_t calculatePayloadSize()
{
    uint8_t size = 0;

    for (uint8_t i = 0; i < NUMBER_OF_SENSORS; ++i)
    {
        size += sensors[i].size;
    }

    return size;
}

/**
* @brief Constructor
* @details Initializes sensor values to zero and allocates memory for the payload buffer.
*/
myPayloadEncoder::myPayloadEncoder():
    _sensorValues{},
    _buffer{nullptr},
    _bufferSize{0}
{
    _buffer = reinterpret_cast<uint8_t *>(malloc(calculatePayloadSize()));
}


/**
* @brief Destructor
* @details Frees the allocated memory for the payload buffer.
*/
myPayloadEncoder::~myPayloadEncoder()
{
    free(_buffer);
}

void myPayloadEncoder::setSensorValue(SensorId sensor, uint32_t value)
{
	_sensorValues[sensor] = value;
}

/**
* @brief Compose the payload from sensor values.
* @details Adds flow meter, level meter, and battery voltage values to the buffer in sequence.
*/
void myPayloadEncoder::composePayload()
{
	if (_buffer == nullptr) { return; }

    _bufferSize = 0;              // Initialize index
	
    for(uint8_t i = 0; i < NUMBER_OF_SENSORS; i++)
     {
        switch(sensors[i].size)
         {
           case 1:
               _bufferSize = add_uint8(_bufferSize, static_cast<uint8_t>(_sensorValues[i]));
               break;

           case 2:
               _bufferSize = add_uint16(_bufferSize, static_cast<uint16_t>(_sensorValues[i]));
               break;

           case 4:
               _bufferSize = add_uint32(_bufferSize, _sensorValues[i]);
               break;
		  
		   default:
               return;
         }
     }
}

// UINT32
unsigned char myPayloadEncoder::add_uint32 (unsigned char idx_in, uint32_t value) {
    for (uint8_t i=0; i<4; i++) {
        _buffer[idx_in++] = (value >> 24) & 0xFF;  // msb
        value = value << 8;                        // shift-left
    }
    return (idx_in);
}

// UINT16
unsigned char myPayloadEncoder::add_uint16 (unsigned char idx_in, const uint16_t value) {
    _buffer[idx_in++] = (value >> 8) & 0xFF; // msb
    _buffer[idx_in++] = (value)      & 0xFF; // lsb
    return (idx_in);
}

// UINT8
unsigned char myPayloadEncoder::add_uint8 (unsigned char idx_in, const uint8_t value){
	_buffer[idx_in++] = value;
    return (idx_in);
}
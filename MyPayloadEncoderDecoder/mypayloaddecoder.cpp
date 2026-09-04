/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/
/**
 * @file mypayloaddecoder.cpp
 * @brief Implementation of the myPayloadDecoder class.
 */
#include "mypayloaddecoder.h"


myPayloadDecoder::myPayloadDecoder():
    _buffer{nullptr},
	_bufferSize(0),
	_sensorValues{}
  {
      
  }

myPayloadDecoder::~myPayloadDecoder()
{

}

void myPayloadDecoder::decodePayload()
{
	if (_buffer == nullptr) { return; }
	if (_bufferSize == 0) { return; }
	
	uint8_t offset = 0;
	
    for(uint8_t i = 0; i < NUMBER_OF_SENSORS; i++)
    { 
     if ((offset + sensors[i].size) > _bufferSize) { return; }
	
	 if (sensors[i].size == 1)
	  {
         _sensorValues[i] = extract_uint8(_buffer, offset);
		 offset += sensors[i].size;
	  }
	 else if (sensors[i].size == 2)
	  {
         _sensorValues[i] = extract_uint16(_buffer, offset);
		 offset += sensors[i].size;
	  }
	 else if(sensors[i].size == 4)
	  {
         _sensorValues[i] = extract_uint32(_buffer, offset);
		 offset += sensors[i].size;
	  }
	 else
	  {
         return;
	  }
    }
}

uint32_t myPayloadDecoder::getSensorValue(SensorId sensor) const
{
    if (sensor >= NUMBER_OF_SENSORS)
    {
        return 0;
    }

    return _sensorValues[sensor];
}

// UINT32
uint32_t myPayloadDecoder::extract_uint32(const uint8_t *buf, const unsigned char idx){
  uint32_t value {0};
  for (uint8_t i=0; i<4; i++) {
    value |= ((uint32_t)buf[idx+i] << (24-(i*8)));  // msb
  }
  return value;
}
 
// UINT16
uint16_t myPayloadDecoder::extract_uint16(const uint8_t *buf, const unsigned char idx){
  uint16_t value {0};
  value  = ((uint16_t)buf[idx] << 8);  // msb
  value |=  (uint16_t)buf[idx+1];      // lsb
  return value;
}

// UINT8
uint8_t myPayloadDecoder::extract_uint8 (const uint8_t *buf, const unsigned char idx){
  return (uint8_t)buf[idx];
}
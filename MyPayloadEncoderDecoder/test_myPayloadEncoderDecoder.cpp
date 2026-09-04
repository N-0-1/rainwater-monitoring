/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/
#include <iomanip>
#include <iostream>

#include "mypayloaddecoder.h"
#include "mypayloadencoder.h"
#include "test_myPayloadEncoderDecoder.h"

using namespace std;




void testGroup1()
{
    testTypicalValues();
    testBoundaryValues();
}


void testTypicalValues()
{
    myPayloadEncoder encoder;   // Encoder object
    myPayloadDecoder decoder;   // Decoder object

    uint8_t testFlowMeter = 100;       // Test variable containing value that shall be transferred
	uint16_t testLevelMeter = 633;      // Test variable containing value that shall be transferred
    uint32_t testBatteryVoltage = 582480;  // Test variable containing value that shall be transferred

    encoder.setSensorValue(FLOW_METER, testFlowMeter);             // Set variable in encoder object.
	encoder.setSensorValue(LEVEL_METER, testLevelMeter);           // Set variable in encoder object.
    encoder.setSensorValue(BATTERY_VOLTAGE, testBatteryVoltage);   // Set variable in encoder object.
    encoder.composePayload();

    uint8_t *payloadBuffer = encoder.getPayload();
    uint8_t payloadSize = encoder.getPayloadSize();

    std::cout << "Typical Values_payloadBuffer_addres: " << static_cast<void*>(payloadBuffer) << std::endl;
    std::cout << "Typical Values_payloadSize: " << static_cast<int>(payloadSize) << std::endl;
    std::cout << "The encoded payload in Hex via myPayloadencoder:" << std::endl;
    for (uint8_t i = 0; i < payloadSize; ++i)
    {
        std::cout << std::hex
                  << std::setw(2)
                  << std::setfill('0')
                  << static_cast<int>(payloadBuffer[i])
                  << " ";
    }
    std::cout << std::dec << std::endl;

    decoder.setPayload(payloadBuffer);
    decoder.setPayloadSize(payloadSize);
    decoder.decodePayload();

    uint8_t result1 = decoder.getSensorValue(FLOW_METER);        // Retrieve variable from decoder object and save in result1.
    uint16_t result2 = decoder.getSensorValue(LEVEL_METER);       // Retrieve variable from decoder object and save in result2.
    uint32_t result3 = decoder.getSensorValue(BATTERY_VOLTAGE);   // Retrieve variable from decoder object and save in result3.

    std::cout << "The decoded values from the payload via mypayloadecoder:" << std::endl;
    cout << "FlowMeter: " << static_cast<int>(result1) << endl;
    cout << "LevelMeter: " << result2 << endl;
    cout << "BatteryVoltage: " << result3 << endl;

    // evaluate test result of test 1
    cout << "Typical Value - Flow Meter: ";
    if(result1 == testFlowMeter)    {
        cout << "PASS" << endl;
    }else{
        cout << "FAIL" << endl;
    }

    // evaluate test result of test 2
    cout << "Typical Value - Level Meter: ";
    if(result2 == testLevelMeter){
        cout << "PASS" << endl;
    }else{
        cout << "FAIL" << endl;
    }
	
	// evaluate test result of test 3
    cout << "Typical Value - Battery Voltage: ";
    if(result3 == testBatteryVoltage){
        cout << "PASS" << endl;
    }else{
        cout << "FAIL" << endl;
    }
}


void testBoundaryValues()
{
    myPayloadEncoder encoder;   // Encoder object
    myPayloadDecoder decoder;   // Decoder object

    uint8_t testFlowMeter = 255;      // Test variable containing value that shall be transferred
    uint16_t testLevelMeter = 65535;         // Test variable containing value that shall be transferred
    uint32_t testBatteryVoltage = 4294967295; // Test variable containing value that shall be transferred

    encoder.setSensorValue(FLOW_METER, testFlowMeter);             // Set variable in encoder object.
	encoder.setSensorValue(LEVEL_METER, testLevelMeter);           // Set variable in encoder object.
    encoder.setSensorValue(BATTERY_VOLTAGE, testBatteryVoltage);   // Set variable in encoder object.
    encoder.composePayload();

    uint8_t *payloadBuffer = encoder.getPayload();
    uint8_t payloadSize = encoder.getPayloadSize();

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Boundary Values_payloadBuffer_addres: " << static_cast<void*>(payloadBuffer) << std::endl;
    std::cout << "Boundary Values_payloadSize: " << static_cast<int>(payloadSize) << std::endl;
    std::cout << "The encoded payload in Hex via myPayloadencoder:" << std::endl;
    for (uint8_t i = 0; i < payloadSize; ++i)
    {
        std::cout << std::hex
                  << std::setw(2)
                  << std::setfill('0')
                  << static_cast<int>(payloadBuffer[i])
                  << " ";
    }
    std::cout << std::dec << std::endl;

    decoder.setPayload(payloadBuffer);
    decoder.setPayloadSize(payloadSize);
    decoder.decodePayload();

    uint8_t result1 = decoder.getSensorValue(FLOW_METER);        // Retrieve variable from decoder object and save in result1.
    uint16_t result2 = decoder.getSensorValue(LEVEL_METER);       // Retrieve variable from decoder object and save in result2.
    uint32_t result3 = decoder.getSensorValue(BATTERY_VOLTAGE);   // Retrieve variable from decoder object and save in result3.

    std::cout << "The decoded values from the payload via mypayloadecoder:" << std::endl;
    cout << "FlowMeter: " << static_cast<int>(result1) << endl;
    cout << "LevelMeter: " << result2 << endl;
    cout << "BatteryVoltage: " << result3 << endl;

    // evaluate test result of test 1
    cout << "Boundary Value - Flow Meter: ";
    if(result1 == testFlowMeter){
        cout << "PASS" << endl;
    }else{
        cout << "FAIL" << endl;
    }

    // evaluate test result of test 2
    cout << "Boundary Value - Level Meter: ";
    if(result2 == testLevelMeter){
        cout << "PASS" << endl;
    }else{
        cout << "FAIL" << endl;
    }
	
	// evaluate test result of test 3
    cout << "Boundary Value - Battery Voltage: ";
    if(result3 == testBatteryVoltage){
        cout << "PASS" << endl;
    }else{
        cout << "FAIL" << endl;
    }
}

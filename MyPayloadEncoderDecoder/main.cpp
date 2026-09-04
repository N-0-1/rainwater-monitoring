/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/

/**
 * @file main.cpp
 * @brief Main application used to execute all unit tests.
 * @author Remko Welling
 * @author Nasser Abdulal
 * @version 1.0.0
 */

#include <iostream>
#include "test_myPayloadEncoderDecoder.h"

using namespace std;

int main()
{
    // Run unit tests
    cout << "Running Payload Encoder/Decoder Unit Tests..." << endl;
    testGroup1();
    cout << "All unit tests completed." << endl;
    
    return 0;
}

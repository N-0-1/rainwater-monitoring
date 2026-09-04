/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-payload-encoder-decoder.
  --------------------------------------------------------------------*/

/**
 * @file test_myPayloadEncoderDecoder.h
 * @brief unit tests for the myPayloadEncoder and myPayloadDecoder classes.
 * @author Remko Welling
 * @author Nasser Abdulal
 * @version 1.0.0
 *
 */

/**
 * @page UnitTests Unit Tests of Payload -Encoder -Decoder
 *
 * # Description
 *
 * The unit tests are divided into separate tests that are grouped
 * together to validate the payload encoder and decoder functionality.
 *
 * Each test creates its own encoder and decoder objects and follows
 * the process shown below:
 *
 * \verbatim
 *
 *                   +---------+                   +---------+
 *                   |         |                   |         |
 * input variable -->| encoder |-->  payload ----->| decoder |--> result
 *                   |         |                   |         |
 *                   +---------+                   +---------+
 *
 * \endverbatim
 */

#ifndef TEST_MYPAYLOADENCODERDECODER_H
#define TEST_MYPAYLOADENCODERDECODER_H

/**
 * @brief Executes all payload encoding and decoding tests.
 */
void testGroup1();

/**
 * @brief Verifies encoding and decoding using typical sensor values.
 */
void testTypicalValues();

/**
 * @brief Verifies encoding and decoding using boundary values.
 */
void testBoundaryValues();


#endif // TEST_MYPAYLOADENCODERDECODER_H

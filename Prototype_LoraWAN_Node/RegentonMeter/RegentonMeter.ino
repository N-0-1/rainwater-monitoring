/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-Prototype-LoRaWAN-node.
  --------------------------------------------------------------------*/

/**
 * @file RegentonMeter.ino
 * @brief Main application for the LoRaWAN rain barrel monitoring node.
 *
 * @details
 * This application implements a prototype IoT node for monitoring
 * domestic rainwater buffering systems.
 *
 * The node periodically acquires measurements from the Sensor Module,
 * packages the measurements into a LoRaWAN payload and transmits them
 * to The Things Network (TTN).
 *
 * The prototype uses simulated sensors mounted on a custom shield:
 * - Red push button      -> Flow meter
 * - White potentiometer -> Water level sensor
 * - Red potentiometer   -> Battery voltage sensor
 *
 * The application demonstrates the complete data path from sensor
 * acquisition to cloud communication using LoRaWAN technology.
 *
 * @author Nasser Abdulal
 */
 
#include "ThingsNetworkConfig.h"
#include "sensors.h"

/**
 * @var INTERVAL
 * @brief Periodic uplink interval.
 *
 * @details
 * Defines the maximum time between two consecutive
 * LoRaWAN uplink transmissions.
 *
 * Configured to 5 minutes.
 */
const unsigned long INTERVAL = 300000;  // 1000 * 60 * 5 = 1000 is 1 second in milliseconds * 60 second in 1 minute * 5 minutes.
/**
 * @var lastTime
 * @brief Timestamp of the previous uplink transmission.
 *
 * Used by the application scheduler to determine when
 * the next periodic transmission should be sent.
 */
unsigned long lastTime = 0;


/**
 * @brief Initializes the prototype node.
 *
 * @details
 * Performs all startup actions required before normal
 * operation begins:
 *
 * - Initializes hardware peripherals.
 * - Initializes the LoRaWAN transceiver.
 * - Joins The Things Network using OTAA.
 *
 * @post The node is ready for operation.
 */
void setup()
{
  initializeNodeHardware();
  joinNetwork_and_debug();
}

/**
 * @brief Main application execution loop.
 *
 * @details
 * Continuously executes the monitoring cycle:
 *
 * 1. Updates LED indicators.
 * 2. Displays debug information.
 * 3. Reads all simulated sensors.
 * 4. Evaluates transmission conditions.
 * 5. Sends an uplink when required.
 *
 * Transmission conditions:
 * - Periodic interval elapsed.
 * - Battery voltage reaches the configured threshold of 4.0 V.
 * - Water level reaches the configured threshold of 145 cm.
 *
 * This function implements the primary monitoring and
 * communication behaviour of the rain barrel monitoring
 * prototype.
 */
void loop()
{
  unsigned long now = millis(); // to count the time
  ledsControl();    // to control the the leds of the HAN_Node
  debugSensors();  // to show the reading of potintial meters in the serial monitor
  readSensors();

  if (battery_cV == 400 || level_cM == 145 || now - lastTime >= INTERVAL)
  {
    build_and_sendUplink();
    lastTime = now;
   }
}
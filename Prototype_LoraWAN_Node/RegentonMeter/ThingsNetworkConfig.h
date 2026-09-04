/*--------------------------------------------------------------------
  This file is part of the han-iot-portfolio-Prototype-LoRaWAN-node.
  --------------------------------------------------------------------*/
/**
 * @file ThingsNetworkConfig.h
 * @brief LoRaWAN network configuration and communication interface.
 *
 * @details
 * This module manages the connection between the prototype node and
 * The Things Network (TTN). It contains the LoRaWAN configuration
 * parameters, OTAA activation credentials, and the functions required
 * to join the network and transmit uplink messages.
 *
 * The module receives sensor data from the Sensor Module, encodes it
 * into a payload, and transmits the payload through the LoRaWAN
 * network.
 *
 * @author Nasser Abdulal
 */

#ifndef THINGSNETWORKCONFIC_H
#define THINGSNETWORKCONFIC_H

#include "sensors.h"
#include <TheThingsNetwork.h>
#include "mypayloadencoder.h"

/**
 * @def loraSerial
 * @brief Hardware serial interface connected to the LoRaWAN transceiver.
 */
#define loraSerial Serial1
/**
 * @def debugSerial
 * @brief USB serial interface used for debugging and diagnostics.
 */
#define debugSerial Serial
/**
 * @def freqPlan
 * @brief LoRaWAN regional frequency plan.
 *
 * Configured for the European EU868 frequency band.
 */
#define freqPlan TTN_FP_EU868

/**
 * @var appEui
 * @brief LoRaWAN application identifier.
 *
 * @details
 * Application EUI used during the Over-The-Air Activation (OTAA)
 * join procedure.
 */
extern const char *appEui;
/**
 * @var appKey
 * @brief LoRaWAN application key.
 *
 * @details
 * Security key issued by The Things Stack and used during
 * OTAA authentication.
 */
extern const char *appKey;

/**
 * @brief Initializes the LoRaWAN transceiver and joins the network.
 *
 * @details
 * Performs the following steps:
 * - Configures serial communication interfaces.
 * - Opens the debugging interface.
 * - Displays transceiver status information.
 * - Enables Adaptive Data Rate (ADR).
 * - Starts the OTAA join procedure.
 *
 * @note This function must be executed once during device startup.
 *
 * @post The device is connected to The Things Network and
 * ready to transmit uplink messages.
 */
void joinNetwork_and_debug();
/**
 * @brief Builds and transmits an uplink message.
 *
 * @details
 * Collects the latest measurements from the sensor module:
 * - Flow meter reading
 * - Water level
 * - Battery voltage
 *
 * The measurements are transferred to the payload encoder.
 * After payload construction the data is transmitted through
 * the LoRaWAN network using FPort 1.
 *
 * Following successful transmission, the flow meter counter
 * is reset to start a new measurement interval.
 *
 * @post An uplink packet is sent to The Things Network.
 */
void build_and_sendUplink();

#endif
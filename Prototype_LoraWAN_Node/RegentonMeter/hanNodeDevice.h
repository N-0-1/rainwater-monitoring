
#ifndef HANNONODEDEVICE_H
#define HANNONODEDEVICE_H

#include <OneWire.h>

// Library version
#define HANNONODEDEVICE_RELEASE 1

// Pin assignments (strongly typed)
extern const uint8_t PIN_LED_1_RED;    // PD3
extern const uint8_t PIN_LED_2_RED;    // PD4
extern const uint8_t PIN_LED_3_GRN;    // PD5
extern const uint8_t PIN_LED_4_GRN;    // PD6
extern const uint8_t PIN_SWITCH_BLACK; // PB4
extern const uint8_t PIN_SWITCH_RED;   // PB5 (simulates flowmeter pulses)
extern const uint8_t PIN_POT_RED;      // A0 (simulates battery voltage)
extern const uint8_t PIN_POT_WHITE;    // A1
extern const uint8_t PIN_DALLAS;       // OneWire pin

// Button logic levels
#define RELEASED HIGH
#define PRESSED  LOW

// Globals exposed by the library (declared here, defined in .cpp)
extern OneWire ds;

extern int        switchBlackState; // pushbutton status
extern int        switchRedState;   // pushbutton status
extern uint16_t   potRedValue;      // analog read (0..1023)
extern uint16_t   potWhiteValue;    // analog read (0..1023)

// Functions provided by the library
void initializeNodeHardware();
void ledsControl();

#endif // HANNONODEDEVICE_H

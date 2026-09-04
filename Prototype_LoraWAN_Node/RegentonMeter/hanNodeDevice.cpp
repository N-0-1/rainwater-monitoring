
#include "hannodedevice.h"

// ===== Pin definitions (single definition here) =====
const uint8_t PIN_LED_1_RED    = 3;  // PD3
const uint8_t PIN_LED_2_RED    = 4;  // PD4
const uint8_t PIN_LED_3_GRN    = 5;  // PD5
const uint8_t PIN_LED_4_GRN    = 6;  // PD6
const uint8_t PIN_SWITCH_BLACK = 8;  // PB4
const uint8_t PIN_SWITCH_RED   = 9;  // PB5, simulates flowmeter pulses
const uint8_t PIN_POT_RED      = A0; // simulates battery voltage
const uint8_t PIN_POT_WHITE    = A1;
const uint8_t PIN_DALLAS       = 2;  // OneWire on pin 2 (ensure 4.7k pull-up)

// ===== Global state (single definition here) =====
OneWire ds(PIN_DALLAS);

int      switchBlackState = RELEASED;
int      switchRedState   = RELEASED;
uint16_t potRedValue      = 0;
uint16_t potWhiteValue    = 0;

// ===== Implementation =====

void initializeNodeHardware()
{
  // LEDs
  pinMode(PIN_LED_1_RED, OUTPUT);
  pinMode(PIN_LED_2_RED, OUTPUT);
  pinMode(PIN_LED_3_GRN, OUTPUT);
  pinMode(PIN_LED_4_GRN, OUTPUT);

  // Buttons
  // Use INPUT_PULLUP if wired to ground (typical): PRESSED == LOW, RELEASED == HIGH
  pinMode(PIN_SWITCH_BLACK, INPUT_PULLUP);
  pinMode(PIN_SWITCH_RED,   INPUT_PULLUP);

  // Optionally set initial LED states
  digitalWrite(PIN_LED_1_RED, LOW);
  digitalWrite(PIN_LED_2_RED, LOW);

  // Note: OneWire requires an external 4.7k pull-up to Vcc on the data line
}

void ledsControl()
{
  // Read buttons and pots
  switchRedState   = digitalRead(PIN_SWITCH_RED);
  switchBlackState = digitalRead(PIN_SWITCH_BLACK);
  potRedValue      = analogRead(PIN_POT_RED);    // 0..1023
  potWhiteValue    = analogRead(PIN_POT_WHITE);  // 0..1023


  analogWrite(PIN_LED_3_GRN, 1023 - potRedValue / 4);            // LED 3 proportional to POT_RED
  analogWrite(PIN_LED_4_GRN, 1023 - potWhiteValue / 4);          // LED 4 proportional to POT_WHITE

  // Button-controlled red LEDs
  digitalWrite(PIN_LED_1_RED, (switchRedState   == PRESSED) ? HIGH : LOW);
  digitalWrite(PIN_LED_2_RED, (switchBlackState == PRESSED) ? HIGH : LOW);
}

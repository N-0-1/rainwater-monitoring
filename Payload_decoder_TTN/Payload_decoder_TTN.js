/**
 * @brief Decodes the LoRaWAN uplink payload received from the Rain-Tank Meter.
 *
 * @details
 * This formatter converts the raw payload bytes into application-level
 * sensor values. The payload layout must match the sensor definitions
 * configured in the encoder and decoder components.
 *
 * Current payload layout:
 * - Byte 0      : Flow Meter (uint8)
 * - Byte 1..2   : Level Meter (uint16)
 * - Byte 3..6   : Battery Voltage (uint32)
 *
 * @warning
 * Whenever the SensorDefinition table is modified (sensor size changed,
 * sensor added, sensor removed, or sensor order changed), this formatter
 * must be updated accordingly. The byte offsets and extraction logic used
 * here must always match the payload layout defined in the shared sensor
 * definitions.
 *
 * @see payloaddefinitions.h
 */
function decodeUplink(input) {
  var data = {};
 // var warnings = [];
 // var errors = [];

  // Basic validation
 /* if (!input.bytes || !Array.isArray(input.bytes)) {
    errors.push("Missing or invalid input.bytes (expected byte array)");
    return { data: {}, warnings: warnings, errors: errors };
  }
  if (input.bytes.length < 6) {
    errors.push("Payload too short: need 6 bytes");
    return { data: {}, warnings: warnings, errors: errors };
  }*/

  // Decode 3x uint16 (big-endian)
  data.flowMeter      = (input.bytes[0] << 8) + input.bytes[1];
  data.levelMeter     = (input.bytes[2] << 8) + input.bytes[3];
  data.batteryVoltage = (input.bytes[4] << 8) + input.bytes[5];

  // Optional: pass through metadata if present
 // if (input.recvTime) data.recvTime = input.recvTime.toString();
 // if (typeof input.fPort === "number") data.fPort = input.fPort;

  return {
    data: data,
   // warnings: warnings,
    //errors: errors,
  };
}

/*function normalizeUplink(input) {
  return {
    data: {
      meters: {
        flow: input.data.flowMeter,
        level: input.data.levelMeter,
      },
      battery: {
        voltage: input.data.batteryVoltage,
      },
    },
  };
}*/

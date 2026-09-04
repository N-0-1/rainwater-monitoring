@startuml

title Payload Codec Class Diagram

class myPayloadEncoder {
    -_sensorValues[]
    -_buffer
    -_bufferSize

    +setSensorValue()
    +composePayload()
    +getPayload()
    +getPayloadSize()
}

class myPayloadDecoder {
    -_sensorValues[]
    -_buffer
    -_bufferSize

    +setPayload()
    +setPayloadSize()
    +decodePayload()
    +getSensorValue()
}

class SensorDefinition <<struct>> {
    +size
    +name
}

enum SensorId {
    FLOW_METER
    LEVEL_METER
    BATTERY_VOLTAGE
}

myPayloadEncoder ..> SensorDefinition
myPayloadDecoder ..> SensorDefinition

myPayloadEncoder ..> SensorId
myPayloadDecoder ..> SensorId

myPayloadEncoder --> myPayloadDecoder : payload

@enduml
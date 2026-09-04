@startuml

title RainTank Network Database

class Device {
    <<table>>
    +PK id : int
    +device_id : char(16)
    +device_eui : char(16) {unique}
    +location : varchar(100)
}

class Measurement {
    <<table>>
    +PK id : bigint
    +FK device_id : int
    +uplink_at : datetime
    +battery_voltage_cv : decimal(8,3)
    +flow_volume_ml : decimal(12,3)
    +level_cm : decimal(12,3)
}

class RadioMetadata {
    <<table>>
    +PK id : bigint
    +FK measurement_id : bigint
    +gateway_name : varchar(100)
    +gateway_eui : char(16)
    +rssi : int
    +snr : decimal(5,2)
    +latitude : decimal(10,7)
    +longitude : decimal(10,7)
    +height : decimal(8,2)
}

Device "1" -- "0..*" Measurement : generates

Measurement "1" -- "0..*" RadioMetadata : received by

@enduml
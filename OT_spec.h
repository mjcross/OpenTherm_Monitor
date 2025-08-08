#ifndef OT_SPEC_H
#define OT_SPEC_H

/* 
 * ===========================================================
 * Message types and Data IDs from the OpenTherm specification
 * ===========================================================
*/

typedef enum {
    // master-to-slave messages
    READ_DATA =     0b000,
    WRITE_DATA =    0b001,
    INVALID_DATA =  0b010,
    RESERVED =      0b011,
    // slave-to-master messages
    READ_ACK =      0b100,
    WRITE_ACK =     0b101,
    DATA_INVALID =  0b110,
    UNKNOWN_DATAID =  0b111
} OT_msg_type_t;

typedef enum {
    // class 1: control and status information
    STATUS_FLAGS = 0,               // all masters and slaves must support
    CONTROL_SETPOINT = 1,           // all masters and slaves must support
    APPLICATION_FAULT_FLAGS = 5,
    CONTROL_SETPOINT_2 = 8,
    OEM_DIAGNOSTIC_CODE = 115,
    // class 2: configuration information
    MASTER_CONFIGURATION = 2,
    SLAVE_CONFIGURATION = 3,        // all masters must read and all slaves must support
    OPENTHERM_VERSION_MASTER = 124,
    OPENTHERM_VERSION_SLAVE = 125,
    MASTER_PRODUCT_VERSION = 126,
    SLAVE_PRODUCT_VERSION = 127,
    // class 3: remote commands
    COMMAND_CODE = 4,
    // class 4: sensor and informational data
    ROOM_SETPOINT = 16,
    RELATIVE_MODULATION_LEVEL = 17, // all slaves must support
    CH_WATER_PRESSURE = 18,
    DHW_FLOW_RATE = 19,
    DAY_AND_TIME = 20,
    DATE = 21,
    YEAR = 22,
    ROOM_SETPOINT_CH2 = 23,
    ROOM_TEMPERATURE = 24,
    BOILER_WATER_TEMP = 25,         // all slaves must support
    DHW_TEMPERATURE = 26,
    OUTSIDE_TEMPERATURE = 27,
    RETURN_WATER_TEMPERATURE = 28,
    SOLAR_STORAGE_TEMPERATURE = 29,
    SOLAR_COLLECTOR_TEMPERATURE = 30,
    FLOW_TEMPERATURE_CH2 = 31,
    DHW2_TEMPERATURE = 32,
    EXHAUST_TEMPERATURE = 33,
    BOILER_STARTS = 116,
    CH_PUMP_STARTS = 117,
    DHW_PUMP_VALVE_STARTS = 118,
    DHW_BURNER_STARTS = 119,
    BURNER_OPERATION_HOURS = 120,
    CH_PUMP_OPERATION_HOURS = 121,
    DHW_PUMP_VALVE_OPERATION_HOURS = 122,
    DHW_BURNER_OPERATION_HOURS = 123,
    // class 5: pre-defined remote boiler parameters
    REMOTE_PARAMETER_TRANSFER_ENABLE_FLAGS = 6,
    DHW_SETP_BOUNDS = 48,
    CH_SETP_BOUNDS = 49,
    HEAT_CURVE_RATIO_BOUNDS = 50,
    DHW_SETPOINT = 56,
    MAX_CHW_SETPOINT = 57,
    HEAT_CURVE_RATIO = 58,
    // class 6: transparent slave parameters
    NUMBER_OF_TSPS = 10,
    TSP_READ_WRITE = 11,
    // class 7: faulf history data
    SIZE_OF_FAULT_BUFFER = 12,
    READ_FAULT_BUFFER_ENTRY = 13,
    // class 8: control of special applications
    COOLING_CONTROL_SIGNAL = 7,
    MAXIMUM_MODULATION = 14,        // for master on/off control mode, all slaves must support
    MAX_CAPACITY_AND_MIN_MODULATION = 15,
    REMOTE_OVERRIDE_ROOM_SETPOINT = 9,
    REMOTE_OVERRIDE_FUNCTION = 100,

    // *** NEW CODES NOT IN V2.2 ***
    // from https://github.com/rvdbreemen/OTGW-firmware/blob/dev/Specification/New%20OT%20data-ids.txt
    RF_SENSOR_SIGNAL_AND_BATTERY_LEVEL = 98,
    OPERATING_MODE_HC1_HC2_DHW = 99,
    ELECTRICITY_PRODUCER_STARTS = 109,
    ELECTRICITY_PRODUCER_HOURS = 110,
    ELECTRICITY_PRODUCTION = 111,
    CUMULATIVE_ELECTRICITY_PRODUCTION = 112,
    ELECTRICAL_CURRENT_THROUGH_BURNER_FLAME = 36,   // micro Amps
    ROOM_TEMPERATURE_FOR_CH2 = 37,
    RELATIVE_HUMIDITY = 38
    // various other codes are listed for Remeha boilers (now onwed by Baxi)
} OT_data_id_t;


#endif
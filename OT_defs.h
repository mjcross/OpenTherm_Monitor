/*
 * ==============================================
 * OpenTherm data types and function declarations
 * ==============================================
 */

#ifndef OT_DEFS_H
#define OT_DEFS_H

#include "pico/stdlib.h"
#include "OT_spec.h"  // constants defined by the spec

// ----------
// data types
// ----------

// Composite data type for a 32 bit OpenTherm frame
// uses C11 anonymous structures and unions for direct access to the fields
//
typedef union {
    struct {
         union {
            struct {
                uint8_t data_value_LB: 8;
                uint8_t data_value_HB: 8;
            };
            uint16_t data_value: 16;
        };
        OT_data_id_t data_id: 8;
        uint spare: 4;
        OT_msg_type_t msg_type: 3;
        bool parity: 1;             // msb of struct
    };
    uint32_t raw;
} OT_frame_t;

// master status flags
typedef union {
    struct {
        bool ch_enable: 1;          // lsb of struct
        bool dhw_enable: 1;
        bool cooling_enable: 1;
        bool otc_active: 1;
        bool ch2_enable: 1;
        uint32_t reserved: 3;
    };
    uint8_t raw;
} OT_master_status_t;

// slave status flags
typedef union {
    struct {
        bool fault_indication: 1;   // lsb of struct
        bool ch_mode: 1;
        bool dhw_mode: 1;
        bool flame_status: 1;
        bool cooling_status: 1;
        bool ch2_mode: 1;
        bool diagnostic_indication: 1;
        bool electricity_production: 1;
    };
    uint8_t raw;
} OT_slave_status_t;

// slave configuration flags
typedef union {
    struct {
        bool dhw_present: 1;
        bool control_type: 1;   // 0=modulating, 1=on/off
        bool cooling_config: 1; // 0=not supported, 1=supported
        bool dhw_config: 1;     // 0=instantaneous or unspecified, 1=storage tank
        bool master_low_and_pump: 1;    // 0=allowed, 1=not allowed
        bool ch2_present: 1;
        uint32_t reserved: 2;
    };
    uint8_t raw;
} OT_slave_config_t;

// application-specific flags
typedef union {
    struct {
        bool service_req: 1;    // 0=service not required, 1=service required
        bool lockout_reset: 1;  // 0=remote reset disabled, 1=enabled
        bool low_water_pres: 1; // 0=water pressure OK, 1=low water pressure
        bool flame_fault: 1;    // 0=gas/flame OK, 1=fault
        bool air_pres_fault: 1; // 0=air pressure OK, 1=fault
        bool water_overtemp: 1; // 0=water temp OK, 1=fault
        uint32_t reserved: 2;
    };
    uint8_t raw;
} OT_app_specific_flags_t;

// remote parameter flags
typedef union {
    struct {
        bool dhw_setpoint: 1;       // RP1
        bool max_ch_setpoint: 1;    // RP2
        bool rp3: 1;
        bool rp4: 1;
        bool rp5: 1;
        bool rp6: 1;
        bool rp7: 1;
        bool rp8: 1;
    };
    uint8_t raw;
} OT_remote_param_flags_t;


// ---------
// functions
// ---------

bool OT_frame_calc_parity (OT_frame_t *p_frame);
void OT_frame_update_parity (OT_frame_t *p_frame);
bool OT_frame_parity_OK (OT_frame_t *p_frame);
float f88_to_float (int16_t f88);
uint16_t float_to_f88 (float f);
void display_frame (OT_frame_t *p_frame);
void decode_frame (OT_frame_t *p_frame);

#endif
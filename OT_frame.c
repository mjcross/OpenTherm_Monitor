#include <stdio.h>  // for printf() in display_frame()
#include "pico/stdlib.h"
#include "OT_defs.h"
#include "OTv2.3b_data_ids.h"   // data_id names

bool OT_frame_calc_parity (OT_frame_t *p_frame) {
    bool parity = 0;
    OT_frame_t frame_copy = *p_frame;
    while (frame_copy.raw) {
        frame_copy.raw <<= 1;    // intentionally skip first (parity) bit
        parity ^= frame_copy.parity;
    }
    return parity;
}

void OT_frame_update_parity (OT_frame_t *p_frame) {
    p_frame->parity = OT_frame_calc_parity (p_frame);
}

bool OT_frame_parity_OK (OT_frame_t *p_frame) {
    return p_frame->parity == OT_frame_calc_parity (p_frame);
}

float f88_to_float (int16_t f88) {
    return (float)f88 / 256.0;
}

uint16_t float_to_f88 (float f) {
    return (uint16_t)((int16_t)(f * 256));
}

void display_frame (OT_frame_t *p_frame) {
    printf ("%1d %3d %04x", 
        p_frame->msg_type, 
        p_frame->data_id,
        p_frame->data_value);
}

void decode_frame (OT_frame_t *p_frame) {
    switch (p_frame->msg_type) {
        case READ_DATA:
        case READ_ACK:
            printf ("read");
            break;
        case WRITE_DATA:
        case WRITE_ACK:
            printf ("write");
            break;
        default:
            printf ("?");
            break;
    }

    struct OTlookup_t item = OTmap[p_frame->data_id];
    printf (" %s  ", item.friendlyname);

    switch (item.type) {
        case ot_f88:
            printf("%5.2f", f88_to_float (p_frame->data_value));
            break;
        case ot_s16:
            printf ("%d", p_frame->data_value);
            break;
        case ot_s8s8:
            printf ("%d, %d", p_frame->data_value_HB, p_frame->data_value_LB);
            break;
        case ot_u16:
            printf ("%u", p_frame->data_value);
            break;
        case ot_u8u8:
            printf ("%u, %u", p_frame->data_value_HB, p_frame->data_value_LB);
            break;
        case ot_flag8:
            printf ("%08b", p_frame->data_value_LB);
            break;
        case ot_flag8flag8:
            printf ("%08b, %08b", p_frame->data_value_HB, p_frame->data_value_LB);
            break;
        case ot_special:
            printf ("0x%08x", p_frame->data_value);
            break;
        case ot_flag8u8:
            printf ("%08b, %u", p_frame->data_value_HB, p_frame->data_value_LB);
            break;
        case ot_u8:
            printf ("%u", p_frame->data_value_LB);
            break;
        case ot_undef:
            printf ("-");
            break;
    }

    printf ( " %s", item.unit);
}

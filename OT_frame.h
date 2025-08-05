#ifndef OT_FRAME_H
#define OT_FRAME_H

#include "OT_defs.h"

bool OT_frame_calc_parity (OT_frame_t *p_frame);
void OT_frame_update_parity (OT_frame_t *p_frame);
bool OT_frame_parity_OK (OT_frame_t *p_frame);
float f88_to_float (int16_t f88);
uint16_t float_to_f88 (float f);
void display_frame (OT_frame_t *p_frame);
void decode_frame (OT_frame_t *p_frame);

#endif
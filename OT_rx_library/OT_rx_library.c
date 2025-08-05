#include <stdio.h>
#include "hardware/gpio.h"
#include "OT_rx_library.h"


bool OT_rx_init (PIO pio, uint *p_sm, uint gpio, bool invert_rx) {

    static bool rx_prog_is_loaded = false;   // whether the state machine code has been loaded
    static uint rx_prog_offset; // location of the code in the PIO shared memory

    // add the RX state machine code to the PIO shared memory if needed
    if (rx_prog_is_loaded == false) {
        if (pio_can_add_program (pio, &OT_rx_program) == false) {
            puts ("could not add RX program to PIO shared memory");
            return false;   // failure
        } else {
            rx_prog_offset = pio_add_program (pio, &OT_rx_program);
            rx_prog_is_loaded = true;
        }
    }

    // claim a free state machine
    int sm = pio_claim_unused_sm (pio, false);
    if (sm == -1) {
        puts ("could not claim a state machine");
        return false;   // failure
    } else {
        *p_sm = (uint)sm;
    }

    // initialise GPIO pin for input, inverted if required
    gpio_init (gpio);
    if (invert_rx) {
        gpio_set_inover (gpio, GPIO_OVERRIDE_INVERT);
    }

    // configure and enable the state machine
    OT_rx_sm_init (pio, *p_sm, rx_prog_offset, gpio);

    return true;    //success
}
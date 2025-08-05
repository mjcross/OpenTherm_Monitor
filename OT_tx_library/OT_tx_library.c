#include <stdio.h>
#include "hardware/gpio.h"
#include "OT_tx_library.h"


bool OT_tx_init (PIO pio, uint *p_sm, uint gpio, bool invert_tx) {

    static bool tx_prog_is_loaded = false;   // whether the state machine code has been loaded
    static uint tx_prog_offset; // location of the code in the PIO shared memory

    // add the RX state machine code to the PIO shared memory if needed
    if (tx_prog_is_loaded == false) {
        if (pio_can_add_program (pio, &OT_tx_program) == false) {
            puts ("could not add TX program to PIO shared memory");
            return false;   // failure
        } else {
            tx_prog_offset = pio_add_program (pio, &OT_tx_program);
            tx_prog_is_loaded = true;
        }
    }

    // claim a free state machine
    int sm = pio_claim_unused_sm (pio, false);
    if (sm == -1) {
        puts ("could not claim a state machine");
        return false; // failure
    } else {
        *p_sm = (uint)sm;
    }

    // set the gpio pin function to PIO output, inverted if required
    pio_gpio_init (pio, gpio);
    pio_sm_set_consecutive_pindirs (pio, *p_sm, gpio, 1, true);
    if (invert_tx) {
        gpio_set_outover (gpio, GPIO_OVERRIDE_INVERT);
    }

    // configure and enable the state machine
    OT_tx_sm_init (pio, *p_sm, tx_prog_offset, gpio);

    return true;    // success
}
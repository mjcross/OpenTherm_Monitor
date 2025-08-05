/*
Loopback test for the Manchester encoder/decoder state machine code

Connect 'cross-over' cables from gpio_master_tx to gpio_slave_rx and
from gpio_slave_tx to gpio_master_rx

Alternatively you can test the full path via the OpenTherm interface board
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "OT_rx_library.h"
#include "OT_tx_library.h"
#include "OT_defs.h"
#include "OT_frame.h"

const PIO pio = pio0;
const uint gpio_master_rx = 14;     // receive from controller (input)
const uint gpio_master_tx = 15;     // transmit to controller (output)
const uint gpio_slave_rx = 17;      // receive from boiler (input)
const uint gpio_slave_tx = 16;      // transmit to boiler (output)

int main()
{
    stdio_init_all();

    uint sm_master_tx, sm_master_rx, sm_slave_tx, sm_slave_rx;

    // load and start PIO state machines
    if ( 
        OT_tx_init (pio, &sm_master_tx, gpio_master_tx, true) &&
        OT_rx_init (pio, &sm_master_rx, gpio_master_rx, true) &&
        OT_tx_init (pio, &sm_slave_tx,  gpio_slave_tx,  true) &&
        OT_rx_init (pio, &sm_slave_rx,  gpio_slave_rx,  true)
    ) {
        puts ("State machines loaded and running");
    } else {
        puts ("error initialising SMs");
        while (true);
    }

    puts("Entering main loop");
    int loop_counter = 0;

    // create a test frame
    OT_frame_t tx_frame = {}, rx_frame = {};

    while (true) {
        loop_counter += 1;

        tx_frame.msg_type = READ_DATA;
        tx_frame.data_id = STATUS_FLAGS;
        tx_frame.data_value = loop_counter;
        OT_frame_update_parity (&tx_frame);

        putchar ('\n');

        // check Master -> Slave
        printf ("Master sent\t");
        pio_sm_put_blocking (pio, sm_master_tx, tx_frame.raw);
        display_frame (&tx_frame);
        putchar ('\n');

        printf ("Slave rcvd\t");
        rx_frame.raw = pio_sm_get_blocking (pio, sm_slave_rx);
        display_frame (&rx_frame);

        if (tx_frame.raw == rx_frame.raw) {
            puts ("\tOK");
        } else {
            puts ("\tERROR");
        }

        sleep_ms(500);

        // check Slave -> Master
        printf ("Slave sent\t");
        pio_sm_put_blocking (pio, sm_slave_tx, tx_frame.raw);
        display_frame (&tx_frame);
        putchar ('\n');

        printf ("Master rcvd\t");
        rx_frame.raw = pio_sm_get_blocking (pio, sm_master_rx);
        display_frame (&rx_frame);

        if (tx_frame.raw == rx_frame.raw) {
            puts ("\tOK");
        } else {
            puts ("\tERROR");
        }
        
        sleep_ms(500);
    }
}

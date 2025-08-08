/*
* Loopback test for the Manchester encoder/decoder state machine code
* and/or the OpenTherm interface board

To test just the encoders and decoders, connect 'cross-over' cables from 
gpio_master_tx to gpio_slave_rx and from gpio_slave_tx to gpio_master_rx.

! IMPORTANT NOTE
To test the interface board, note that to simplify the circuit it uses
inverse logic on the slave side:

Pulling slave_tx low (0) sends high current (active, 1) which is
detected as master_rx high (1).

Pulling master_tx low (0) sends low voltage (idle, 0) which is
detected as slave_rx high (1).

Therefore we should set the logic inversion as follows:

OT_tx_init (pio, &sm_master_tx, gpio_master_tx, false)  // normal logic
OT_rx_init (pio, &sm_master_rx, gpio_master_rx, false)  // normal logic
OT_tx_init (pio, &sm_slave_tx,  gpio_slave_tx,  true)   // inverted logic
OT_rx_init (pio, &sm_slave_rx,  gpio_slave_rx,  true)   // inverted logic
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

    // load and start PIO state machines (inverse logic for slave interface)
    if ( 
        OT_tx_init (pio, &sm_master_tx, gpio_master_tx, false) &&
        OT_rx_init (pio, &sm_master_rx, gpio_master_rx, false) &&
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
    int ok_count = 0;
    int error_count = 0;

    // create a test frame
    OT_frame_t tx_frame = {}, rx_frame = {};

    while (true) {
        loop_counter += 1;

        tx_frame.msg_type = READ_DATA;
        tx_frame.data_id = STATUS_FLAGS;
        tx_frame.data_value = loop_counter;
        OT_frame_update_parity (&tx_frame);

        putchar ('\n');

        printf ("Slave sent\t");
        pio_sm_put_blocking (pio, sm_slave_tx, tx_frame.raw);
        display_frame (&tx_frame);
        putchar ('\n');

        sleep_ms(500);

        printf ("Master rcvd\t");
        while (!pio_sm_is_rx_fifo_empty(pio, sm_master_rx)) {
            rx_frame.raw = pio_sm_get_blocking (pio, sm_master_rx);
            display_frame (&rx_frame);

            if (tx_frame.raw == rx_frame.raw) {
                ok_count += 1;
            } else {
                error_count += 1;
            }  
        }

        printf ("\tOK %d\tError %d\n", ok_count, error_count);

        sleep_ms(500);

        printf ("Master sent\t");
        pio_sm_put_blocking (pio, sm_master_tx, tx_frame.raw);
        display_frame (&tx_frame);
        putchar ('\n');

        sleep_ms(500);

        printf ("Slave rcvd\t");
        while (!pio_sm_is_rx_fifo_empty(pio, sm_slave_rx)) {
            rx_frame.raw = pio_sm_get_blocking (pio, sm_slave_rx);
            display_frame (&rx_frame);

            if (tx_frame.raw == rx_frame.raw) {
                ok_count += 1;
            } else {
                error_count += 1;
            }  
        }

        printf ("\tOK %d\tError %d\n", ok_count, error_count);

       


        sleep_ms(500);
    
    }
}

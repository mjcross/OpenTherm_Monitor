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

    puts ("Starting in...");
    for (int i=20; i>0; i--) {
        printf ("%d\n", i);
        sleep_ms (1000);
    }

    uint sm_master_tx, sm_master_rx, sm_slave_tx, sm_slave_rx;

    // load and start PIO state machines (inverse logic for slave interface)
    if ( 
        OT_tx_init (pio, &sm_master_tx, gpio_master_tx, false) &&
        OT_rx_init (pio, &sm_master_rx, gpio_master_rx, false) &&
        OT_tx_init (pio, &sm_slave_tx,  gpio_slave_tx,  true) &&    // inverse logic
        OT_rx_init (pio, &sm_slave_rx,  gpio_slave_rx,  true)       // inverse logic
    ) {
        puts ("State machines loaded and running");
    } else {
        puts ("error initialising SMs");
        while (true);
    }

    OT_frame_t controller_command, boiler_response;
    puts("Entering main loop");
    while (true) {

        // listen to our 'slave' interface for commands from the controller
        if (!pio_sm_is_rx_fifo_empty (pio, sm_slave_rx)) {
            // receive command from controller on our 'slave' interface
            controller_command.raw = pio_sm_get (pio, sm_slave_rx);
            // display decoded frame
            printf ("Controller:\t");
            display_frame (&controller_command);
            putchar ('\t');
            decode_frame (&controller_command);
            putchar ('\n');
            // forward command to boiler via our 'master' interface
            pio_sm_put_blocking (pio, sm_master_tx, controller_command.raw);
        }

        // listen to our 'master' interface for responses from the boiler 
        if (!pio_sm_is_rx_fifo_empty (pio, sm_master_rx)) {
            // receive response from boiler on our 'master' interface
            boiler_response.raw = pio_sm_get (pio, sm_master_rx);
            // display decoded frame
            printf ("Boiler:    \t");
            display_frame (&boiler_response);
            putchar ('\t');
            decode_frame (&boiler_response);
            putchar ('\n');
            // forward response to controller via our 'slave' interface
            pio_sm_put_blocking (pio, sm_slave_tx, boiler_response.raw);
        }

    }
}

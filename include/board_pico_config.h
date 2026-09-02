/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * XIAO RP2040 configuration for CMSIS-DAP SWD use.
 *
 * Physical XIAO mapping:
 *   D7  / GPIO1 -> target nRESET
 *   D8  / GPIO2 -> target SWCLK
 *   D10 / GPIO3 -> target SWDIO
 *
 * UART bridge and LEDs are intentionally disabled. This keeps GPIO1 dedicated
 * to target reset and avoids assigning functions to pins/LEDs not required for
 * the Solum M3 recovery use case.
 */

#ifndef BOARD_PICO_H_
#define BOARD_PICO_H_

#define PROBE_IO_RAW

// PIO / SWD configuration
#define PROBE_SM 0
#define PROBE_PIN_OFFSET 2
#define PROBE_PIN_SWCLK (PROBE_PIN_OFFSET + 0) // GPIO2 / XIAO D8
#define PROBE_PIN_SWDIO (PROBE_PIN_OFFSET + 1) // GPIO3 / XIAO D10

// Target reset, active-low
#define PROBE_PIN_RESET 1                      // GPIO1 / XIAO D7

#define PROBE_PRODUCT_STRING "Debugprobe on XIAO RP2040 (CMSIS-DAP)"

#endif

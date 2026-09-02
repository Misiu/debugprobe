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
 * The upstream debugprobe build always compiles cdc_uart.c, so UART symbols
 * must remain defined even if the UART bridge is not needed for Solum recovery.
 * UART is therefore assigned to GPIO4/GPIO5 (UART1), leaving GPIO1 exclusively
 * available for target nRESET.
 */

#ifndef BOARD_PICO_H_
#define BOARD_PICO_H_

#define PROBE_IO_RAW
#define PROBE_CDC_UART

// PIO / SWD configuration
#define PROBE_SM 0
#define PROBE_PIN_OFFSET 2
#define PROBE_PIN_SWCLK (PROBE_PIN_OFFSET + 0) // GPIO2 / XIAO D8
#define PROBE_PIN_SWDIO (PROBE_PIN_OFFSET + 1) // GPIO3 / XIAO D10

// Target reset, active-low
#define PROBE_PIN_RESET 1                      // GPIO1 / XIAO D7

// CDC UART bridge. Not required for Solum recovery, but debugprobe currently
// compiles cdc_uart.c unconditionally and therefore requires these definitions.
// GPIO4/GPIO5 are valid UART1 pins on RP2040 and do not conflict with SWD/reset.
#define PROBE_UART_TX 4
#define PROBE_UART_RX 5
#define PROBE_UART_INTERFACE uart1
#define PROBE_UART_BAUDRATE 115200

#define PROBE_PRODUCT_STRING "Debugprobe on XIAO RP2040 (CMSIS-DAP)"

#endif

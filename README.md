# Debugprobe for Seeed Studio XIAO RP2040

This fork targets **Seeed Studio XIAO RP2040** as a CMSIS-DAP/SWD debug probe with a dedicated target reset line.

It is based on the Raspberry Pi Debug Probe firmware, but this repository is intentionally focused only on the XIAO RP2040 configuration.

## Wiring

| XIAO pin | RP2040 GPIO | Debug Probe function | Connect to target |
| --- | ---: | --- | --- |
| **D7** | GPIO1 | Target reset | **nRESET** |
| **D8** | GPIO2 | SWD clock | **SWCLK** |
| **D10** | GPIO3 | SWD data | **SWDIO** |
| **GND** | - | Ground | **GND** |
| **3V3** | - | 3.3 V supply | **VCC / 3.3 V** |

![XIAO RP2040 Debug Probe wiring](docs/xiao-rp2040-debugprobe-wiring.png)

The diagram follows the official Seeed Studio XIAO RP2040 front-pinout naming. See the [official Seeed Studio pinout](https://files.seeedstudio.com/wiki/XIAO-RP2040/img/XIAO_RP2040_front_pinout.png) and the [XIAO RP2040 documentation](https://wiki.seeedstudio.com/XIAO-RP2040/).

> **Important:** the target interface is 3.3 V. Do **not** connect the target to the XIAO `5V` pin.

For the Solum M3 recovery use case only five connections are required: `D7/nRESET`, `D8/SWCLK`, `D10/SWDIO`, `GND`, and `3V3`.

The CDC UART bridge remains assigned internally to GPIO4/GPIO5 because the upstream Debug Probe source currently compiles the UART component, but UART is not required for SWD programming.

## Build

GitHub Actions builds the XIAO RP2040 firmware automatically using Pico SDK 2.3.0.

Expected artifact:

```text
debugprobe_on_xiao_rp2040.uf2
```

The workflow is located at:

```text
.github/workflows/build-xiao-rp2040.yml
```

## Install on XIAO RP2040

1. Put the XIAO RP2040 into UF2 bootloader mode so that the computer exposes the `RPI-RP2` drive.
2. Copy `debugprobe_on_xiao_rp2040.uf2` to that drive.
3. After reboot, the board should enumerate as a CMSIS-DAP Debug Probe.

## Pin configuration

The XIAO-specific configuration is in:

```text
include/board_pico_config.h
```

Relevant definitions:

```c
#define PROBE_PIN_RESET 1
#define PROBE_PIN_SWCLK 2
#define PROBE_PIN_SWDIO 3

#define PROBE_UART_TX 4
#define PROBE_UART_RX 5
#define PROBE_UART_INTERFACE uart1
#define PROBE_UART_BAUDRATE 115200
```

## Upstream

Original Raspberry Pi Debug Probe project:

https://github.com/raspberrypi/debugprobe

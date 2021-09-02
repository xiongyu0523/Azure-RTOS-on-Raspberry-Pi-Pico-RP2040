# Azure RTOS threadx on Raspberry Pi PR2040

This sample demonstrates [Azure RTOS threadx](https://azure.com/rtos) on Raspberry Pi RP2040 Microcontroller

## Contents

| File/folder       | Description                                |
|-------------------|--------------------------------------------|
| `demo_threadx.c`    | Sample source code.                        |
| `threadx`           | Azure RTOS ThreadX source code and cortex-m0 port.            |
| `tx_initialize_low_level.S`     | RP2040 specific low-level initialization code.                         |
| `main.c`       | RP2040 user application entry point.                          |

## Prerequisites

1. [Raspberry Pi Pico](https://www.raspberrypi.org/products/raspberry-pi-pico/) board

2. A terminal emulator (such as [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/) or [Tera Term](https://ttssh2.osdn.jp/index.html.en) to display the output.

3. Follow chapter 8.2 of [Getting Started with Raspberry Pi Pico](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf) to setup the build environment on Windows 10.

## Build and run the sample

1. Clone this repository (and threadx as a submodule) alongside the pico-sdk (>= 1.2.0) directory. (This project is an external project depends on pico-sdk)
   
   ```
   git clone --recurse-submodules https://github.com/xiongyu0523/Azure-RTOS-on-Raspberry-Pi-Pico-RP2040
   ```

2. Open a **Developer command prompt** for VS2019 and go to the cloned project to build
   
   ```
   cd Azure-RTOS-on-Azure-Sphere-Mediatek-MT3620
   mkdir build
   cd build
   # assume PICO-SDK-PATH is set to ../../pico-sdk
   cmake .. -G "NMake Makefiles"
   # waiting for namke project generation
   nmake 
   ```

3. Hold the BOOTSEL button on Raspberry Pi Pico and connect micro-USB cable, you will see a new USB drive `PRI-PR2` is mounted.

4. Drag and drop the `Azure-RTOS-on-Raspberry-Pi-Pico-RP2040.uf2` file in build folder to the USB drive

## Observe the output

Open a terminal and connect to the `USB Serial Device (COMx)` just enumerated. You will see a statistical data of multiple tasks printed every second and LED is blinking at 1Hz.

```
ThreadX Demo
**** ThreadX Demonstration on Raspberry Pi Pico ****
           thread 0 events sent:          108
           thread 1 messages sent:        3926897
           thread 2 messages received:    3926877
           thread 3 obtained semaphore:   268
           thread 4 obtained semaphore:   268
           thread 5 events received:      107
           thread 6 mutex obtained:       268
           thread 7 mutex obtained:       268
```

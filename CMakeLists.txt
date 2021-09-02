cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(Azure-RTOS-on-Raspberry-Pi-Pico-RP2040)

pico_sdk_init()

#add_definitions(-DPendSV_Handler=isr_pendsv)
#add_definitions(-DSysTick_Handler=isr_systick)

add_executable(${PROJECT_NAME} main.c tx_initialize_low_level.S demo_threadx.c)

pico_enable_stdio_usb(${PROJECT_NAME} 1)

pico_add_extra_outputs(${PROJECT_NAME})

set(THREADX_ARCH "cortex_m0")
set(THREADX_TOOLCHAIN "gnu")
add_subdirectory(threadx)

target_link_libraries(${PROJECT_NAME} pico_stdlib cmsis_core azrtos::threadx)
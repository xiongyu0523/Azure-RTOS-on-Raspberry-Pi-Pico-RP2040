cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(test_project)

pico_sdk_init()

add_executable(test test.c)

pico_enable_stdio_usb(test 1)

pico_add_extra_outputs(test)

target_link_libraries(test pico_stdlib)
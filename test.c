/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

extern void demo_threadx(void);
extern void __vectors(void);
extern void isr_pendsv(void);
extern void isr_systick(void);
extern void _tx_initialize_low_level(void);

int main() {

    stdio_init_all();
    printf("ThreadX Demo\n");

    _tx_initialize_low_level();

    // LED OFF
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, 0);

    demo_threadx();

    return 0;
}
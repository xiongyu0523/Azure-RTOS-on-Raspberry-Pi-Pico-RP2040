/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

extern void demo_threadx(void);

int main() {

    stdio_init_all();
    printf("ThreadX Demo\n");

    demo_threadx();

    return 0;
}
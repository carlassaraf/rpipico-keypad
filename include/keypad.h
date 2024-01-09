/*
 * Copyright (c) 2023 Fabrizio Carlassara <fabrizio.carlassara@gmail.com>
*/
#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include "pico/stdlib.h"

// Prototipos de funciones

void keypad_init(uint8_t columns[4], uint8_t rows[4], char matrix_values[16]);
char keypad_get_key(void);
void keypad_irq_enable(bool enable, gpio_irq_callback_t callback);

#endif

/*
 * Copyright (c) 2023 Fabrizio Carlassara <fabrizio.carlassara@gmail.com>
*/
#include "keypad.h"

// Puntero a GPIOs de columnas y filas
static uint8_t *_columns, *_rows;
// Puntero a valores de keypad
static char *_matrix_values;
// Mascara de GPIOs a columnas
static uint32_t _all_rows_mask = 0x0;

/**
 * @brief Obtiene el numero de GPIO a partir de un puntero y offset
 * @param ptr puntero a lista de GPIO
 * @param off offset de la lista
 * @return numero de GPIO almacenado
*/
static inline uint8_t gpio_from_ptr(uint8_t *ptr, uint8_t off) {
    return *(ptr + sizeof(uint8_t) * off);
}

/**
 * @brief Inicializa el keypad
 * @param columns Pins connected to keypad columns
 * @param rows Pins connected to keypad rows
 * @param matrix_values values assigned to each key
*/
void keypad_init(uint8_t columns[4], uint8_t rows[4], char matrix_values[16]) {
    // Copio los valores del teclado
    _matrix_values = matrix_values;
    // Copio los valores de GPIOs
    _columns = columns;
    _rows = rows;
    // Inicializo los GPIOs
    for (uint8_t i = 0; i < 4; i++) {
        // GPIO de fila y columna
        uint8_t row = gpio_from_ptr(_rows, i);
        uint8_t column = gpio_from_ptr(_columns, i);
        // Inicializo GPIO de columna y fila
        gpio_init(column);
        gpio_init(row);
        // Configuro GPIOs como entrada/salida
        gpio_set_dir(column, GPIO_IN);
        gpio_set_dir(row, GPIO_OUT);
        // Armo una mascara para todas las filas
        _all_rows_mask |= (1 << row);
    }
	// Dejo todas las filas en uno
    gpio_put_masked(_all_rows_mask, _all_rows_mask);
}

/**
 * @brief Obtiene la primer tecla presionada
 * @return caracter presionado del keypad
*/
char keypad_get_key(void) {
    // Pongo un cero en todas las filas
    gpio_put_masked(_all_rows_mask, 0x00);
    // Itero en cada fila
    for(uint8_t row = 0; row < 4; row++) {
        // Pongo un uno en la fila
        gpio_put(_rows[row], true);
        // Recorro cada columna
        for(uint8_t col = 0; col < 4; col++) {
            // Reviso si esta columna fue apretada
            if(gpio_get(_columns[col])) {
                // Devuelvo el caracter de esta fila y columna
                return _matrix_values[row * 4 + col];
            }
        }
        // Pongo un cero en la fila antes de ir a la siguiente
        gpio_put(_rows[row], false);
    } 
    // Devuelvo cero si no hay nada apretado
    return 0;
}

/**
 * @brief Configuro keypad para trabajar por interrupciones
 * @param enable habilita o deshabilita interrupcion
 * @param callback funcion invocada cuando se dispara la interrupcion
*/
void keypad_irq_enable(bool enable, gpio_irq_callback_t callback) {
    // Recorro todos los GPIO de las columnas para habilitar/deshabilitar IRQ
    for (uint8_t i = 0; i < 4; i++) {
        // Configuro interrupcion para trabajar por flanco ascendente
        gpio_set_irq_enabled_with_callback(_columns[i], GPIO_IRQ_EDGE_RISE, enable, callback);
    }
}

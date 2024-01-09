#include <stdio.h>
#include "pico/stdlib.h"
#include "keypad.h"

// Array con GPIOs conectados a las columnas
uint8_t columns[4] = { 20, 21, 22, 26 };
// Array con GPIOs conectados a las filas
uint8_t rows[4] = { 16, 17, 18, 19 };
// Teclas en el keypad
char matrix[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

/**
 * @brief Callback para la interrupcion por keypad
 * @param gpio numero de GPIO que disparo la interrupcion
 * @param event_mask tipo de evento
*/
void keypad_callback(uint gpio, uint32_t event_mask) {
    // Leo el keypad
    char key = keypad_get_key();
    // Muestro tecla
    printf("Key pressed: %c\n", key);
}

/**
 * @brief Programa principal
*/
int main() {
    // Inicializo USB
    stdio_init_all();
    // Inicializo el keypad
    keypad_init(columns, rows, matrix);
    // Configuro callback para interrupcion
    keypad_irq_enable(true, keypad_callback);
    
    while (true);
}

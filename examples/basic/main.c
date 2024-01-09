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
 * @brief Programa principal
*/
int main() {
    // Inicializo USB
    stdio_init_all();
    // Inicializo el keypad
    keypad_init(columns, rows, matrix);
    
    while (true) {
        // Leo la tecla presionada
        char key = keypad_get_key();
        // Muestro en consola
        printf("Key pressed: %c\n", key);
        // Demora
        sleep_ms(250);
    }
}

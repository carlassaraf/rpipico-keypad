# basic

Ejemplo basico que configura el keypad y lo lee constantemente en un bucle. Hace uso del printf por USB para poder ver en consola la tecla presionada por lo que es necesario hacer modificaciones en la configuracion del proyecto como se describe en el [platformio.ini](platformio.ini).

## Conexiones

![pinout](https://circuitdigest.com/sites/default/files/inlineimages/u5/Membrane-Keyboard-Pinout.jpg)

Siguiendo la imagen de arriba las conexiones son:

| Raspberry Pi Pico | Keypad |
| --- | --- |
| GPIO16 | R1 |
| GPIO17 | R2 |
| GPIO18 | R3 |
| GPIO19 | R4 |
| GPIO20 | C1 |
| GPIO21 | C2 |
| GPIO22 | C3 |
| GPIO26 | C4 |

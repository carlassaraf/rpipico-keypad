# rpipico-keypad

## Raspberry Pi Pico VS Code Extension

Para agregar esta biblioteca, solamente hay que copiarla con el nombre `keypad` en el directorio del proyecto y agregar en el `CMakeLists.txt` del proyecto lo siguiente:

```cmake
add_subdirectory(keypad)
target_link_libraries(${PROJECT_NAME} keypad)
```

## PlatformIO

Biblioteca para usar un keypad con la Raspberry Pi Pico y su SDK. Puede ser usada descargandola e incluyendola en un proyecto de forma particular o puede incluirse en PlatformIO modificando el `platformio.ini` con lo siguiente:

```
lib_deps = https://github.com/carlassaraf/rpipico-keypad.git
```

## Ejemplos

Los ejemplos que hay en el repositorio son:

| Ejemplo | Descripcion |
| --- | --- |
| [basic](examples/basic/) | Ejemplo basico lee constantemente el keypad |
| [irq](examples/irq/) | Ejemplo basico con interrupcion |

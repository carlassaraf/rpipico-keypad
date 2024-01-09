# rpipico-keypad
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

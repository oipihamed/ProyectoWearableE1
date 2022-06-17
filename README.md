# Llavero Inteligente

## V I S I Ó N 
Crear un producto Wearable que ofrezca al usuario opciones como la localización mediante alertas de sonido, Botón de pánico, Medición de Pulso Cardíaco y Mostrar la Temperatura ambiente. Todo lo anterior con el monitoreo mediante la aplicación Móvil.


## É P I C A S

1. **Localización del llavero:** Envío de alertas de sonido mediante la aplicación móvil, lo que permite al usuario al usuario localizar el llavero si está en ubicaciones.
    - Codificación del módulo de localización por alertas
    - Armar circuito para módulo de localización
    - Programación de módulo de localización (Aplicación)
    - Armado de carcasa provisional de llavero
    - Pruebas de módulo de localización
2. **Botón de pánico:** El botón de pánico permite al usuario enviar alertas de ayuda a una persona de confianza, en casos de emergencia.
    - Integración de botón de pánico al circuito de localización
    - Codificación de módulo Botón de pánico
    - Programación de módulo Botón de pánico (Aplicación)
    - Pruebas de Módulo Botón de Pánico
3. **Pulso:** Medir el pulso cardíaco y mostrarlo en la aplicación.
    - Integración módulo Pulso Cardiaco
    - Codificación módulo pulso cardíaco
    - Programación de módulo pulso cardiaco (Aplicación)
    - Pruebas de Módulo pulso cardiaco
4. **Temperatura:** Tomar la temperatura ambiente para mostrarla en la aplicación 
    - Integración módulo Temperatura ambiental
    - Codificación módulo Temperatura ambiental
    - Programación de módulo Temperatura ambiental (Aplicación)
    - Construcción de final carcasa del Llavero
    - Pruebas de Módulo Temperatura ambiental


## M A T E R I A L E S 

| Componente | Descripción | Imagen | Cantidad |
| --- | --- | --- | --- |
| ESP32 Cam| Pequeño módulo que incluye el procesador IOT ESP32-S con WIFI y Bluetooth incorporado, una cámara OV2640 de 2MP y algunos pines adicionales para conectar cualquier dispositivo como sensores o actuadores.|![descarga (2)](https://user-images.githubusercontent.com/72764702/173450333-8f7f206c-6882-4c1a-9f74-1b39394adc5a.jpg) | 1|
| Sensor DHT11 | sensor que mide humedad y temperatura. Es ideal para sistemas de medición climatológicos o para controles de temperatura y humedad. Este sensor además incluye un transductor interno de temperatura del tipo NTC. |![download](https://user-images.githubusercontent.com/72764702/173450465-1c0f6742-a695-41de-90b3-51ab577a5671.jpg) | 1|
| Buzzer | Un buzzer o zumbador es un dispositivo que es capaz de enviar avisos a través del sonido. Puede ser mecánico, electromecánico o piezoeléctrico. |![images](https://user-images.githubusercontent.com/72764702/173450570-0863472a-7034-449e-bc82-0ac7a63fb323.jpg) | 1 |
| Sensor de pulso | Este módulo de detección combina un fototransistor y un LED que, cuando se coloca un dedo o el lóbulo de la oreja, proporciona una lectura. |![download](https://user-images.githubusercontent.com/72764702/173450779-7e753fac-a0cc-45da-8efc-7d97714dbcf3.jpg) | 1 |
| Pulsador | Un botón pulsador es básicamente un interruptor que podemos accionar pulsando sobre él, mientras lo mantenemos pulsado el interruptor estará cerrado, generando continuidad; cuando lo soltemos, el interruptor se abrirá. | ![download](https://user-images.githubusercontent.com/72764702/173450937-94501c69-f639-4264-8257-49dc8c230aa8.jpg) | 1 |


## D I A G R A M A 

![Diagrama](https://user-images.githubusercontent.com/72764702/174343938-e5f7c55a-2cdc-4340-a01b-ca30867d6142.png)


## T A B L E R O

![IMG_20220608_165415 1](https://user-images.githubusercontent.com/72764702/173451954-607272b4-cee6-4432-9c51-effce2f5281c.jpg)

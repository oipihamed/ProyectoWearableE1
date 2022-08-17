# **LLAVERO INTELIGENTE**
## O B J E T I V O
Crear un producto Wearable que ofrezca al usuario opciones como la localización mediante alertas de sonido, Botón de pánico que enviará un mensaje de alerta e imagens a ala aplicación y Mostrar la Temperatura ambiente. Todo lo anterior con el monitoreo mediante la aplicación Móvil.
##
##
## **V I S I Ó N** 
Ofrecer productos que destaquen por su facilidad de uso, potencia y capacidad de adaptación a múltiples actividades y a los nuevos entornos operativos, apostando por ofrecer el mejor servicio orientado al cliente.
## 
## 
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
3. **Fotografía:** Envío de imágenes cada dos segundos a la aplicación Móvil.
    - Integración módulo Fotografía
    - Codificación módulo Fotografía
    - Programación de módulo Fotografía (Aplicación)
    - Pruebas de Módulo Fotografía
4. **Temperatura:** Tomar la temperatura ambiente para mostrarla en la aplicación 
    - Integración módulo Temperatura ambiental
    - Codificación módulo Temperatura ambiental
    - Programación de módulo Temperatura ambiental (Aplicación)
    - Construcción de final carcasa del Llavero
    - Pruebas de Módulo Temperatura ambiental
## 
##  
## **S O F T W A R E** 
#### **Librerías**
- DHT.h
- FirebaseESP32.h
- Wifi.h
- Tone 32.hpp
- PulseSensorPlayground.h
- ESP_Mail_Client.h
- esp_camera.h
- Arduino.h
- soc/soc.h
- driver/rtc_io.h
 - SPIFFS.h
- FS.h
- Firebase_ESP_Client.h
- ddons/TokenHelper.h
## 
## 
## H A R D W A R E

| Componente | Descripción | Imagen | Cantidad |
| --- | --- | --- | --- |
| ESP32 Cam| Pequeño módulo que incluye el procesador IOT ESP32-S con WIFI y Bluetooth incorporado, una cámara OV2640 de 2MP y algunos pines adicionales para conectar cualquier dispositivo como sensores o actuadores.|![descarga (2)](https://user-images.githubusercontent.com/72764702/173450333-8f7f206c-6882-4c1a-9f74-1b39394adc5a.jpg) | 1|
| Sensor DHT11 | sensor que mide humedad y temperatura. Es ideal para sistemas de medición climatológicos o para controles de temperatura y humedad. Este sensor además incluye un transductor interno de temperatura del tipo NTC. |![download](https://user-images.githubusercontent.com/72764702/173450465-1c0f6742-a695-41de-90b3-51ab577a5671.jpg) | 1|
| Buzzer | Un buzzer o zumbador es un dispositivo que es capaz de enviar avisos a través del sonido. Puede ser mecánico, electromecánico o piezoeléctrico. |![images](https://user-images.githubusercontent.com/72764702/173450570-0863472a-7034-449e-bc82-0ac7a63fb323.jpg) | 1 |
| Pulsador | Un botón pulsador es básicamente un interruptor que podemos accionar pulsando sobre él, mientras lo mantenemos pulsado el interruptor estará cerrado, generando continuidad; cuando lo soltemos, el interruptor se abrirá. | ![download](https://user-images.githubusercontent.com/72764702/173450937-94501c69-f639-4264-8257-49dc8c230aa8.jpg) | 1 |
| Batería |Es un tipo de batería recargable muy habitual en el mundo de los multirrotores.  Nacen como una opción aceptable a la utilización de combustibles para realizar vuelos.|![download](https://user-images.githubusercontent.com/72764702/185250412-ed60667c-7de5-4dce-b230-b50335bd831b.jpg) | 1 |

## 
## 
## A R Q U I T E C T U R A
![Diagrama en blanco](https://user-images.githubusercontent.com/72764702/185230111-912d6d84-d455-4198-b73f-768f967fae4a.png)

## 
## 
## T A B L E R O

Se desarrolla el proyecto bajo la metodología Scrum, para lo cual se lleva a cabo un registro de actividades en Sprint Board en la Herramienta Trello
![image](https://user-images.githubusercontent.com/72764702/185231233-62bf8cd1-1e9d-4c8d-b1ad-903e60b4873b.png)
## 
## 
## D I S E Ñ O -  P R O T O T I P O
Se realizó una carcasa provisonal de madera que en el último Sprint fue sustituida por una de menor tamaño y un materal ligero

![Screenshot_2022-08-14-18-18-34-871_com picsart studio](https://user-images.githubusercontent.com/72764702/184584231-5d61ea5c-aa7c-46c1-80ff-2db669b9c24c.jpg)
## 
## 
### Diseño 3D
El diseño de la carcasa se llevó a cabo por medio de un módelo 3D digital, para posteriormente llevar a cabo la impresión de la misma

![Screenshot_2022-08-15-01-00-19-485_com picsart studio](https://user-images.githubusercontent.com/72764702/184584618-ed27ce52-6da4-4747-afeb-fb7a913d82fd.jpg)
## 
## 
## **C I R C U I T O**
![image](https://user-images.githubusercontent.com/72764702/185231798-1db2751c-93d1-498b-9a00-5879407f9db4.png)
##
##
## R E S U L T A D O S 
El proyecto wearable tiene como resultado un llavero inteligente que permite al usuario Medir su pulso cardiaco, Enviar alerta de panico a algun familiar, localización del mismo y por último ver la temperatura y húmedad en el ambiente; todo esto mediante su integración y comunicación con la aplicación móvil.

### Producto Wearable
![Screenshot_2022-08-14-17-44-26-074_com picsart studio](https://user-images.githubusercontent.com/72764702/184584582-c33dd962-897e-4c09-8a6a-dbc2d17f6392.jpg)

# NodeMCU ESP8266 + MAX7219 + DHT11

La idea de este proyecto fue crear un reloj muy simple que me sirva para uno de mis hobbies que es la radioafición.

La necesidad era crear un reloj que de una hora exacta y adicionalmente que me de datos meteorologicos como temperatura y humedad.

El hadware utilizado fue:
* Node MCU ESP8266
* Sensor DHT11
* 5 modulos display led de 8x8 MAX7219

El codigo fue un "mersh" de varias cosas encontradas por internet.

El sensor y los modulos se conectan a 3vcc.
Conexiones:
* MAX7219 DIN: D7
* MAX7219 CS: D8
* MAX7219 CLK; D5
* DHT1 DATA(el del medio): D1

Particularmente el sensor DHT11 no me gusta la exactitud de la temperatura, preferiria un BMP180 pero no tiene humedad (si tiene presión admosferica).

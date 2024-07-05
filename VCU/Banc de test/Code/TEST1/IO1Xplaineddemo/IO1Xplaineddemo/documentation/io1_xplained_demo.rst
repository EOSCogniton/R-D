=================
IO1 Xplained Demo
=================

IO1 Xplained pro board must be connected to EXT1 extension header for the
example to work.

The example application uses the USART driver to communicate with the console
via EDBG Virtual COM Port.

This example reads information about current temperature and light level and
sends it to the console every second. The USART driver is used to communicate with
the console; the ADC driver is used to read data from the light sensor; the I2C
Master driver is used to read data from the temperature sensor.

Drivers
-------
* Synchronous ADC
* Synchronous USART
* Synchronous I2C Master
* Delay
* GPIO

Default interface settings
--------------------------
* USART

  * No parity
  * 8-bit character size
  * 1 stop bit
  * 9600 baud-rate

* ADC

  * 1.0V reference voltage
  * 12-bit resolution

* I2C Master

  * 100000 baud-rate
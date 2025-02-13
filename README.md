# SCA3300

Arduino Library for `Murata SCA3300` Accelerometer

*Version 1.0.0 - Dezember 15, 2021*

The `Murata SCA3300` accelerometer sensor is a `3.3 volt` device used to measure acceleration in three axes simultaneously.

[Datasheet](https://www.murata.com/-/media/webrenewal/products/sensor/pdf/datasheet/datasheet_sca3300-d01.ashx?la=en-us)

## Notes

1. The `SCA3300` accelerometer will require a bidrectional level shifter to interface the `SPI` pins to `5 volt` devices, such as the Arduino Uno.
2. A pull-up resistor may be required on the Chip/Slave Select line of the `SCA3300`. A typical resistor value of `4.7k ohms` should connect this pin to `+3.3 volts`.
3. Be sure to connect the `SCA3300 DVIO` pin to `+3.3 volts` as well. This pin powers the digital pins.

## Wiring

For an Arduino Uno, the default `SPI` pins are as follows:

- `SCK - Digital Pin 13`
- `SDO - Digital Pin 12 (MISO)`
- `SDI - Digital Pin 11 (MOSI)`
- `CS - Digital Pin 10 (SS)`

For a `SAMD`-type Arduino, such as the Sparkfun Redboard Turbo or Arduino Zero, the default `SPI` pins are only available on the `ICSP` connector:

- `Pin 22 (MISO)`
- `Pin 23 (MOSI)`
- `Pin 24 (SCK)`
- `Chip/Slave Select` uses digital `Pin 10` as the default.

======================================

## Basic `SCA3300` Library Functions

`begin()`  
This initializes the library and the `SPI` chip, and by default assigns the `SPI` Chip Select Pin to Digital `Pin 10`.

`begin(csPinNum)`  
This variation allows you to choose a different pin as the `SPI` Chip Select Pin. Replace 'csPinNum' with your Pin number.

`begin(altSpiPort, csPinNum)`  
This allows using an alternate SPI port definition for communication to the SCL3300. Please see Example9_AlternateSPI.ino

`isConnected()`  
Returns 'true' if the sensor is still responding as expected, and able to provide valid data. It does not collect a data set from the sensor.

`available()`  
Reads the raw SCL3300 sensor data as a group so that all the data is consistent. Call this first before using the functions below. Starting with Version 3.0.0, this call should be the conditional in an 'if' statement, and an 'else' clause included to call reset() when available() returns false. (See the example sketches in the library.)

`getCalculatedAccelerometerX()`  
Returns a double float of the accelerometer value in units of 'g' for the X direction.

`getCalculatedAccelerometerY()`  
Returns a double float of the accelerometer value in units of 'g' for the Y direction.

`getCalculatedAccelerometerZ()`  
Returns a double float of the accelerometer value in units of 'g' for the Z direction.

`getTemperatureCelsius()`  
Returns a double float of the temperature in Celsius.

`getTemperatureFarenheit()`  
Returns a double float of the temperature in Farenheit.

## Utility Functions available

`reset()`  
Does a software reset of the `SCL3300` sensor.

`getSerialNumber()`  
Returns a long integer of the device Serial Number set by the manufacturer.

`powerDownMode()`  
Puts the sensor in a power down mode to reduce power usage.

`WakeMeUp()`  
Revives sensor from being powered down, so that it can start to generate sensor data.

`setMode(modeNum)`  
Sets the sensor mode to the number provided as modeNum. The default mode is '4'. Valid values are 1, 2, 3, and 4.

`setFastReadMode()`  
Using Fast Read Mode in the library works by keeping the SPI connection continuously open. This may or may not affect the behavior of other hardware interactions, depending on the sketch design. Fast Read Mode is considered an advanced use case, and not recommended for the beginner.

`stopFastReadMode()`  
This stops the Fast Read Mode in the library by closing the SPI connection that was open, and doing a reset of the SCL3300. This may or may not affect the behavior of other hardware interactions, depending on the sketch design. Fast Read Mode is considered an advanced use case, and not recommended for the beginner.

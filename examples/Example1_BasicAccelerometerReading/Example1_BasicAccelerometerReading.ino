/* Read Accelerometer data from Murata SCA3300 Accelerometer
 * Version 1.0.0 - Dezember 15, 2021
 * Example1_BasicAccelerometerReading
*/

#include <SPI.h>
#include <SCA3300.h>

SCA3300 accelerometer;
//Default SPI chip/slave select pin is D10

// Need the following define for SAMD processors
#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif

void setup() {
  Serial.begin(9600);
  delay(2000); //SAMD boards may need a long time to init SerialUSB
  Serial.println("Reading basic Accelerometer values from SCA3300 Accelerometer");

  if (accelerometer.begin() == false) {
    Serial.println("Murata SCA3300 accelerometer not connected.");
    while(1); //Freeze
  }
}

void loop() {
  if (accelerometer.available()) { //Get next block of data from sensor
    Serial.print("X Accelerometer: ");
    Serial.print(accelerometer.getCalculatedAccelerometerX());
    Serial.print("\t");
    Serial.print("Y Accelerometer: ");
    Serial.print(accelerometer.getCalculatedAccelerometerY());
    Serial.print("\t");
    Serial.print("Z Accelerometer: ");
    Serial.println(accelerometer.getCalculatedAccelerometerZ());
    delay(250); //Allow a little time to see the output
  } else accelerometer.reset();
}

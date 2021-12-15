/* Read Raw sensor data from Murata SCA3300 Accelerometer
 * Version 1.0.0 - Dezember 15, 2021
 * Example3_RawDataReading
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
  Serial.println("Reading Raw register values from SCA3300 Accelerometer");

  if (accelerometer.begin() == false) {
    Serial.println("Murata SCA3300 accelerometer not connected.");
    while(1); //Freeze
  }
}

void loop() {
  if (accelerometer.isConnected()) Serial.println("Accelerometer is still alive...");
  else Serial.println("Accelerometer error detected...");
  
  if (accelerometer.available()) { //Get next block of data from sensor
    Serial.print("Raw X Accel: ");
    Serial.print(accelerometer.scaData.AccX);
    Serial.print("\t");
    Serial.print("Y Accel: ");
    Serial.print(accelerometer.scaData.AccY);
    Serial.print("\t");
    Serial.print("Z Accel: ");
    Serial.println(accelerometer.scaData.AccZ);
    Serial.print("SCA3300 STO register: ");
    Serial.print((accelerometer.scaData.STO >> 8) & 0xff, HEX);
    Serial.print("\t");
    Serial.print("WHOAMI register: ");
    Serial.println(accelerometer.scaData.WHOAMI, HEX);
    Serial.print("Raw Temperature: ");
    Serial.println(accelerometer.scaData.TEMP);
    Serial.print("Serial Number Register: ");
    Serial.print(accelerometer.getSerialNumber());
    Serial.print("B33");
    Serial.print("\t");
    Serial.print("SL3300 Status Summary Register: ");
    Serial.println(accelerometer.scaData.StatusSum, HEX);
    delay(1000);
  } else accelerometer.reset();
}

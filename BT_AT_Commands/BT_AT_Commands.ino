/*
 This code is for setting up the HM-19 with a new name for the bluetooth device and Changing parameter of the bluetooth module.
 Since Arduino UNO only has one hardware serial port, we need to create a software serial port on other pins. 
 The serial monitor needs pins 0 and 1 of the Arduino to communicate to the computer through the USB connection, so we can't use those same pins to communicate 
 to the HM-19 at the same time. We will implement a software serial port to set up a second serial port on the HM-19.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)
 */
#include <SoftwareSerial.h>

SoftwareSerial BT(2,3); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. 
  }


  Serial.println("ENTER AT COMMANDS");

  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
 
}

void loop() 
{
  if (BT.available())
    Serial.write(BT.read());
  if (Serial.available())
    BT.write(Serial.read());
}

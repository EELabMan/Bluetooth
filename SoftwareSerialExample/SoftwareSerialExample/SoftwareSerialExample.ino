/*
 This code is for setting up the HC-05 with a new name for the bluetooth device and setting a new password.
 Since Arduino UNO only has one hardware serial port, we need to create a software serial port on other pins. 
 The serial monitor needs pins 1 and 2 of the Arduino to communicate to the computer, so we can't use those same pins to communicate 
 to the HC-05 at the same time. We will implement a software serial port to set up a second serial port on the HC-05.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 */
#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. 
  }


  Serial.println("ENTER AT COMMANDS");

  // set the data rate for the SoftwareSerial port
  BT.begin(38400);
 
}

void loop() 
{
  if (BT.available())
    Serial.write(BT.read());
  if (Serial.available())
    BT.write(Serial.read());
}

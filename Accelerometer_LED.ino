/* Accelerometer block of Phone sensor module allows you to access your smartphone's accelerometer values.
   NOTE:
   1)For Arduino Mega Connect Bluetooth on Serial3 pins.
   2)For Arduino Uno/Nano library uses SoftwareSerial,hence pin 2 and pin 3 are used
   as RX and TX pins respectively on SoftwareSerial.Hence with arduino Uno
   follow below connections for bluetooth.
   UNO  - BLUETOOTH
   2    - TX
   3    - RX

   3)For Uno/Nano keep bluetooth Baudrate below 38400.
  
   You can reduce the size of library compiled by enabling only those modules that you want
   to use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/phone-sensors-module/
*/

#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#include <Dabble.h>
  const int green = 5;
  const int red = 6;
  const int yellow = 9;
  const int blue = 11;
  
void setup() {
  Serial.begin(9600);     // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);    //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  print_Accelerometer_data();
}

void print_Accelerometer_data()
{
  Serial.print("X_axis: ");
  Serial.print(Sensor.getAccelerometerXaxis(), 4);
  Serial.print('\t');
  Serial.print("Y_axis: ");
  Serial.print(Sensor.getAccelerometerYaxis(), 4);
  Serial.print('\t');
  Serial.print("Z_axis: ");
  Serial.println(Sensor.getAccelerometerZaxis(), 4);
  Serial.println();

  if (Sensor.getAccelerometerXaxis() < 2 )
  {
    digitalWrite(blue, HIGH);
  }

    if (Sensor.getAccelerometerXaxis() > 2)
  {
    digitalWrite(blue, LOW);
  }

    if (Sensor.getAccelerometerYaxis() <2)
  {
    digitalWrite(green, HIGH);
  }

    if (Sensor.getAccelerometerYaxis() > 2)
  {
    digitalWrite(green, LOW);
  }

    if (Sensor.getAccelerometerZaxis() <2)
  {
    digitalWrite(yellow, HIGH);
  }

    if (Sensor.getAccelerometerZaxis() > 2)
  {
    digitalWrite(yellow, LOW);
  }

      if ((Sensor.getAccelerometerXaxis() < 2) && (Sensor.getAccelerometerYaxis() < 2))
  {
    digitalWrite(red, HIGH);
  }

    if ((Sensor.getAccelerometerXaxis() < 2) && (Sensor.getAccelerometerYaxis() > 2))
  {
    digitalWrite(red, LOW);
  }
}

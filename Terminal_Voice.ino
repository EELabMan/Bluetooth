/*
   Terminal Module is like a chat box. It allows you to send and receive commands between your
   board and smartphone.
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

   Explore more on: https://thestempedia.com/docs/dabble/terminal-module/
*/

#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
#include <Dabble.h>
const int green = 5;
const int red = 6;
const int yellow = 9;
const int blue = 11;
String Serialdata = "";
String BTdata ="";
bool dataflag = 0;
void setup() {
  Serial.begin(9600);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);  //Change this baudrate as per your bluetooth baudrate. Connect bluetooth on digital pin 2(RX) and 3(TX) for Uno/Nano and on Serial3 pins for Mega.
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.      //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  while (Terminal.available()!= 0)
  {
    Serialdata = String(Serialdata + char(Terminal.read()));
    dataflag = 1;
  }
  delay(20);
  if (dataflag == 1)
  {
  if(Serialdata == ("turn on the blue LED"))
   {
    digitalWrite(blue, HIGH);
    delay(2);
   }
  if(Serialdata == ("turn off the blue LED"))
   {
    digitalWrite(blue, LOW);
    delay(2);
   }

   if(Serialdata == ("turn on the green LED"))
   {
    digitalWrite(green, HIGH);
    delay(2);
   }
  if(Serialdata == ("turn off the green LED"))
   {
    digitalWrite(green, LOW);
    delay(2);
   }

   if(Serialdata == ("turn on the yellow LED"))
   {
    digitalWrite(yellow, HIGH);
    delay(2);
   }
  if(Serialdata == ("turn off the yellow LED"))
   {
    digitalWrite(yellow, LOW);
    delay(2);
   }

   if(Serialdata == ("turn on the red LED"))
   {
    digitalWrite(red, HIGH);
    delay(2);
   }
  if(Serialdata == ("turn off the red LED"))
   {
    digitalWrite(red, LOW);
    delay(2);
   }
  if(Serialdata == ("all on"))
   {
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    delay(2);
   }

  if(Serialdata == ("all off"))
   {
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    delay(2);
   }
   
   Serial.println(Serialdata);
    Serialdata = "";
    dataflag = 0;
  
  }

   if(Serial.available())
  {
    while (Serial.available() != 0)
    {
      BTdata = String(BTdata + char(Serial.read()));
    }
  
  Terminal.println(BTdata);
  BTdata = ""; 
  }
  
}

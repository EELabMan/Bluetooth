/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
const int green = 5;
const int red = 6;
const int yellow = 9;
const int blue = 11;

void setup() {
  Serial.begin(250000);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    digitalWrite(blue, HIGH);
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    digitalWrite(blue, LOW);
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    digitalWrite(green, HIGH);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    digitalWrite(green, LOW);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    digitalWrite(red, HIGH);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    digitalWrite(red, LOW);
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
    digitalWrite(yellow, LOW);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
    digitalWrite(yellow, HIGH);
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}

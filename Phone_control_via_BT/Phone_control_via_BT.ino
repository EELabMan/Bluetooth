/*********************************************************
* MJRoBot DIGI_Ana_Voice Control over BT
* Project with digital and Analog variables
* Marcelo Rovai - 29jan16
* Tige Kelley - Modified for UTA EE Lab workshops 11-4-2021 
**********************************************************/

#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); //TX, RX respetively
String device;

const int dev1 = 3; //PWM
const int dev2 = 5; //PWM
const int dev3 = 6; //PWM
const int dev4 = 9; //PWM

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  
  pinMode(dev1, OUTPUT);
  pinMode(dev2, OUTPUT);
  pinMode(dev3, OUTPUT);
  pinMode(dev4, OUTPUT);
}

void loop() 
{
  while (BT.available())   //Check if there is an available byte to read
  {
    delay(10); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    device += c; //build the string.
  }  
  if (device.length() > 0) 
  {
    Serial.println(device); 
    // Button control:
          if (device == "dev1on") {digitalWrite(dev1, HIGH);}
     else if (device == "dev1off") {digitalWrite(dev1, LOW);}
     else if (device == "dev2on") {digitalWrite(dev2, HIGH);}
     else if (device == "dev2off") {digitalWrite(dev2, LOW);}
     else if (device == "dev3on") {digitalWrite(dev3, HIGH);}
     else if (device == "dev3off") {digitalWrite(dev3, LOW);}
     else if (device == "dev4on") {digitalWrite(dev4, HIGH);}
     else if (device == "dev4off") {digitalWrite(dev4, LOW);}
     
     // Voice control:
     else if (device == "ligar um" || device == "Ligar 1") {digitalWrite(dev1, HIGH);}
     else if (device == "desligar um" || device == "desligar 1") {digitalWrite(dev1, LOW);}
     else if (device == "ligar som" || device == "Ligar som") {digitalWrite(dev2, HIGH);}
     else if (device == "desligar som" || device == "Desligar som") {digitalWrite(dev2, LOW);}
     else if (device == "ligar TV" || device == "Ligar TV") {digitalWrite(dev3, HIGH);}
     else if (device == "desligar TV" || device == "Desligar TV") {digitalWrite(dev3, LOW);}
     else if (device == "ligar quarto" || device == "Ligar quarto") {digitalWrite(dev4, HIGH);}
     else if (device == "desligar quarto" || device == "Desligar quarto") {digitalWrite(dev4, LOW);}
     
     // Slider control:
     char colour = device[0];  
     int value = device[2];  
     Serial.print("    ");  
     Serial.println(value);  
     if ( colour == 'r')  
     {  
       analogWrite(dev1, value);        // use value to set PWM for LED brightness  
     }  
     if ( colour == 'y')  
     {  
       analogWrite(dev2, value);        // use value to set PWM for LED brightness  
     } 
     if ( colour == 'g')  
     {  
       analogWrite(dev3, value);        // use value to set PWM for LED brightness  
     } 
     if ( colour == 'b')  
     {  
       analogWrite(dev4, value);   
     }
     device="";  //Reset the variable
  } 
}

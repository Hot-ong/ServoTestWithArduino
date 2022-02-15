#include <Arduino.h>
#line 1 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
#line 1 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
void setup();
#line 7 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
void loop();
#line 1 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
}


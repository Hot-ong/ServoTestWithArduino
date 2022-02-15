# 1 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, 0x1);
}

void loop()
{
  digitalWrite(13, 0x1); // turn the LED on (HIGH is the voltage level)
  delay(500); // wait for a second
  digitalWrite(13, 0x0); // turn the LED off by making the voltage LOW
  delay(500);
}

#include<Servo.h>
const int button_zeroset = 2;
const int button_1st = 3;
const int button_2nd = 4;
const int button_3rd = 5;
const int button_4th = 6;
const int servo_1st = 9;
const int servo_2nd = 10;
const int servo_3rd = 11;
const int centre = 89;
const int leftDrop = 150;
const int rightDrop = 30;

Servo servo1;
Servo servo2;
Servo servo3;
int servo1_value = 0;
int servo2_value = 0;
int servo3_value = 0;

int testVar = 0;

bool btn0_sts = false;
bool btn1_sts = false;
bool btn2_sts = false;
bool btn3_sts = false;
bool btn4_sts = false;


void setup() {
  pinMode(button_zeroset, INPUT_PULLUP); // 위치 초기화
  pinMode(button_1st, INPUT_PULLUP);    // 1번 위치
  pinMode(button_2nd, INPUT_PULLUP);    // 2번 위치
  pinMode(button_3rd, INPUT_PULLUP);    // 3번 위치
  pinMode(button_4th, INPUT_PULLUP);    // 4번 위치
  servo1.attach(servo_1st); // 1번 서보모터
  servo2.attach(servo_2nd); // 2번 서보모터
  servo3.attach(servo_3rd); // 3번 서보모터
  servo1.write(centre);
  servo2.write(centre);
  servo3.write(centre);
}

void loop() {
    if (digitalRead(button_zeroset) == 0)  {
        if(!(btn1_sts||btn2_sts||btn3_sts||btn4_sts))    btn0_sts = true;
        delay(10);
    }

    if (digitalRead(button_1st) == 0)  {
        if(!(btn0_sts||btn2_sts||btn3_sts||btn4_sts))    btn1_sts = true;
        delay(10);
    }

    if (digitalRead(button_2nd) == 0)  {
        if(!(btn1_sts||btn0_sts||btn3_sts||btn4_sts))    btn2_sts = true;
        delay(10);
    }

    if (digitalRead(button_3rd) == 0)  {
        if(!(btn1_sts||btn2_sts||btn0_sts||btn4_sts))    btn3_sts = true;
        delay(10);
    }

    if (digitalRead(button_4th) == 0)  {
        if(!(btn1_sts||btn2_sts||btn3_sts||btn0_sts))    btn4_sts = true;
        delay(10);
    }

    //

    if(btn0_sts)
    {
        position_zeroSet();
        delay(100);
        btn0_sts = false;
    }

    if(btn1_sts)
    {
        position_1st();
        delay(100);
        btn1_sts = false;
    }

    if(btn2_sts)
    {
        position_2nd();
        delay(100);
        btn2_sts = false;
    }

    if(btn3_sts)
    {
        position_3rd();
        delay(100);
        btn3_sts = false;
    }

    if(btn4_sts)
    {
        position_4th();
        delay(100);
        btn4_sts = false;
    }
}

void position_zeroSet(void)
{
    servo1.write(centre);
    servo2.write(centre);
    servo3.write(centre);
}

void position_1st(void)
{
    servo1.write(leftDrop);
    servo2.write(leftDrop);
    servo3.write(centre);
}

void position_2nd(void)
{
    servo1.write(leftDrop);
    servo2.write(rightDrop);
    servo3.write(centre);
}

void position_3rd(void)
{
    servo1.write(rightDrop);
    servo2.write(centre);
    servo3.write(leftDrop);
}

void position_4th(void)
{
    servo1.write(rightDrop);
    servo2.write(centre);
    servo3.write(rightDrop);
}
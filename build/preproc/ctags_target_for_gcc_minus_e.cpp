# 1 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
# 2 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino" 2





// Pin mapping
static const int button_zeroset = 2;
static const int button_1st = 3;
static const int button_2nd = 4;
static const int button_3rd = 5;
static const int button_4th = 6;
static const int servo_1st = 8;
static const int servo_2nd = 9;
static const int servo_3rd = 10;

// 각도값 (현재 1,2,3번 모터 각도 공통으로 사용)
static const int centre = 90; // 평형 상태의 각도
static const int leftDrop = 150; // 모터 정면에서 봤을 때 왼쪽으로 기울이는 각도. 값이 클수록 급경사. > centre. ≤ 180.
static const int rightDrop = 30; // 모터 정면에서 봤을 때 오른쪽으로 기울이는 각도. 값이 작을수록 급경사. < centre. ≥ 0

// 버튼에 따른 모터 동작 간격
static const int motor_term = 500; // millisecond 단위. 버튼 동작 간의 간격, 하부 모터 동작 후 상부 모터 동작 사이 간격




// 모터 위치 값 (숫자는 큰 의미 없음)
static const int pos_zero = 0;
static const int pos_1st = 1;
static const int pos_2nd = 2;
static const int pos_3rd = 3;
static const int pos_4th = 4;

// 모터 위치 값 정의
static const int pos_matrix[5][3] =
{ // {1번모터, 2번모터, 3번 모터}
    {centre, centre, centre}, // 위치 초기화 구성
    {leftDrop, leftDrop, centre}, // 1번 위치 구성
    {leftDrop, rightDrop, centre}, // 2번 위치 구성
    {rightDrop, centre, leftDrop}, // 3번 위치 구성
    {rightDrop, centre, rightDrop} // 4번 위치 구성
};

// 서보모터 객체 생성
Servo servo1;
Servo servo2;
Servo servo3;

bool btn0_sts = false; // 0번 버튼 프로세스 상태 flag
bool btn1_sts = false; // 1번 버튼 프로세스 상태 flag
bool btn2_sts = false; // 2번 버튼 프로세스 상태 flag
bool btn3_sts = false; // 3번 버튼 프로세스 상태 flag
bool btn4_sts = false; // 4번 버튼 프로세스 상태 flag

void setup() {
    pinMode(button_zeroset, 0x2); // 위치 초기화 버튼 핀 할당
    pinMode(button_1st, 0x2); // 1번 위치 버튼 핀 할당
    pinMode(button_2nd, 0x2); // 2번 위치 버튼 핀 할당
    pinMode(button_3rd, 0x2); // 3번 위치 버튼 핀 할당
    pinMode(button_4th, 0x2); // 4번 위치 버튼 핀 할당
    servo1.attach(servo_1st); // 1번 서보모터 핀 할당
    servo2.attach(servo_2nd); // 2번 서보모터 핀 할당
    servo3.attach(servo_3rd); // 3번 서보모터 핀 할당
    motors_position(pos_zero); // 위치 초기화
}

void loop() {
    if (digitalRead(button_zeroset) == 0) { // 위치 초기화 버튼 입력
        if(!(btn1_sts||btn2_sts||btn3_sts||btn4_sts)) btn0_sts = true;
    }

    if (digitalRead(button_1st) == 0) { // 1번 버튼 입력
        if(!(btn0_sts||btn2_sts||btn3_sts||btn4_sts)) btn1_sts = true;
    }

    if (digitalRead(button_2nd) == 0) { // 2번 버튼 입력
        if(!(btn1_sts||btn0_sts||btn3_sts||btn4_sts)) btn2_sts = true;
    }

    if (digitalRead(button_3rd) == 0) { // 3번 버튼 입력
        if(!(btn1_sts||btn2_sts||btn0_sts||btn4_sts)) btn3_sts = true;
    }

    if (digitalRead(button_4th) == 0) { // 4번 버튼 입력
        if(!(btn1_sts||btn2_sts||btn3_sts||btn0_sts)) btn4_sts = true;
    }


    if(btn0_sts) // 위치 초기화 버튼 동작 수행
    {
        motors_position(pos_zero);
        btn0_sts = false;
    }

    if(btn1_sts) // 1번 버튼 동작 수행
    {
        motors_position(pos_1st);
        btn1_sts = false;
    }

    if(btn2_sts) // 2번 버튼 동작 수행
    {
        motors_position(pos_2nd);
        btn2_sts = false;
    }

    if(btn3_sts) // 3번 버튼 동작 수행
    {
        motors_position(pos_3rd);
        btn3_sts = false;
    }

    if(btn4_sts) // 4번 버튼 동작 수행
    {
        motors_position(pos_4th);
        btn4_sts = false;
    }
}



void motors_position(int pos)
{
    if((pos < pos_zero) || (pos > pos_4th)) return;
# 188 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
    servo2.write(pos_matrix[pos][1]);
    servo3.write(pos_matrix[pos][2]);
    delay(motor_term);
    servo1.write(pos_matrix[pos][0]);
    delay(motor_term);

/*

    int a = servo1.read(), b = servo2.read(), c = servo3.read();

    int pres_pos[3] = {servo1.read(), servo2.read(), servo3.read()};

    int goal_pos[3] = {pos_matrix[pos][0], pos_matrix[pos][1], pos_matrix[pos][2]};

    bool d = false, e = false, f = false;

    bool pos_flag[3] = {false, false, false};



    for(int i = 0; i < 3; i++)

    {

        if(pres_pos[i] == goal_pos[i])  pos_flag[i];

    }



    while (!(pos_flag[1] && pos_flag[2]))

    {

        if(pres_pos[1] < goal_pos[1])   {

            pres_pos[1]++;

            servo2.write(pres_pos[1]);

        }

        else if (pres_pos[1] > goal_pos[1]) {

            pres_pos[1]--;

            servo2.write(pres_pos[1]);

        }

        else {

            if(pos_flag[1] != true)    pos_flag[1] = true;

        }



        if(pres_pos[2] < goal_pos[2])   {

            pres_pos[2]++;

            servo3.write(pres_pos[2]);

        }

        else if (pres_pos[2] > goal_pos[2]) {

            pres_pos[2]--;

            servo3.write(pres_pos[2]);

        }

        else {

            if(pos_flag[2] != true)    pos_flag[2] = true;

        }

    }

    delay(motor_term);

    while (!(pos_flag[0]))

    {

        if(pres_pos[0] < goal_pos[0])   {

            pres_pos[0]++;

            servo1.write(pres_pos[0]);

        }

        else if (pres_pos[0] > goal_pos[0]) {

            pres_pos[0]--;

            servo1.write(pres_pos[0]);

        }

        else {

            if(pos_flag[0] != true)    pos_flag[0] = true;

        }

    }

    delay(motor_term);

*/
# 250 "c:\\Users\\3dore\\Desktop\\HDW\\03_Workspace\\Arduino_Sources\\ServoTestWithArduino\\ServoTestWithArduino.ino"
}

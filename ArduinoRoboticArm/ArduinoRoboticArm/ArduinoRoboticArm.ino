/*
Name:		ArduinoRoboticArm.ino
Created:	2018-01-3
Author:	BetaMan(강민수,skymin0417@gmail.com)
*/

#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

#define SERVOS 5
#define LEARN_BTN digitalRead(11)
#define RUN_BTN digitalRead(12)

int servoNowArray[5] = { 0, };
int servoRecordArray[][5] = { 0, };
int recordLength = 0;

void setup() {
	Serial.begin(9600);
	servo1.attach(5);
	servo2.attach(6);
	servo3.attach(7);
	servo4.attach(8);
	servo5.attach(9);

	pinMode(11, INPUT);
	pinMode(12, INPUT);
}

void loop() {
	for (int i = 1; i < SERVOS + 1; i++) servoNowArray[i - 1] = map(analogRead(i), 150, 900, 0, 180);
	servo1.write(servoNowArray[0]);
	servo2.write(servoNowArray[1]);
	servo3.write(servoNowArray[2]);
	servo4.write(servoNowArray[3]);
	servo5.write(servoNowArray[4]);
	//  if(LEARN_BTN) {
	//    for(int i = 0; i < SERVO; i++) {
	//      servoRecordArray[recordLength][i] = servoNowArray[i];    
	//    }
	//    ++recordLength;
	//    while(LEARN_BTN) {}
	//  }
	//  if(RUN_BTN) {
	//    while(1) {
	//      for(int i = 0; i < recordLength+1; i++) {
	//        servo1.write(servoNowArray[i][0]);
	//        servo2.write(servoNowArray[i][1]);
	//        servo3.write(servoNowArray[i][2]);
	//        servo4.write(servoNowArray[i][3]);
	//        servo5.write(servoNowArray[i][4]);        
	//      }  
	//    }  
	//  }
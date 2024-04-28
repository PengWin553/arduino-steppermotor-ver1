#include<Stepper.h>
int btn1 = 7;
int btn2 = 6;
int btn1State;
int btn2State;
const int stepsPerRevolution = 2048;
const int stepsPerRevolution2 = 2048;
Stepper stepperName = Stepper(stepsPerRevolution,8,10,9,11);
Stepper stepperName2 = Stepper(stepsPerRevolution2,11,9,10,8);
void setup(){
  stepperName.setSpeed(5);
  stepperName2.setSpeed(5);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}
void loop(){
  btn1State = digitalRead(btn1);
  btn2State = digitalRead(btn2);
  while(btn1State == false){
    stepperName2.setSpeed(15);
    stepperName2.step(stepsPerRevolution2);
    delay(10);
    btn1State = true;
  }
  while(btn2State == false){
    stepperName.setSpeed(15);
    stepperName.step(stepsPerRevolution);
    delay(10);
    btn2State = true;
  }
}
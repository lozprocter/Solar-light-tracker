#include <Stepper.h>
int ldr1 = A0;
int ldr2 = A1;

const int stepsPerRevolution = 50;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
 
void setup() {
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  myStepper.setSpeed(100);

  Serial.begin(9600);
}

void loop() {
  int ldr_right=(map(analogRead(ldr1),0,1023,0,100));
  int ldr_left=(map(analogRead(ldr2),0,1023,0,100));
  ldr_right = (ldr_right*10)/50;
  ldr_left = (ldr_left*10)/50;

  Serial.println(ldr_right);
  Serial.println(ldr_left);
  Serial.println();

  if (ldr_right > ldr_left + 5){
    myStepper.step(stepsPerRevolution);
  }
  else if (ldr_left > ldr_right + 5){
    myStepper.step(-stepsPerRevolution);
  }
  
  delay(10);
}


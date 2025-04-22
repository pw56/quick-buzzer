#include "audio.h"

//ピンの割り当て
const char
  LED1 = ,
  LED2 = ,
  LED3 = ,
  LED4 = ,
  LED5 = ,
  LED6 = ;

//ピンモードの設定
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);

bool isAnswering;

void func1() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(LED1, HIGH);
    ringSound("answer");
  }
}

void func2() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(LED2, HIGH);
    ringSound("answer");
  }
}

void func3() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(LED3, HIGH);
    ringSound("answer");
  }
}

void func4() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(LED4, HIGH);
    ringSound("answer");
  }
}

void func5() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(LED5, HIGH);
    ringSound("answer");
  }
}

void func6() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(LED6, HIGH);
    ringSound("answer");
  }
}

void correct() {
  isAnswering = true;

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);

  ringSound("correct");
}

void incorrect() {
  isAnswering = true;

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);

  ringSound("incorrect");
}
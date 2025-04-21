#include "audio.h"

//ピンの割り当て
const char
  led1 = ,
  led2 = ,
  led3 = ,
  led4 = ,
  led5 = ,
  led6 = ;

//ピンモードの設定
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);

bool isAnswering;

void func1() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(led1, HIGH);
    ringSound("answer");
  }
}

void func2() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(led2, HIGH);
    ringSound("answer");
  }
}

void func3() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(led3, HIGH);
    ringSound("answer");
  }
}

void func4() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(led4, HIGH);
    ringSound("answer");
  }
}

void func5() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(led5, HIGH);
    ringSound("answer");
  }
}

void func6() {
  if(!isAnswering) {
    isAnswering = true;
    digitalWrite(led6, HIGH);
    ringSound("answer");
  }
}

void correct() {
  isAnswering = true;

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

  ringSound("correct");
}

void incorrect() {
  isAnswering = true;

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

  ringSound("incorrect");
}
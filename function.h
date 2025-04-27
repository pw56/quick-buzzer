#include "audio.h"

//ピンの割り当て
extern const char
  LED1,
  LED2,
  LED3,
  LED4,
  LED5,
  LED6;

bool isAnswering = false;

void func1() {
  isAnswering = true;
  digitalWrite(LED1, HIGH);
  ringSound("answer");
}

void func2() {
  isAnswering = true;
  digitalWrite(LED2, HIGH);
  ringSound("answer");
}

void func3() {
  isAnswering = true;
  digitalWrite(LED3, HIGH);
  ringSound("answer");
}

void func4() {
  isAnswering = true;
  digitalWrite(LED4, HIGH);
  ringSound("answer");
}

void func5() {
  isAnswering = true;
  digitalWrite(LED5, HIGH);
  ringSound("answer");
}

void func6() {
  isAnswering = true;
  digitalWrite(LED6, HIGH);
  ringSound("answer");
}

void correct() {
  isAnswering = false;

  //ここで全てのランプを消す
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);

  ringSound("correct");
}

void incorrect() {
  isAnswering = false;

  //ここで全てのランプを消す
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);

  ringSound("incorrect");
}
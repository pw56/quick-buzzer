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

void func1() {
  digitalWrite(led1, HIGH);
  ringSound("answer");
}

void func2() {
  digitalWrite(led2, HIGH);
  ringSound("answer");
}

void func3() {
  digitalWrite(led3, HIGH);
  ringSound("answer");
}

void func4() {
  digitalWrite(led4, HIGH);
  ringSound("answer");
}

void func5() {
  digitalWrite(led5, HIGH);
  ringSound("answer");
}

void func6() {
  digitalWrite(led6, HIGH);
  ringSound("answer");
}

void correct() {
  //ここで全てのランプを消す
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

  ringSound("correct");
}

void incorrect() {
  //ここで全てのランプを消す
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

  ringSound("incorrect");
}
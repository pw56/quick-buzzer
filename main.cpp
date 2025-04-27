#include "function.h"

//ピンの割り当て
const char
  BTN1 = ,
  BTN2 = ,
  BTN3 = ,
  BTN4 = ,
  BTN5 = ,
  BTN6 = ,
  CORR_BTN = ,
  INCORR_BTN = ,
  LED1 = ,
  LED2 = ,
  LED3 = ,
  LED4 = ,
  LED5 = ,
  LED6 = ,
  BUZZER = ;

extern bool isAnswering;

void setup() {
  //早押しボタン
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BTN5, INPUT);
  pinMode(BTN6, INPUT);
  pinMode(CORR_BTN, INPUT);
  pinMode(INCORR_BTN, INPUT);

  //LED
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  //ブザー
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if(isAnswering == false) {
    //早押しボタンのループ
    if(digitalRead(BTN1) == HIGH)
      func1();

    if(digitalRead(BTN2) == HIGH)
      func2();

    if(digitalRead(BTN3) == HIGH)
      func3();

    if(digitalRead(BTN4) == HIGH)
      func4();

    if(digitalRead(BTN5) == HIGH)
      func5();

    if(digitalRead(BTN6) == HIGH)
      func6();
  } else {
    if(digitalRead(CORR_BTN) == HIGH)
      correct();

    if(digitalRead(INCORR_BTN) == HIGH)
      incorrect();
  }
}
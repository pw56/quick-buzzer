#include "function.h"

//ピンの割り当て
const char
  btn1 = ,
  btn2 = ,
  btn3 = ,
  btn4 = ,
  btn5 = ,
  btn6 = ,
  corrBtn = ,
  incorrBtn = ;

void setup() {
  //ピンモードの設定
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(btn6, INPUT);
  pinMode(corrBtn, INPUT);
  pinMode(incorrBtn, INPUT);

  //早押しボタンの割り込み処理の登録
  attachInterrupt(btn1, func1, RISING);
  attachInterrupt(btn2, func2, RISING);
  attachInterrupt(btn3, func3, RISING);
  attachInterrupt(btn4, func4, RISING);
  attachInterrupt(btn5, func5, RISING);
  attachInterrupt(btn6, func6, RISING);

  //正解ボタン&不正解ボタンの割り込み処理の登録
  attachInterrupt(corrBtn, correct, RISING);
  attachInterrupt(incorrBtn, incorrect, RISING);
}

void loop() {
  ;
}
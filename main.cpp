#include "function.h"

//ピンの割り当て
const char
  BTN1 = ,
  BTN2 = ,
  BTN3 = ,
  BTN4 = ,
  BTN5 = ,
  BTN6 = ,
  corrBtn = ,
  incorrBtn = ;

void setup() {
  //ピンモードの設定
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);
  pinMode(BTN5, INPUT);
  pinMode(BTN6, INPUT);
  pinMode(corrBtn, INPUT);
  pinMode(incorrBtn, INPUT);

  //早押しボタンの割り込み処理の登録
  attachInterrupt(BTN1, func1, RISING);
  attachInterrupt(BTN2, func2, RISING);
  attachInterrupt(BTN3, func3, RISING);
  attachInterrupt(BTN4, func4, RISING);
  attachInterrupt(BTN5, func5, RISING);
  attachInterrupt(BTN6, func6, RISING);

  //正解ボタン&不正解ボタンの割り込み処理の登録
  attachInterrupt(corrBtn, correct, RISING);
  attachInterrupt(incorrBtn, incorrect, RISING);
}

void loop() {
  ;
}
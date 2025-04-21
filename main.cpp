#include "function.h"

const char
  btn1 = ,
  btn2 = ,
  btn3 = ,
  btn4 = ,
  btn5 = ,
  btn6 = ,
  btn = ,
  btn = ;

void setup() {
  pinMode();//ボタンのやつだけコメントつけながらやっといて

  //早押しボタンの割り込み処理の登録
  attachInterrupt(btn1, func1, RISING);

  //正解ボタン&不正解ボタンの割り込み処理の登録
  attachInterrupt(btn, , RISING);
  attachInterrupt(btn, , RISING);
}

void loop() {
  ;
}
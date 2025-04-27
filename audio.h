#include "answer_sound.h"
#include "correct_sound.h"
#include "incorrect_sound.h"

extern const unsigned char BUZZER;

const unsigned int SF = ;//サンプリング周波数
const unsigned float __SP = 1 / SF * 1000000;//サンプリング周期 = 1秒 ÷ サンプル周波数 × 1秒のマイクロ秒換算

void __play(byte* data) {
  for(unsigned int i, size = sizeof(*data); i < size; i++) {
    analogWrite(BUZZER, *data[i]);//この行に配列の音を鳴らすコードを書いて
    delayMicroseconds(__SP);
  }
  analogWrite(BUZZER, 0);
}

void ringSound(char type) {
  if(type == "answer") {
    __play(ANSWER_SOUND);
  }

  if(type == "correct") {
    __play(CORRECT_SOUND);
  }

  if(type == "incorrect") {
    __play(INCORRECT_SOUND);
  }
}
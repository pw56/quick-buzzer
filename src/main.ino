#include "audio_player.h"
#include "pushed.h"
#include "correct.h"
#include "incorrect.h"
#include <avr/pgmspace.h>
#include <Keyboard.h>

// ボタンピン
const int buttons[] = {22, 23, 24, 25, 26, 27};
const int correctBtn = 8;
const int incorrectBtn = 9;

// ランプピン
const int lamps[] = {2, 3, 4, 5, 6, 7};

// 状態管理
int answeredIndex = -1;
bool answering = false;

void setup() {
  // ボタン入力
  for (int i = 0; i < 6; i++) pinMode(buttons[i], INPUT_PULLUP);
  pinMode(correctBtn, INPUT_PULLUP);
  pinMode(incorrectBtn, INPUT_PULLUP);

  // ランプ出力
  for (int i = 0; i < 6; i++) pinMode(lamps[i], OUTPUT);

  // ブザー出力
  pinMode(BUZZER_PIN, OUTPUT);

  // Keyboard 初期化
  Keyboard.begin();
  
  // 起動時LED点滅 (内蔵LED: pin 13)
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

void loop() {
  // キーボード入力チェック
  sendKeyboardInput();
  
  // 回答中でないならボタン受付
  if (!answering) {
    for (int i = 0; i < 6; i++) {
      if (digitalRead(buttons[i]) == LOW) {
        answeredIndex = i;
        answering = true;
        playAudio(pushed, sizeof(pushed));
        digitalWrite(lamps[i], HIGH);
        break;
      }
    }
  } else {
    // 正解処理
    if (digitalRead(correctBtn) == LOW) {
      playAudio(correct, sizeof(correct));
      resetState();
    }

    // 不正解処理
    if (digitalRead(incorrectBtn) == LOW) {
      playAudio(incorrect, sizeof(incorrect));
      resetState();
    }
  }
}

// キーボード入力の送信
void sendKeyboardInput() {
  if (!answering) {
    for (int i = 0; i < 6; i++) {
      if (digitalRead(buttons[i]) == LOW) {
        Keyboard.write('k');  // 'K'キーを送信
        delay(100);  // デバウンス
        break;
      }
    }
  } else {
    if (digitalRead(correctBtn) == LOW || digitalRead(incorrectBtn) == LOW) {
      Keyboard.write('0');  // '0'キーを送信
      delay(100);  // デバウンス
    }
  }
}

void resetState() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(lamps[i], LOW);
  }
  answeredIndex = -1;
  answering = false;
}
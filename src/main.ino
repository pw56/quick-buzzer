#include <Arduino.h>
#include <avr/pgmspace.h>
#include "usbdrv.h"
#include "audio_player.h"

// 音声データヘッダファイルをインクルード
#include "../data/pushed.h"
#include "../data/correct.h"
#include "../data/incorrect.h"

// ボタン入力ピン
const uint8_t btnPins[8] = {A0, A1, A2, A3, A4, A5, A6, A7};
// ランプ出力ピン
const uint8_t ledPins[6] = {2, 3, 4, 5, 6, 7};

// AudioPlayerはaudio_player.cppでグローバルに定義済み
volatile bool usbEvent = false;

// USB HID Report: 8bit (キーコードのみ)
uchar usbReportBuffer[2] = {0, 0};

// 最初に押されたボタン番号 (-1:なし)
int8_t firstPress = -1;

void setup() {
  // ランプオフ、入力プルアップ
  for (auto p : ledPins) pinMode(p, OUTPUT), digitalWrite(p, LOW);
  for (auto p : btnPins) pinMode(p, INPUT_PULLUP);

  audioPlayer.begin();
  usbInit();
  sei();
}

void loop() {
  usbPoll();
  // 回答可能状態 (全LED消灯 && firstPress==-1)
  bool ready = (firstPress < 0);
  // ボタン読み取り
  if (ready) {
    for (uint8_t i = 0; i < 6; ++i) {
      if (digitalRead(btnPins[i]) == LOW) {
        firstPress = i;
        digitalWrite(ledPins[i], HIGH);
        audioPlayer.play(pushed_wav, pushed_wav_length); 
        sendKey('K');
        break;
      }
    }
  } else {
    // 正誤ボタン
    for (uint8_t i = 6; i < 8; ++i) {
      if (digitalRead(btnPins[i]) == LOW) {
        // 全LEDリセット
        for (auto p : ledPins) digitalWrite(p, LOW);
        if (i == 6) {
          audioPlayer.play(correct_wav, correct_wav_length);
        } else {
          audioPlayer.play(incorrect_wav, incorrect_wav_length);
        }
        sendKey('0');
        firstPress = -1;
        break;
      }
    }
  }
}

// USB キー送信
void sendKey(char c) {
  usbReportBuffer[1] = c;
  usbSetInterrupt(usbReportBuffer, sizeof(usbReportBuffer));
}

// V-USB 用コールバック (report の提供)
uchar usbFunctionSetup(uchar data[8]) {
  usbEvent = true;
  return 0;
}
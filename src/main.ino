#include "audio_player.h"
#include "pushed.h"
#include "correct.h"
#include "incorrect.h"
#include <avr/pgmspace.h>
#include <VUSB.h>

// ボタンピン
const int buttons[] = {A0, A1, A2, A3, A4, A5};
const int correctBtn = A6;
const int incorrectBtn = A7;

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

  // V-USB 初期化
  usbInit();
  usbDeviceDisconnect();
  delay(250);
  usbDeviceConnect();
}

void loop() {
  usbPoll();

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

// USB HID 機能: キーボードとして動作
USB_PUBLIC uchar usbFunctionSetup(uchar data[8]) {
  usbRequest_t *rq = (usbRequest_t *)data;

  if ((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS &&
      rq->bRequest == USBRQ_HID_GET_REPORT) {
    static uchar report[2] = {0, 0};  // 無入力

    // 入力状態を模倣
    if (!answering) {
      for (int i = 0; i < 6; i++) {
        if (digitalRead(buttons[i]) == LOW) {
          report[0] = 0;         // 修飾キーなし
          report[1] = 0x0E;      // 'K'キーのスキャンコード
          break;
        }
      }
    } else {
      if (digitalRead(correctBtn) == LOW || digitalRead(incorrectBtn) == LOW) {
        report[0] = 0;
        report[1] = 0x27; // '0'キーのスキャンコード
      }
    }

    usbMsgPtr = report;
    return sizeof(report);
  }

  return 0;
}

void resetState() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(lamps[i], LOW);
  }
  answeredIndex = -1;
  answering = false;
}
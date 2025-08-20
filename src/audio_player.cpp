#include "audio_player.h"
#include <Arduino.h>

// ブザーピン (pins.ymlに基づく)
#define BUZZER_PIN 10

// サンプリングレート (8kHz)
#define SAMPLE_RATE 8000

// グローバルインスタンス
AudioPlayer audioPlayer;

// Timer1 Compare Match A 割り込みハンドラ
ISR(TIMER1_COMPA_vect) {
  audioPlayer.handleTimer();
}

void AudioPlayer::begin() {
  // ブザーピンを出力に設定
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  
  // 初期化
  audioData = nullptr;
  audioLength = 0;
  audioIndex = 0;
  isPlaying = false;
  
  // Timer1を8kHzで動作するよう設定
  // Arduino Nano (16MHz) で 8kHz = 16MHz / (prescaler * (OCR1A + 1))
  // prescaler = 8, OCR1A = 249 → 16MHz / (8 * 250) = 8kHz
  
  noInterrupts();
  TCCR1A = 0;  // Timer1 制御レジスタA クリア
  TCCR1B = 0;  // Timer1 制御レジスタB クリア
  TCNT1 = 0;   // Timer1 カウンタ クリア
  
  // CTC モード (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);
  
  // プリスケーラ 8 設定
  TCCR1B |= (1 << CS11);
  
  // Compare値設定 (8kHz)
  OCR1A = 249;
  
  // Compare Match A 割り込み有効
  TIMSK1 |= (1 << OCIE1A);
  
  interrupts();
}

void AudioPlayer::play(const uint8_t *data, uint16_t length) {
  if (data == nullptr || length == 0) {
    return;
  }
  
  noInterrupts();
  audioData = data;
  audioLength = length;
  audioIndex = 0;
  isPlaying = true;
  interrupts();
}

bool AudioPlayer::isPlayingAudio() {
  return isPlaying;
}

void AudioPlayer::stop() {
  noInterrupts();
  isPlaying = false;
  audioData = nullptr;
  audioIndex = 0;
  digitalWrite(BUZZER_PIN, LOW);
  interrupts();
}

void AudioPlayer::handleTimer() {
  if (!isPlaying || audioData == nullptr || audioIndex >= audioLength) {
    // 再生終了
    isPlaying = false;
    digitalWrite(BUZZER_PIN, LOW);
    return;
  }
  
  // PROGMEMからデータを読み取り
  uint8_t sample = pgm_read_byte(&audioData[audioIndex]);
  audioIndex++;
  
  // 8bit PCM データをブザーで出力
  // WAVファイルの生データには不要なヘッダが含まれている可能性があるため、
  // 実際の音声データ部分のみを処理する
  
  // 簡易的なPWM出力: サンプル値が128以上なら HIGH、未満なら LOW
  if (sample > 128) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}
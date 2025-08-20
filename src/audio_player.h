#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdint.h>

// WAV データは data/ 以下のヘッダで定義
extern const uint8_t pushed_wav[];
extern const uint8_t correct_wav[];
extern const uint8_t incorrect_wav[];
extern const int pushed_wav_length;
extern const int correct_wav_length;
extern const int incorrect_wav_length;

class AudioPlayer {
private:
  volatile const uint8_t* audioData;
  volatile uint16_t audioLength;
  volatile uint16_t audioIndex;
  volatile bool isPlaying;
  
public:
  // ブザーピン (D10) を使って PWM で再生
  void begin();
  void play(const uint8_t *data, uint16_t length);
  bool isPlayingAudio();
  void stop();
  
  // Timer1 割り込みハンドラ用
  void handleTimer();
};

// グローバルな AudioPlayer インスタンス
extern AudioPlayer audioPlayer;

#endif
#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <avr/pgmspace.h>
#include <stdint.h>

// WAV データは data/ 以下のヘッダで定義
extern const uint8_t pushed_wav[];
extern const uint8_t correct_wav[];
extern const uint8_t incorrect_wav[];

class AudioPlayer {
public:
  // PWM 出力ピン (D9) を使って 8kHz で再生
  void begin();
  void play(const uint8_t *data, uint16_t length);
};

#endif
#include "audio_player.h"
#include <avr/pgmspace.h>

void playAudio(const unsigned char* data, size_t length) {
  for (size_t i = 0; i < length; i++) {
    analogWrite(BUZZER_PIN, pgm_read_byte_near(data + i));
    delayMicroseconds(125); // 8kHz = 125μs間隔
  }
  analogWrite(BUZZER_PIN, 0); // 停止
}
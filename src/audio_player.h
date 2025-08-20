#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <Arduino.h>

#define BUZZER_PIN 10

void playAudio(const unsigned char* data, size_t length);

#endif
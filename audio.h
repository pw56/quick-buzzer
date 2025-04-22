const unsigned int Hz = ;
const unsigned float __TIME = 1 / Hz * 1000000;//1秒 ÷ サンプル周波数 × 1秒のマイクロ秒換算


const byte* ANSWER_SOUND = {}

const byte* CORRECT_SOUND = {}

const byte* INCORRECT_SOUND = {}

void __play(byte* data) {
  for(unsigned int i, size = sizeof(*data); i < size; i++) {
    (*data[i]);//この行に配列の音を鳴らすコードを書いて
    delayMicroseconds(__TIME);
  }
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
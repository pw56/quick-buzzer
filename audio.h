void __play(byte* data) {
  for(unsigned int i; i < sizeof(*data); i++) {
    tone();
  }
}

void ringSound(char type) {
  if(type == "") {
    __play();
  }
}
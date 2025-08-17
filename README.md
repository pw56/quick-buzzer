# quick-buzzer

## 概要
このリポジトリはArduino Nano上で動作する早押し機を製作するのに作成・引用したソースコードとそれに必要なファイルです。
このリポジトリのソースコードはMicrosoft Copilotによって作成されました。
[こちら](https://copilot.microsoft.com/shares/pnHkYBDkBwXsRy7J9ifzT)がその会話です。

## ファイル構成
quiz-usb-audio/
├── data/
│   ├── pushed.h
│   ├── correct.h
│   └── incorrect.h
├── lib/
│   └── VUSB/            ← V-USB ライブラリ本体
│       ├── usbconfig.h
│       ├── usbdrv.h
│       └── ...
├── src/
│   ├── main.ino
│   └── audio_player.h
└── README.md

## 使用するソフト
・[Arduino Web Editor](https://create.arduino.cc/editor)
・[AudioMass](https://audiomass.co/)

## 使用するライブラリ
・[V-USB]()

## 使用する素材
・[]()
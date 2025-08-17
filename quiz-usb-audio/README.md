# Quick Buzzer System

## 概要
Arduino Nano上で動作する早押し機システムです。

## ファイル構成
```
quiz-usb-audio/
├── data/
│   ├── pushed.h      - ボタン押下音のオーディオデータ
│   ├── correct.h     - 正解音のオーディオデータ
│   └── incorrect.h   - 不正解音のオーディオデータ
├── lib/
│   └── VUSB/         - V-USB ライブラリ
│       ├── usbconfig.h
│       ├── usbdrv.h
│       └── ...
├── src/
│   ├── main.ino      - メインプログラム
│   └── audio_player.h - オーディオプレイヤーヘッダー
└── README.md
```

## 使用するソフト
- [Arduino Web Editor](https://create.arduino.cc/editor)
- [AudioMass](https://audiomass.co/)

## 使用するライブラリ
- V-USB

## セットアップ
1. Arduino Web Editorでプロジェクトを開く
2. 必要なライブラリをインストール
3. Arduino Nanoに書き込み

## 使用方法
1. システムを起動
2. ボタンを押して早押し機能を使用
3. 正解/不正解に応じて音声が再生される
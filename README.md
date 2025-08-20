# quick-buzzer

## 概要
このリポジトリはArduino Nano上で動作する早押し機を製作するのに作成・引用したソースコードとそれに必要なファイルです。
このリポジトリのソースコードはMicrosoft Copilotによって作成されました。
[こちら](https://copilot.microsoft.com/shares/pnHkYBDkBwXsRy7J9ifzT)がその会話です。

## ファイル構成
```
quick-buzzer
├── data
│   ├── pushed.h         - ボタン押下音のオーディオデータ
│   ├── correct.h        - 正解音のオーディオデータ
│   └── incorrect.h      - 不正解音のオーディオデータ
├── lib
│   └── VUSB             - V-USB ライブラリ
│       ├── usbconfig.h
│       ├── usbdrv.h
│       └── ...
├── src
│   ├── main.ino         - メインプログラム
│   ├── audio_player.h   - オーディオプレイヤーヘッダー
│   └── audio_player.cpp - オーディオプレイヤー実装
├── usbconfig.h          - USBの設定ファイル
├── pins.yml             - ピン割り当てのメモ
├── prompt.txt           - ソースコードのコーディングのプロンプトの文章
├── LICENSE
└── README.md
```

## 使用するソフト
- [Arduino Web Editor](https://create.arduino.cc/editor)
- [Wav2C](https://guilhermerodrigues680.github.io/wav2c-online)

## 使用するライブラリ
- [V-USB](https://github.com/obdev/v-usb)

## 使用した音源
- [効果音ラボ](https://soundeffect-lab.info/)
- [OtoLogic](https://otologic.jp/)

## 回路
![回路図]()

## セットアップ
1. Arduino Web Editorでプロジェクトを開く
2. 必要なライブラリをインストール
3. Arduino Nanoに書き込み

## 使用方法
1. 本体を起動
2. ボタンを押して早押し機能を使用
3. ボタン押下時にブザーで押下音が再生される
4. 正解/不正解ボタンを押すと、対応する音声がブザーで再生される

## 音声再生機能
- **ブザーピン**: D10 (pins.ymlで設定)
- **再生方式**: PWMを使用したブザー出力
- **サンプリングレート**: 8kHz
- **対応音声**:
  - pushed.h: ボタン押下音
  - correct.h: 正解音
  - incorrect.h: 不正解音

## 実物写真
![通常]()
![点灯]()

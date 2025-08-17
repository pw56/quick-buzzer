// usbconfig.h (プロジェクトルート直下に配置)
#ifndef __USBCONFIG_H__
#define __USBCONFIG_H__

// Arduino Nano (ATmega328P) の内蔵8MHz RCを16MHzに倍率変換して使う場合など
#define USB_CFG_CLOCK_KHZ     (F_CPU/1000)

// D− を Arduino の D6、D＋ を D7 として接続
#define USB_CFG_DMINUS_BIT    6
#define USB_CFG_DPLUS_BIT     7

// その他必要な設定（割り込み、USB データ長など）は
// v-usb の README を参照して調整してください

#endif
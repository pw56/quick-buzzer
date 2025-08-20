// usbconfig.h
#ifndef __USBCONFIG_H__
#define __USBCONFIG_H__

// CPUクロック（kHz単位）。16MHz動作なら 16000
#define USB_CFG_CLOCK_KHZ      (F_CPU/1000)

// D− を Arduino D8、D＋ を D9 に接続
#define USB_CFG_DMINUS_BIT     8
#define USB_CFG_DPLUS_BIT      9

// 内部プルアップを使う場合は USB_CFG_PULLUP_INTERNAL を1に
//#define USB_CFG_PULLUP_INTERNAL 1

// HID キーボード用設定
#define USB_CFG_HAVE_INTRIN_ENDPOINT 1
#define USB_CFG_INTRIN_ENDPOINT_SIZE 8

// レポートバッファ長（バイト数）
#define USB_CFG_MAX_BUS_POWER      100  // mA
#define USB_CFG_DEVICE_CLASS       0    // クラス自動判定
#define USB_CFG_DEVICE_SUBCLASS    0
#define USB_CFG_DEVICE_PROTOCOL    0

#endif // __USBCONFIG_H__

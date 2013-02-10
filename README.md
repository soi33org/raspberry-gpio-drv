raspberry-gpio-drv
==================

GPIO Driver for RaspberryPi on Raspbian “wheez"

使い方

## 1.
#include "gpio_drv.h"
ヘッダをインクルードする

## 2.
gpio_init()
メモリマップの初期化を行う

## 3.
gpio_inout(int port_no, GPIO_INOUT inout)
GPIOポート番号とGPIO_IN/GPIO_OUTを渡し、GPIOポートを入力か出力かを指定する

## 4.
### 出力の場合
gpio_write(int port_no, int data) 
GPIOポート番号に対して、データを渡す。
data が 0 だとGPIOの出力が 0 になる
data が 0以外 だとGPIOの出力が 1 になる

### 入力の場合
gpio_read(int port_no)
GPIOポートの入力として 1/0 が返ってくる


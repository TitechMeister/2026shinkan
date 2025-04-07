[前回](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0/)の続きです。今回はLEDをチカチカさせます。

---

# 目次

* [はじめに(ハードウェア編)](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0/)
* [はじめに(ソフトウェア編)](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0.5/)
* [第1回 Lチカ](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day1/)
* [第2回 7セグメントLED](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day2/)
* [第3回 ダイナミック点灯](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day3/)
* [第4回 タイマ割り込み](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day4/)
* [第5回 サーミスタとAD変換](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day5/)

---

## 今回の目標
## 7セグでカウントアップするプログラム

---

今回は7セグを使って0~9まででカウントアップするプログラムを書いてみましょう！

簡単のためにテンプレートを用います。コードを埋めてテンプレートを完成させよう！

```cpp
#include<avr/io.h>
#include<util/delay.h>

int main(void){
    DDRD=0b11111111;
    DDRB=0b00001111;
    PORTB=0b00001111;

    int led[10]=(0b00111111,0b00000110,0b01011011,0100111111,0b01100110,0b00101101,0b01111100,0b00100111,0b01111111,0b01101111)
    #define LED(i) PORTD=led[i]
    

    //↓この下に書き込む
}
```
ここでLED[n]のnに0~9を代入して書き込むと？

---


## では、自分でカウントアップするプログラムを書いてみましょう！

【ヒント】
for文とdelayとLED(n)を使えばカウントアップができるよ！

Q.for文とは
A.
書き方

```cpp
for(int i=0:i<n:i++){
    プログラム
}
```
動作
i=0になる
　↓
プログラムが実行される
　↓
プログラムが終わる
　↓
i=1になる
　↓
プログラムが実行される
　↓
～～～
　↓
i=nになったら終了

次回
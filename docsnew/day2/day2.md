[前回](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)の続きです。

---

# 目次

* [はじめに(ハードウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0/day0.md)
* [はじめに(ソフトウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)
* [第1回 Lチカ](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)
* [第2回 7セグメントLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)
* [第3回 ダイナミック点灯](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)

---

## 今回の目標
## 7セグでカウントアップするプログラムを書く

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

[次回最終回:DAY3_ダイナミック点灯](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)
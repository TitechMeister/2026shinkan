[前回](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)の続きです。

---

# 目次

* [はじめに(ハードウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0/day0.md)
* [はじめに(ソフトウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)
* [第1回 Lチカ](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)
* [第2回 7セグメントLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)
* [第3回 ダイナミック点灯](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)

---

## 今回の目標
## 7セグでそれぞれの桁に違う数字を表示する

---

##  ダイナミック点灯

7セグの4桁に別々の数字を表示させる方法が**ダイナミック点灯**です！

1. 1桁目**だけ**を点灯します。この状態で5ms程度待ちます。
2. 2桁目**だけ**を点灯します。この状態で5ms程度待ちます。
3. 3桁目**だけ**を点灯します。この状態で5ms程度待ちます。
4. 4桁目**だけ**を点灯します。この状態で5ms程度待ちます。

1.~4.を繰り返し実行します。すると、各桁の残像が見えるため、4桁全てが点灯しているように見えます。

---

## トランジスタ

n桁目だけ表示するプログラムを書いていきます。
簡単のために今回もテンプレートを使っていきます。

```cpp
#include<avr/io.h>
#include<util/delay.h>

int main(void){
    
    DDRD=0b11111111;
    DDRB=0b00001111;

    //LED(i)を準備する
    int led[10]=(0b00111111,0b00000110,0b01011011,0100111111,0b01100110,0b00101101,0b01111100,0b00100111,0b01111111,0b01101111);
    #define LED(i) PORTD=led[i]

    //DIGIT(i)を準備する
    int digit[4]=(0b00000001,0b00000010,0b00000100,0b00001000);
    #define DITGIT(i) PORTB=digit[i-1]

    //↓この下に書き込む
    
```
以下のコードを実行してみてください。
```cpp
    while(1){
    DIGIT(n);
    LED(0);
    }
    
```
n桁目だけ0が表示されているのがわかると思います。

##　問題
7セグに1234と表示してみてください。

【ヒント】
1.4桁目に1を5ms表示する
2.3桁目に2を5ms表示する
3.2桁目に3を5ms表示する
4.1桁目に4を5ms表示する
5.1~4を無限に繰り返すと？

【復習】
無限ループ
while(1){
    プログラム
}

n回繰り返す
for(int i=0:i<n:i++){
    プログラム
}

7セグにnを表示する
LED(n);

7セグのn桁目に表示する
DIGIT(n);

---

## 最終課題　0~9999までカウントアップするタイマーを作ろう！



<details>
  <summary>プログラム例</summary>
  <pre><code>
#include<avr/io.h>
#include<util/delay.h>

int led[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111100,0b00100111,0b01111111,0b01101111};

//DIGIT(i)を準備する
int digit[4]={0b00000001,0b00000010,0b00000100,0b00001000};

int main(void){
    DDRD=0b11111111;
    DDRB=0b00001111;

    //LED(i)を準備する

    while(1){
        for(int i=0;i<10000;i++){
            int j = i/1000;
            int k = (i-j*1000)/100;
            int l = (i-j*1000-k*100)/10;
            int m = (i-j*1000-k*100-l*10);
            for(int n =0;n<20;n++){
                PORTD=led[j];
                PORTB=digit[0];
                _delay_ms(1);
                PORTD=led[k];
                PORTB=digit[1];
                _delay_ms(1);
                PORTD=led[l];
                PORTB=digit[2];
                _delay_ms(1);
                PORTD=led[m];
                PORTB=digit[3];
                _delay_ms(1);
            }
        }
    }
}
  </code></pre>
</details>


ここまでお疲れ様でした！
これにて電操作業体験は終了です！
Meisterでは[もひこんなど新勧イベント](https://titechmeister.github.io/welcome/event)が他にもあるのでぜひ参加してみてください！



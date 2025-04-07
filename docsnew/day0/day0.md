# 目次

* [はじめに(ハードウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0/day0.md)
* [はじめに(ソフトウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)
* [第1回 Lチカ](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)
* [第2回 7セグメントLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)
* [第3回 ダイナミック点灯](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)


---

## 1. AVRとは

今回使うマイコンはAVRというものです。Arduino UNOに使われているマイコンもAVRです。

![](img/fig1.jpg)
（秋月電子の販売ページより）

写真を見ると分かるように、マイコンにはピンがたくさんあります。小さいですが、CPUやメモリなどが全部入ってます。それだけでなくAD変換器やUARTなども組み込まれてます。

## 2. 回路の準備

Meister新歓2025で使用する回路の情報はGithubで管理されています。詳細は[https://github.com/TitechMeister/2026sinkan](https://github.com/TitechMeister/2026shinkan/tree/main)で確認できます。

受け取る際には、事前に公式TwitteかDiscord、公式LINEで連絡をして頂けると幸いです。

### 2.1.部品リスト

|名称|個数|画像|
|:-:|:-:|:-:|
|ATmega88|1|<img height="128" src="https://akizukidenshi.com/img/goods/L/103655.jpg"></img>|
|1kΩ抵抗|14|<img width="128" src="https://akizukidenshi.com/img/goods/L/126479.jpg"></img>|
|2SC1815|4|<img width="128" src="https://akizukidenshi.com/img/goods/L/126144.jpg"></img>|
|1x3ピンヘッダ|2|<img src="https://akizukidenshi.com/img/goods/L/106192.jpg" height="128"></img>|
|1x6ピンヘッダ|2|<img width="128"  src="https://akizukidenshi.com/img/goods/L/105336.jpg"></img>|
|USB typeA メス|1|<img height="128" src="https://akizukidenshi.com/img/goods/L/100160.jpg"></img>|
|7セグ|1|<img src="https://akizukidenshi.com/img/goods/L/103673.jpg" height="128"></img>|
## 3. はんだ付け

![](img/fig2.jpg)

今回使う回路を表から見た図です。

はんだ付けする際注意が必要な部分は以下の２点です。

1. マイコンを取り付ける位置。くぼみの部分を合わせます。
1. ７セグの向き。小数点を表示するためのLEDが端に来るように配置します。ロゴと７セグの向きは同じ向きです。

上手なはんだ付けをするために、以下の動画を参考にしてみてください。

[![](http://img.youtube.com/vi/NhDiQtUeF-M/0.jpg)](https://www.youtube.com/watch?v=NhDiQtUeF-M)

部品と表に書いてある番号との対応表です。

|番号|名称|個数|画像|
|:-:|:-:|:-:|:-:|
|U1|ATmega88V|1|<img height="128" src="https://akizukidenshi.com/img/goods/L/103655.jpg"></img>|
|R1~R12|1kΩ抵抗|14|<img width="128" src="https://akizukidenshi.com/img/goods/L/126479.jpg"></img>|
|Q1~Q4|2SC1815|4|<img width="128" src="https://akizukidenshi.com/img/goods/L/126144.jpg"></img>|
|ICSP|1x3ピンヘッダ|2|<img src="https://akizukidenshi.com/img/goods/L/106192.jpg" height="128"></img>|
|J3,J4|1x6ピンヘッダ|2|<img width="128"  src="https://akizukidenshi.com/img/goods/L/105336.jpg"></img>|
|J2|USB typeA メス|1|<img height="128" src="https://akizukidenshi.com/img/goods/L/100160.jpg"></img>|
|J1|7セグ|1|<img src="https://akizukidenshi.com/img/goods/L/103673.jpg" height="128"></img>|


---

[次回：DAY0.5_はじめに(ソフトウェア編)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)に続きます。
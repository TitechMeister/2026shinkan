# XIAO RP2040 動作確認用 PlatformIO プロジェクト

摘出した Seeed Studio XIAO RP2040 が教材用に使える状態か確認するためのスケッチです。XIAO 単体でも USB シリアルと内蔵 USER LED で最低限の生存確認ができ、実習基板に載せた状態では教材で使うピンもまとめて確認できます。

## 確認する内容

- 内蔵 USER LED: 赤、緑、青、白、消灯を繰り返す
- D0/D1/D2: 実習基板上の LED を順番に点灯
- D3/A3: アナログ入力値と電圧をシリアルに表示
- D4/D5: I2C スキャンを実行し、SHT31 などのアドレスを表示
- D6/D7: `uart` コマンドで UART ループバック確認
- D9: ボタン入力を `PRESSED` / `released` で表示
- USB シリアル: コマンド入力と定期レポート表示

## 書き込み

```powershell
cd C:\Users\user\2026shinkan\firmware\xiao_rp2040_check
pio run -t upload
pio device monitor -b 115200
```

PlatformIO の設定は Seeed 公式の PlatformIO 用設定に合わせています。

```ini
platform = https://github.com/Seeed-Studio/platform-seeedboards.git
board = seeed-xiao-rp2040
framework = arduino
```

## BOOT ボタンが取れている個体への対応

このスケッチが一度入っている個体なら、シリアルモニタで次を送ると BOOTSEL モードに入ります。

```text
boot
```

または短く、

```text
b
```

`RPI-RP2` ドライブが見えたら、PlatformIO から再度アップロードできます。

注意: まだ何も書き込まれていない個体、または USB シリアルが起動しない個体は、ソフトウェアから BOOTSEL に入れません。その場合は BOOT パッドを使って BOOT 信号を落としながら USB 接続するか、SWD で書き込む必要があります。

## シリアルコマンド

```text
? / help : ヘルプ表示
report   : レポートを1回表示し、定期レポートを有効化
quiet    : 定期レポートを停止
scan     : D4/D5 の I2C スキャン
uart     : D6(TX) と D7(RX) をジャンパして UART 確認
led      : D0-D2 をまとめて点滅
boot / b : BOOTSEL モードへ再起動
```

## 判定の目安

- XIAO 単体: USB シリアルにレポートが出て、内蔵 USER LED が色変化すれば最低限 OK
- 実習基板上: D0-D2 の LED が順番に光り、D9 ボタンが `PRESSED` になることを確認
- SHT31 接続時: I2C スキャンで `0x45` または `0x44` が見えることを確認
- UART 確認: D6 と D7 をジャンパして `uart` を送ったとき `PASS` になれば OK

I/O ピンに 3.3V を超える電圧を入れないでください。

# MLib - KicadLibrary

Meisterで使用するパーツのKicadLibrary

## 使い方

1. [mouser](https://www.mouser.jp/electronic-cad-symbols-models/)や[Digikey](https://www.digikey.jp/),[RSコンポーネンツ](https://rs.componentsearchengine.com/index.html)などから部品を検索してkicadの関連ファイルをダウンロードしてくる。
2. {部品名}.kicad_symファイルの中身をMeister.kicad_symファイルの末尾にすべてコピペする。また (property "Footprint" "{部品名}" となっている部分を (property "Footprint" "Meister:{部品名}"　のように変更する。
3. 同じようにMeister.bakも変更する。(これはkicad_symのバックアップファイルらしい)
4. もし存在するならば、{部品名}.libや{部品名}.dcmも同じようにMeister.libまたはMeister.dcmの末尾に追加する。なくても問題ないかも？
5. {パッケージ名}.kicad_modファイルをMeister.prettyフォルダの中に入れる。

## 一覧

|パーツ名|パッケージタイプ|説明|
|:---:|---|---|
|NJM2863F33|SOP|ローノイズ低飽和型レギュレータ3.3V|
|NJM2866F33|SOP|低損失表面実装型レギュレーター 3.3V100mA|

## 参考

<https://keiorogiken.wordpress.com/2017/12/01/kicad%E3%81%AE%E6%8B%A1%E5%BC%B5%E5%AD%90%E4%BD%95%E3%82%82%E3%82%8F%E3%81%8B%E3%82%89%E3%82%93%E3%80%82/>

### パッケージタイプ

|略称|正式名称|実装型|説明|
|:---:|---|---|---|
|SIP|Single In-line Package|挿入実装型|1方向、直線状|
|ZIP|Zigzag In-line Package|挿入実装型|1方向、交互に折り曲げ|
|DIP|Dual In-line Package|挿入実装型|2方向、直線状|
|SOP|Small Outline Package|表面実装型|2方向、L字型|
|SOJ|Small Outline J-leaded package|表面実装型|2方向、J字型(内側に曲がっている)|
|SON|Small Outline Non-leaded package|表面実装型|2方向、電極パッド|
|QFP|Quad Flat Package|表面実装型|4方向、L字型|
|QFJ|Quad Flat J-leaded package|表面実装型|4方向、J字型|
|QFN|Quad Flat Non-leaded package|表面実装型|4方向、電極パッド(側面にもある場合とない場合がある)|
|PGA|Pin Grid Array|挿入実装型|マトリックス、針状|
|LGA|Land Grid Array|表面実装型|マトリックス、電極パッド(底面のみ)|

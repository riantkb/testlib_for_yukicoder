# testlib for yukicoder
[yukicoder](https://yukicoder.me/) で [testlib](https://github.com/MikeMirzayanov/testlib) ( + [rime](https://github.com/icpc-jag/rime)) を用いた入力生成、入力検証、スペシャルジャッジを行うためのサンプルコード

## できること
- yukicoder のジェネレータ機能において、testlib を利用したテストケース生成を行うことができる
  - rime と yukicoder において、同じコードで同じランダムケースを生成することができる
- yukicoder のスペシャルジャッジ、リアクティブジャッジ、スコアリングジャッジにおいて、testlib を利用した正答判定を行うことができる
  - rime と yukicoder において、同じコードでジャッジができる


## 使い方
- 対応するジャッジ形式の問題の `tests/TESTSET`, `tests/generator.cc`, `tests/validator.cc` (, `tests/judge.cc`, `tests/reactive.cc`) を参考に、適宜自分の問題に適したように書き換える。
  - `tests/TESTSET` に `flags=['-DIS_NOT_YUKICODER']` が必要な場合に注意してください


## 例
### ノーマルジャッジの例
- [問題文](00_normal_judge/statement.md)
- [generator](00_normal_judge/tests/generator.cc)
- [validator](00_normal_judge/tests/validator.cc)

### スペシャルジャッジの例
- [問題文](01_special_judge/statement.md)
- [generator](01_special_judge/tests/generator.cc)
- [validator](01_special_judge/tests/validator.cc)
- [judge](01_special_judge/tests/judge.cc)

### リアクティブジャッジの例
- [問題文](02_reactive_judge/statement.md)
- [generator](02_reactive_judge/tests/generator.cc)
- [validator](02_reactive_judge/tests/validator.cc)
- [reactive](02_reactive_judge/tests/reactive.cc)
- [judge](02_reactive_judge/tests/judge.cc)

### スコアリングジャッジの例
- [問題文](03_scoring_judge/statement.md)
- [generator](03_scoring_judge/tests/generator.cc)
- [validator](03_scoring_judge/tests/validator.cc)
- [judge](03_scoring_judge/tests/judge.cc)


---

## やっていること
### 環境認識について
- yukicoder でのコンパイル時に定義される特有の環境変数などは存在しなかったため、ローカルでのコンパイル時に `IS_NOT_YUKICODER` という環境変数を定義することで対応した。
  - ダサいが、まぁ……

### ジェネレータ
- yukicoder のジェネレータ機能は 1 つの入力を生成するプログラムを複数回走らせることで複数個のランダムな入力を得ているが、testlib では乱数を固定しているため、複数回走らせても同じ入力しか得ることができない。
  - ジェネレータを走らせるたびに得られる入力が変わると困ることも多いので、この仕様は正しいと個人的には考えている。
- ここでは、yukicoder のジェネレータ機能において通し番号が標準入力で与えられることを利用し、それを乱数のシードに設定することで異なる出力が得られるようにした。
- 同時に、rime での実行時にも通し番号で毎回乱数のシードを上書きすることで yukicoder のジェネレータ機能と同じ入力を吐くようにした。
  - 実際には、通し番号をある定数回 xorshift したものをシードとする、などの方法を取った方が良いかもしれない。

### スペシャルジャッジ
- testlib で想定されている入力・想定解・出力の受け取り方と、yukicoder におけるそれらの受け渡し方が一致していなかったため、それらを繋げる関数を用意した。

### リアクティブジャッジ
- rime で使用できるリアクティブジャッジと yukicoder で提供されているリアクティブジャッジの方式が異なるため、その両方における IO 関数を用意した。
  - かなり不完全ではありますが……
- rime では kupc 方式が採用されており、[reactive.hpp](common/reactive.hpp) を用いるため testlib は用いず、yukicoder では testlib を用いた。

### スコアリングジャッジ
- ほとんどスペシャルジャッジと同様のため、スコアの出力方法についてのみ関数を用意した。

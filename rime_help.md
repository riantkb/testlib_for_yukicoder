# 問題の作り方

（この markdown は以前 TTPC を開催した際に用意したものに一部改変を加えたものです。）


- `hoge` を適宜問題名に読み替えてください


## 問題ディレクトリ作成
```sh
rime add . problem hoge
```
- `hoge` というディレクトリができて、中には `PROBLEM` というファイルのみが生成されます。

```sh
cd hoge
```
- 以下は全て、問題ディレクトリ直下にいることを想定して書きます。


## 想定解、想定誤解答等の作成
```sh
rime add . solution riantkb
```
- `riantkb` というディレクトリができ、中には `SOLUTION` というファイルのみが生成されます。

`riantkb/SOLUTION（生成時）`
```py
# -*- coding: utf-8; mode: python -*-

## Solution
#c_solution(src='main.c') # -lm -O2 as default
#cxx_solution(src='main.cc', flags=[]) # -std=c++11 -O2 as default
#java_solution(src='Main.java', encoding='UTF-8', mainclass='Main')
#java_solution(src='Main.java', encoding='UTF-8', mainclass='Main',
#              challenge_cases=[])
#java_solution(src='Main.java', encoding='UTF-8', mainclass='Main',
#              challenge_cases=['10_corner*.in'])
#rust_solution(src='main.rs') # Rust (rustc)
#script_solution(src='main.sh') # shebang line is required
#script_solution(src='main.pl') # shebang line is required
#script_solution(src='main.py') # shebang line is required
#script_solution(src='main.rb') # shebang line is required
#js_solution(src='main.js') # javascript (nodejs)
#hs_solution(src='main.hs') # haskell (stack + ghc)
#cs_solution(src='main.cs') # C# (mono)

## Score
#expected_score(100)
```

- これのうち使用するもの 1 つのみコメントアウトを外し、適宜ファイル名を書き換えます（その他は残しても消してもどちらでも良いです）。

`riantkb/SOLUTION（変更後）`
```py
# -*- coding: utf-8; mode: python -*-

## Solution
#c_solution(src='main.c') # -lm -O2 as default
cxx_solution(src='main.cc', flags=[]) # -std=c++11 -O2 as default
#java_solution(src='Main.java', encoding='UTF-8', mainclass='Main')
#java_solution(src='Main.java', encoding='UTF-8', mainclass='Main',
#              challenge_cases=[])
#java_solution(src='Main.java', encoding='UTF-8', mainclass='Main',
#              challenge_cases=['10_corner*.in'])
#rust_solution(src='main.rs') # Rust (rustc)
#script_solution(src='main.sh') # shebang line is required
#script_solution(src='main.pl') # shebang line is required
#script_solution(src='main.py') # shebang line is required
#script_solution(src='main.rb') # shebang line is required
#js_solution(src='main.js') # javascript (nodejs)
#hs_solution(src='main.hs') # haskell (stack + ghc)
#cs_solution(src='main.cs') # C# (mono)

## Score
#expected_score(100)
```

- なお、想定誤解法を作成する場合は、以下のようにすることで「そのコードがあるテストケースでちゃんと落ちるか」をテストすることができます（詳しくはこちらを読んでください: https://rime.readthedocs.io/ja/latest/#solution ）。

`riantkb/SOLUTION（変更後）`
```py
# -*- coding: utf-8; mode: python -*-

## Solution
cxx_solution(src='main.cc', flags=[], challenge_cases=[]) # -std=c++11 -O2 as default

## Score
#expected_score(100)
```

- `riantkb/main.cc` （上で指定したファイル名）を作成し、コードを書きます。


## 入力生成器、検証器の作成
```sh
rime add . testset tests
```
- `tests` というディレクトリができ、中には `TESTSET` というファイルのみが生成されます。

`tests/TESTSET（生成時）`
```py
# -*- coding: utf-8; mode: python -*-

## Input generators.
#c_generator(src='generator.c')
#cxx_generator(src='generator.cc', dependency=['testlib.h'])
#java_generator(src='Generator.java', encoding='UTF-8', mainclass='Generator')
#rust_generator(src='generator.rs')
#script_generator(src='generator.pl')

## Input validators.
#c_validator(src='validator.c')
#cxx_validator(src='validator.cc', dependency=['testlib.h'])
#java_validator(src='Validator.java', encoding='UTF-8',
#               mainclass='tmp/validator/Validator')
#rust_validator(src='validator.rs')
#script_validator(src='validator.pl')

## Output judges.
#c_judge(src='judge.c')
#cxx_judge(src='judge.cc', dependency=['testlib.h'],
#          variant=testlib_judge_runner)
#java_judge(src='Judge.java', encoding='UTF-8', mainclass='Judge')
#rust_judge(src='judge.rs')
#script_judge(src='judge.py')

## Reactives.
#c_reactive(src='reactive.c')
#cxx_reactive(src='reactive.cc', dependency=['testlib.h', 'reactive.hpp'],
#             variant=kupc_reactive_runner)
#java_reactive(src='Reactive.java', encoding='UTF-8', mainclass='Judge')
#rust_reactive(src='reactive.rs')
#script_reactive(src='reactive.py')

## Extra Testsets.
# icpc type
#icpc_merger(input_terminator='0 0\n')
# icpc wf ~2011
#icpc_merger(input_terminator='0 0\n',
#            output_replace=casenum_replace('Case 1', 'Case {0}'))
#gcj_merger(output_replace=casenum_replace('Case 1', 'Case {0}'))
id='X'
#merged_testset(name=id + '_Merged', input_pattern='*.in')
#subtask_testset(name='All', score=100, input_patterns=['*'])
# precisely scored by judge program like Jiyukenkyu (KUPC 2013)
#scoring_judge()
```

- 先ほどと同様に使うものだけコメントアウトを外し、適宜ファイル名を書き換えます（generator, validator それぞれ複数指定できます）。
- 必要であればスコアについても記述します。
  - 部分点を設定しない場合は Sample と All のみ、設定する場合はよしなにしてください。

`tests/TESTSET（変更後）`
```py
# -*- coding: utf-8; mode: python -*-

## Input generators.
#c_generator(src='generator.c')
cxx_generator(src='generator.cc', dependency=['testlib.h'])
cxx_generator(src='generator_corner.cpp', dependency=['testlib.h'])
#java_generator(src='Generator.java', encoding='UTF-8', mainclass='Generator')
#rust_generator(src='generator.rs')
#script_generator(src='generator.pl')

## Input validators.
#c_validator(src='validator.c')
cxx_validator(src='validator.cc', dependency=['testlib.h'])
cxx_validator(src='validator_rickytheta.cpp', dependency=['testlib.h'])
#java_validator(src='Validator.java', encoding='UTF-8',
#               mainclass='tmp/validator/Validator')
#rust_validator(src='validator.rs')
#script_validator(src='validator.pl')

## Output judges.
#c_judge(src='judge.c')
#cxx_judge(src='judge.cc', dependency=['testlib.h'],
#          variant=testlib_judge_runner)
#java_judge(src='Judge.java', encoding='UTF-8', mainclass='Judge')
#rust_judge(src='judge.rs')
#script_judge(src='judge.py')

## Reactives.
#c_reactive(src='reactive.c')
#cxx_reactive(src='reactive.cc', dependency=['testlib.h', 'reactive.hpp'],
#             variant=kupc_reactive_runner)
#java_reactive(src='Reactive.java', encoding='UTF-8', mainclass='Judge')
#rust_reactive(src='reactive.rs')
#script_reactive(src='reactive.py')

## Extra Testsets.
# icpc type
#icpc_merger(input_terminator='0 0\n')
# icpc wf ~2011
#icpc_merger(input_terminator='0 0\n',
#            output_replace=casenum_replace('Case 1', 'Case {0}'))
#gcj_merger(output_replace=casenum_replace('Case 1', 'Case {0}'))
id='X'
#merged_testset(name=id + '_Merged', input_pattern='*.in')
subtask_testset(name='Sample', score=0, input_patterns=['*sample*'])
subtask_testset(name='All', score=100, input_patterns=['*'])
# precisely scored by judge program like Jiyukenkyu (KUPC 2013)
#scoring_judge()
```

- `tests/generator.cc`, `tests/validator.cc` （上で指定したファイル名）を作成し、コードを書きます。
  - このとき、`testlib.h` が便利なので使うようにしましょう。
    - いい感じのドキュメントがない、かなしい。
    - このディレクトリにあるコードを読んだり、他のブログ記事などを読んだりして雰囲気を察して下さい。
    - 適当に関数定義に飛んで `testlib.h` の実装を眺めると良い気持ちになる。

- サンプルなどの手で作った入力に関しては、`.in` という拡張子で tests ディレクトリ内に入れておくとそれも一緒に validate と test をしてくれます。嬉しい。
- 場合によっては output checker とかがあったほうが良いかも？


## テストの実行
```sh
rime test
```
- テストが実行されます。具体的には以下が行われます。
  - 各コードのコンパイル
  - テストケースの生成、検証
  - 各解答コードのテスト

- Mac ユーザーの場合、`gcc` と叩くと clang が起動するせいで `bits/stdc++.h` をインクルードしているとコンパイルでこけます。
  - `CXX=g++-10` など、`CXX` をよしなに設定することで解決できます。

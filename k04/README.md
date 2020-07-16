# 課題4 レポート

bb35319001 青木晴喜

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l.5~10 : 性別、身長、学籍番号の構造体の宣言

l.25~27 : 性別、身長のデータファイルを読み込む

l.29~31 : 学籍番号のデータファイルを読み込む

l.40~46 : 配列に性別、身長のデータを格納

l.55~60 : 配列に学籍番号を格納

l.62~63 : 学籍番号の入力を求める

l.67~84 : 入力された学籍番号があった場合、男女別にデータを表示させる

l.87~89 : 入力された学籍番号がなかった場合、No data　と表示させる

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment #20200716 moto]
- OKです。
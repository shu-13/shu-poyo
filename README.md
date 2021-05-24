[JP](https://github.com/shu-rt/shu-poyo/) | [ENG](https://github.com/shu-rt/shu-poyo/blob/main/README.en.md)

# shu-poyo
しゅうの自作マウス研修用のデータを管理する場所です

# 各種スペック
## 開発用PC
MacBook Pro (13-in, 2019), macOS Catalina 10.15.6  
Processor: 1.4 GHz Quad-Core Intel Core i5  

## マイクロマウス機体
CPU: STM32?  
Sensors: Light sensor, push button, IMU  
Motor: ?  
Motor Driver: ?  

## ソフトウェア
|Tool |Name |Version |
|----|----|----|
|開発PC |macOS Catalina| 10.15.6|
|エディタ |VS Code| 1.54.3|
|パッケージ管理 |Homebrew| 2.4.16|
|書き込み |Open-OCD |0.11.0 |
|プログラム生成 |STM32CubeMX |6.2.1 |
|GNU Tools |arm-none-eabi-gcc |9.2.1 |

### インストール方法
VS Codeは[こちら](https://code.visualstudio.com/download)からインストールしましょう  
C/C++とCodeDebuggerのエクステンションも用意するとよいです  

[公式ページ](https://brew.sh/index_ja)より、Homebrewをインストールしましょう  
次のコマンドで、GNU Toolsをインストールします
```sh
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```

次のコマンドで、フラッシュ書き込み用のソフトウェアをインストールします
```sh
$ brew install open-ocd
```

STM32CubeMXは[こちら](https://www.st.com/ja/development-tools/stm32cubemx.html)からダウンロードしましょう  
`SetupSTM32CubeMX-X.X.X.app`を起動して、インストールしていきます  
起動しない場合は次のコマンドを実行してみましょう(ダウンロードしたファイルに含まれているREADME.htmlに書かれていました)  
```sh
(.appがあるデイレクトりで)$ sudo xattr -cr ./SetupSTM32CubeMX-6.2.1.app 
```


# 階層の説明
## circuits
使用する回路図をここに置きます

## hardware
機体の大きさやギア周りなどの設計図を置きます

## software
書き上げたソフトウェアを置きます  

# LICENSE
こちらのリポジトリは**MIT LICENSE**の基で公開されています。  
詳しくは、[LICENSE](https://github.com/shu-rt/shu-poyo/blob/main/LICENSE)をご参照ください。

"software"ディレクトリにはSTM32CubeMXで生成したソースコードが含まれています。  
それらの各ソースコードについては、各ファイルのヘッダーに明記されているライセンスに従います。
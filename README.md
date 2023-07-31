# Oyadomari_Kakeru_Project
 
国際電子ビジネス専門学校ITエンジニア科ゲームプログラムコース 3年生課程　3年　
親泊 翔(オヤドマリ　カケル)
メール : kakeru-oyadomari-k21f@stu.kbc.ac.jp


【タイトル】はしをつなげっぱなし
【開発環境】Windows10 Visual Stusio 2022
【使用技術】C/C++, DXライブラリ
【 作成者 】 ☆親泊 翔
            ・阿次富 心
            ・當銘 耀斗
            ・松竹 武人
            ・横田 雷揮
            ・菅 翔希


〇ゲーム説明
上下に動くブロックを繋げてプレイヤーをできるだけ遠くに運ぶゲームです。
繋げることに失敗したり、上に2マス以上の段差を作ってしまうとゲームオーバーになります。

〇操作方法
コントローラー（XInput方式）
左スティック  ：カーソル移動
A            ：決定、ブロックの設置
BACK         ：ポーズ


〇担当箇所
・シーン管理
    SceneManager.h
    SceneManager.cpp
    AbstractScene.h

・ゲームメイン
    GameMain.h
    GameMain.cpp
    World.h
    World.cpp

・ポーズ画面
    ExitDisplay.h
    ExitDisplay.cpp
    DrawBoxUI.h
    DrawBoxUI.cpp
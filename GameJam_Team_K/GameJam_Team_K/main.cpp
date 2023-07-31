#include "DxLib.h"
#include "SceneManager.h"
#include "FrameRateControll.h"
#include "Controll.h"
#include "Title.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);

    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    SetBackgroundColor(0x53, 0xff, 0x8F);

    FrameRateControll* frame;
    frame = new FrameRateControll();

    SceneManager sceneMng(dynamic_cast<AbstractScene*>(new Title()));

    while (ProcessMessage() == 0)   //メインの更新
    {
        ClearDrawScreen();		//画面初期化
        frame->Update();
        sceneMng.Update();		//シーン更新処理
        frame->Draw();
        sceneMng.Draw();		//シーン描画処理

        frame->Wait();
        if (sceneMng.ChangeScene() == nullptr)		//シーン変更処理
        {
            DxLib_End();		//DxLib終了
            return 0;			//ソフト終了
        }
        ScreenFlip();			//裏画面の内容を表画面に反映
    }


    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}
#include "Controll.h"
#include "SceneManager.h"
#include "End.h"
#include "Title.h"

void SceneManager::Update() {
    Controll::Update();

    if (exitdisplay != nullptr) {
        exitdisplay->Update();
    }
    else {
        // 現在シーンのアップデートを実行
        mScene->Update();
    }

    //backを押したらUIの表示
    if (exitdisplay == nullptr
        && (Controll::JudgeChatteButton(XINPUT_BUTTON_BACK) == true
            || (GetJoypadInputState(DX_INPUT_KEY) & PAD_INPUT_9) != 0)) {
        exitdisplay = new ExitDisplay;
    }
    else if (exitdisplay != nullptr
        && (Controll::JudgeChatteButton(XINPUT_BUTTON_BACK) == true
            || (GetJoypadInputState(DX_INPUT_KEY) & PAD_INPUT_9) != 0 || exitdisplay->GetRetryFlg())) {
        exitdisplay = nullptr;
        //コントローラの更新をしないとそのまま画面遷移のほうでAボタンが
        //入力されてる判定になるから一度だけ更新
        Controll::Update();
    }
}

// 描画処理
void SceneManager::Draw() const {
    // 現在シーンの描画関数を実行
    if (exitdisplay != nullptr) {
        exitdisplay->Draw();
    }
    else {
        mScene->Draw();
    }
}

AbstractScene* SceneManager::ChangeScene()
{
    AbstractScene* nextScene = mScene;

    if (exitdisplay != nullptr) {
        //MenuでEXITを選んだら終了
        if (exitdisplay->GetExitFlg()) {
            nextScene = new End();
            exitdisplay = nullptr;
        }
        else if (exitdisplay->GetTitleFlg()) {
            nextScene = new Title;
            exitdisplay = nullptr;
        }
    }
    else {
        nextScene = mScene->ChangeScene();
    }


    // 次のシーンが現在シーンと違う場合切り替える
    if (nextScene != mScene) {
        delete mScene;
        mScene = nextScene;
    }

    return nextScene;
}
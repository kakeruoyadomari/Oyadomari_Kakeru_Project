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
        // ���݃V�[���̃A�b�v�f�[�g�����s
        mScene->Update();
    }

    //back����������UI�̕\��
    if (exitdisplay == nullptr
        && (Controll::JudgeChatteButton(XINPUT_BUTTON_BACK) == true
            || (GetJoypadInputState(DX_INPUT_KEY) & PAD_INPUT_9) != 0)) {
        exitdisplay = new ExitDisplay;
    }
    else if (exitdisplay != nullptr
        && (Controll::JudgeChatteButton(XINPUT_BUTTON_BACK) == true
            || (GetJoypadInputState(DX_INPUT_KEY) & PAD_INPUT_9) != 0 || exitdisplay->GetRetryFlg())) {
        exitdisplay = nullptr;
        //�R���g���[���̍X�V�����Ȃ��Ƃ��̂܂܉�ʑJ�ڂ̂ق���A�{�^����
        //���͂���Ă锻��ɂȂ邩���x�����X�V
        Controll::Update();
    }
}

// �`�揈��
void SceneManager::Draw() const {
    // ���݃V�[���̕`��֐������s
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
        //Menu��EXIT��I�񂾂�I��
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


    // ���̃V�[�������݃V�[���ƈႤ�ꍇ�؂�ւ���
    if (nextScene != mScene) {
        delete mScene;
        mScene = nextScene;
    }

    return nextScene;
}
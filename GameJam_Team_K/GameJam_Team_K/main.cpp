#include "DxLib.h"
#include "SceneManager.h"
#include "FrameRateControll.h"
#include "Controll.h"
#include "Title.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);

    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    SetBackgroundColor(0x53, 0xff, 0x8F);

    FrameRateControll* frame;
    frame = new FrameRateControll();

    SceneManager sceneMng(dynamic_cast<AbstractScene*>(new Title()));

    while (ProcessMessage() == 0)   //���C���̍X�V
    {
        ClearDrawScreen();		//��ʏ�����
        frame->Update();
        sceneMng.Update();		//�V�[���X�V����
        frame->Draw();
        sceneMng.Draw();		//�V�[���`�揈��

        frame->Wait();
        if (sceneMng.ChangeScene() == nullptr)		//�V�[���ύX����
        {
            DxLib_End();		//DxLib�I��
            return 0;			//�\�t�g�I��
        }
        ScreenFlip();			//����ʂ̓��e��\��ʂɔ��f
    }


    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}
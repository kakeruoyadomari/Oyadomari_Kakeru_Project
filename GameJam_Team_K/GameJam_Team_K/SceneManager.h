#pragma once
#include "DxLib.h"
#include "AbstractScene.h"
#include "ExitDisplay.h"

// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ����Ǘ�����B
class SceneManager : public AbstractScene {
private:
    AbstractScene* mScene;  // ���݂̃V�[��
    ExitDisplay* exitdisplay = nullptr;


public:
    // �R���X�g���N�^
    SceneManager(AbstractScene* scene)
        : mScene(scene) {}

    // �f�X�g���N�^
    ~SceneManager()
    {
        delete mScene;
    }

    //�`��ȊO�̍X�V����������
    void Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    void Draw() const override;

    //�V�[���̕ύX����
    AbstractScene* ChangeScene() override;
};
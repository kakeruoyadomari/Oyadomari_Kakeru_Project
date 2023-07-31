#pragma once
#include "AbstractScene.h"
#include "World.h"


class GameMain : public AbstractScene
{
private:
	World* world;

	int backGroundImage[3];		//�w�i�摜�z��
	int backGround;				//�w�i�摜�i�[�p
	int timer;					//�w�i�摜�؂�ւ��p�^�C�}�[

public:
	//�R���X�g���N�^
	GameMain();


	World GetWorld() { return *world; }

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};
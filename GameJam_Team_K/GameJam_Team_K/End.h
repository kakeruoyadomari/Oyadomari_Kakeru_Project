#pragma once
#include "AbstractScene.h"

class End : public AbstractScene
{
private:
	int endImage;			//end�摜

	int waitTime;			//�X�N���[���p���ԕϐ�
	int posY;				//�X�N���[�X�p���W

public:
	End();

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����

};


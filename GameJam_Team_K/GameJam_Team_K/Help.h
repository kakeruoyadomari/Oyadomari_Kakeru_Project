#pragma once
#include "AbstractScene.h"

class Help : public AbstractScene
{
private:
	int helpImage;								//Help�w�i�摜

public:
	Help();

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};


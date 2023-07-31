#pragma once
#include "AbstractScene.h"

#define D_SCREEN_WIDTH 1280
#define D_SCREEN_HEIGHT 720
#define D_PRESS_FONTSIZE 36
#define D_TITLE_FONTSIZE 120
#define D_TITLE_SELECT_GAME		0
#define D_TITLE_SELECT_RANKING	1
#define D_TITLE_SELECT_HELP		2
#define D_TITLE_SELECT_END		3

class Title : public AbstractScene 
{
private:
	int flgnumber;
	int MenuNumber;
	int Cursor_Y;

	int TitleImage;
public:
	Title();

	// �f�X�g���N�^
	~Title() 
	{

	};

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};

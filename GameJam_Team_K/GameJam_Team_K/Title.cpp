#include <string.h>
#include "DxLib.h"
#include "Title.h"
#include "Controll.h"
#include "GameMain.h"
#include "DrawRanking.h"
#include "Help.h"
#include "End.h"

//----------------------------
// �R���X�g���N�^
//----------------------------
Title::Title()
{
	//�w�i�摜�f�[�^�ǂݍ���
	TitleImage = LoadGraph("Resource/Image/Title.png");

	flgnumber = 0;
	Cursor_Y = 0;
	MenuNumber = 0;
}

void Title::Update() 
{
	flgnumber = Controll::GetJudgeStick(D_STICK_L);


	//�J�[�\���ړ�
	if (flgnumber == 4)
	{
		if (++MenuNumber > 3)
		{
			MenuNumber = 0;
		}

	}

	if (flgnumber == 3)
	{
		if (--MenuNumber < 0)
		{
			MenuNumber = 3;
		}

	}

	Cursor_Y = MenuNumber * 60;		//�J�[�\���ʒu
}

void Title::Draw() const 
{
	SetFontSize(80);
	DrawGraph(0, 0, TitleImage, FALSE);
	DrawFormatString(210, 100, 0x000000, "�͂����Ȃ����ςȂ�!!");

	SetFontSize(70);
	DrawString(540, 360, "Start", 0x000000, TRUE);		//Start����
	DrawString(540, 420, "Ranking", 0x000000, TRUE);	//Ranking����
	DrawString(540, 480, "Help", 0x000000, TRUE);		//Help����
	DrawString(540, 540, "End", 0x000000, TRUE);		//End����

	DrawTriangle(510, 370 + Cursor_Y, 540, 390 + Cursor_Y, 510, 410 + Cursor_Y, GetColor(255, 0, 0), TRUE);		//�J�[�\��
}


AbstractScene* Title::ChangeScene()
{
	//�Q�[�����C��
	if (MenuNumber == D_TITLE_SELECT_GAME)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new GameMain();
		}
	}

	//�����L���O
	if (MenuNumber == D_TITLE_SELECT_RANKING)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new DrawRanking();
		}
	}

	//�w���v
	if (MenuNumber == D_TITLE_SELECT_HELP)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new Help();
		}
	}

	//�G���h
	if (MenuNumber == D_TITLE_SELECT_END)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new End();
		}
	}

	return this;
}
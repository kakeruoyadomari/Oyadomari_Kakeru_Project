#include "Help.h"
#include "DxLib.h"
#include "Controll.h"
#include "Title.h"

Help::Help()
{
	helpImage = LoadGraph("Resource/Image/Ranking.png");
}

void Help::Update()
{
}

void Help::Draw() const
{
	DrawGraph(0, 0, helpImage, FALSE);

	SetFontSize(30);
	DrawString(10, 60, "�w���v���", 0xffffff, 0);

	SetFontSize(50);
	DrawString(100, 180, "             �`�`�V�ѕ��`�`            ", 0xffffff, 0);
	DrawString(100, 260, "���̃Q�[���͏㉺�ɃX���C�h����u���b�N��", 0xffffff, 0);
	DrawString(100, 320, "�^�C�~���O�����킹�Čq���Ă����Q�[���ł��B", 0xffffff, 0);
	DrawString(100, 380, "�q����̂Ɏ��s������,2�}�X�ȏ�̒i��������", 0xffffff, 0);
	DrawString(100, 440, "�@�@�@�@�@�@�Q�[���I�[�o�[�ł��B�@�@�@�@�@", 0xffffff, 0);

	SetFontSize(30);
	DrawString(320, 660, "---- [A]�{�^���������ă^�C�g���֖߂� ----", 0xffff00, 0);
}

AbstractScene* Help::ChangeScene()
{
	if (Controll::JudgeChatteButton(XINPUT_BUTTON_A) == true)
	{
		return new Title();
	}

	return this;
}

#include "End.h"

End::End()
{
	endImage = LoadGraph("Resource/Image/Ranking.png");

	waitTime = 0;
	posY = 0;
}

void End::Update()
{
	//�G���f�B���O�X�N���[��
	if (++waitTime < 600) posY = 300 - waitTime / 2;
}

void End::Draw() const
{
	SetFontSize(24);
	DrawGraph(0, 0, endImage, FALSE);
	DrawString(100, 170 + posY, "�^�C�g���@�@�@�͂����Ȃ����ςȂ�", 0xFFFFFF);
	DrawString(100, 200 + posY, "�o�[�W�����@�@1.0", 0xFFFFFF);
	DrawString(100, 230 + posY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
	DrawString(100, 260 + posY, "�@�@�@�@�@�@�@���e�� ��", 0xFFFFFF);
	DrawString(100, 290 + posY, "�@�@�@�@�@�@�@�E�����x �S", 0xFFFFFF);
	DrawString(100, 320 + posY, "�@�@�@�@�@�@�@�E�c�� �s�l", 0xFFFFFF);
	DrawString(100, 350 + posY, "�@�@�@�@�@�@�@�E���| ���l", 0xFFFFFF);
	DrawString(100, 380 + posY, "�@�@�@�@�@�@�@�E���c ����", 0xFFFFFF);
	DrawString(100, 410 + posY, "�@�@�@�@�@�@�@�E�� �Ċ�", 0xFFFFFF);
}

AbstractScene* End::ChangeScene()
{
	if (++waitTime > 1000)
	{
		return nullptr;
	}
	return this;
}

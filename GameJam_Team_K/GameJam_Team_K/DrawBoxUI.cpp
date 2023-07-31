#include "DrawBoxUI.h"


void DrawBoxUI::DrawBoxUIString(int x, int y, const TCHAR* str, int fontSize, unsigned int backColor, unsigned int frontColor)
{
	// BOX����肻��̒��ɕ���������

	int len = strlen(str);
	int width = 0;
	int height = 0;
	int judgeJ = 0;
	int judgeI = 0;

	//���s�����邩�̊m�F
	if ((len - 1) / 10 >= 1) {
		height = (1 + (len - 1) / 10) * fontSize;
		judgeI = (1 + (len / 10));
	}
	else
	{
		height = fontSize;
		judgeI = 1;
	}
	if (len / 10 >= 1) {
		width = 10 * (fontSize - 10);
		judgeJ = 10;
	}
	else
	{
		width = (len % 10) * (fontSize - 10);
		judgeJ = len % 10;
	}

	//�O�g�̃{�b�N�X
	DrawBox(x - (width / 2) - (len / 3) - 5, y - (height / 2) - (len / 3) - 5,
		x + (width / 2) + (len / 5) + 5, y + (height / 2) + (len / 5) + 5,
		backColor, TRUE);
	//���g�̃{�b�N�X
	DrawBox(x - (width / 2) - (len / 3), y - (height / 2) - (len / 3),
		x + (width / 2) + (len / 5), y + (height / 2) + (len / 5),
		frontColor, TRUE);

	//�w�肵���傫���̕������o��
	SetFontSize(fontSize);
	//�s
	for (int i = 0; i < judgeI; i++)
	{
		if (len / 10 >= 1) {
			judgeJ = 10;
		}
		else
		{
			judgeJ = len % 10;
		}
		//��
		for (int j = 0; j < judgeJ; j++) {
			DrawFormatString(x - (width / 2) + j * (fontSize - 10), y - (height / 2) + i * fontSize - 5, 0xffffff, "%c", str[(i * 10) + j]);
		}
		len -= 10;
	}

	//�f�t�H���g�̃t�H���g�T�C�Y�ɕύX
	SetFontSize(DEFAULT_FONT_SIZE);
}



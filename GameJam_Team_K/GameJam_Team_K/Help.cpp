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
	DrawString(10, 60, "ヘルプ画面", 0xffffff, 0);

	SetFontSize(50);
	DrawString(100, 180, "             ～～遊び方～～            ", 0xffffff, 0);
	DrawString(100, 260, "このゲームは上下にスライドするブロックを", 0xffffff, 0);
	DrawString(100, 320, "タイミングを合わせて繋げていくゲームです。", 0xffffff, 0);
	DrawString(100, 380, "繋げるのに失敗したり,2マス以上の段差を作ると", 0xffffff, 0);
	DrawString(100, 440, "　　　　　　ゲームオーバーです。　　　　　", 0xffffff, 0);

	SetFontSize(30);
	DrawString(320, 660, "---- [A]ボタンを押してタイトルへ戻る ----", 0xffff00, 0);
}

AbstractScene* Help::ChangeScene()
{
	if (Controll::JudgeChatteButton(XINPUT_BUTTON_A) == true)
	{
		return new Title();
	}

	return this;
}

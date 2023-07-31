#include <string.h>
#include "DxLib.h"
#include "Title.h"
#include "Controll.h"
#include "GameMain.h"
#include "DrawRanking.h"
#include "Help.h"
#include "End.h"

//----------------------------
// コンストラクタ
//----------------------------
Title::Title()
{
	//背景画像データ読み込み
	TitleImage = LoadGraph("Resource/Image/Title.png");

	flgnumber = 0;
	Cursor_Y = 0;
	MenuNumber = 0;
}

void Title::Update() 
{
	flgnumber = Controll::GetJudgeStick(D_STICK_L);


	//カーソル移動
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

	Cursor_Y = MenuNumber * 60;		//カーソル位置
}

void Title::Draw() const 
{
	SetFontSize(80);
	DrawGraph(0, 0, TitleImage, FALSE);
	DrawFormatString(210, 100, 0x000000, "はしをつなげっぱなし!!");

	SetFontSize(70);
	DrawString(540, 360, "Start", 0x000000, TRUE);		//Start文字
	DrawString(540, 420, "Ranking", 0x000000, TRUE);	//Ranking文字
	DrawString(540, 480, "Help", 0x000000, TRUE);		//Help文字
	DrawString(540, 540, "End", 0x000000, TRUE);		//End文字

	DrawTriangle(510, 370 + Cursor_Y, 540, 390 + Cursor_Y, 510, 410 + Cursor_Y, GetColor(255, 0, 0), TRUE);		//カーソル
}


AbstractScene* Title::ChangeScene()
{
	//ゲームメイン
	if (MenuNumber == D_TITLE_SELECT_GAME)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new GameMain();
		}
	}

	//ランキング
	if (MenuNumber == D_TITLE_SELECT_RANKING)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new DrawRanking();
		}
	}

	//ヘルプ
	if (MenuNumber == D_TITLE_SELECT_HELP)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new Help();
		}
	}

	//エンド
	if (MenuNumber == D_TITLE_SELECT_END)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
		{
			return new End();
		}
	}

	return this;
}
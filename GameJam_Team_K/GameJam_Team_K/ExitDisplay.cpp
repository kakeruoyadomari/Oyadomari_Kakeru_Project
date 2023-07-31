#include "ExitDisplay.h"
#include"Controll.h"
#include"DrawBoxUI.h"

ExitDisplay::ExitDisplay()
{
	exitFlg = false;
	retryFlg = false;
	helpFlg = false;
	titleFlg = false;
	selectX = 0;
	selectY = 0;
	select = 0;
	flgnumber = 0;

	pauseImage = LoadGraph("Resource/Image/Ranking.png");
}

void ExitDisplay::Update()
{
	if (helpFlg == false)
	{
		flgnumber = Controll::GetJudgeStick(D_STICK_L);
	}

	if (flgnumber == 1) {
		++selectX;
		if (selectX > 1) {
			selectX = 0;
		}
	}
	else if (flgnumber == 2) {
		--selectX;
		if (selectX < 0) {
			selectX = 1;
		}
	}

	if (flgnumber == 3) {
		++selectY;
		if (selectY > 1) {
			selectY = 0;
		}
	}
	else if (flgnumber == 4) {
		--selectY;
		if (selectY < 0) {
			selectY = 1;
		}
	}

	select = selectX + ((selectY) * 2);

	if (select == 0) {
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A)) {
			//ゲーム再開フラグ
			retryFlg = true;
		}
	}
	else if (select == 1) {
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A)) {
			//HELPフラグ
			helpFlg = !helpFlg;
		}
	}
	else 	if (select == 2) {
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A)) {
			//ゲーム再開フラグ
			titleFlg = true;
		}
	}
	else 	if (select == 3) {
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A)) {
			//ゲーム再開フラグ
			exitFlg = true;
		}
	}

}

void ExitDisplay::Draw() const
{

	//背景
	DrawGraph(0, 0, pauseImage, FALSE);

	if (select == 0) {
		//再開選択中
		DrawBoxUI::DrawBoxUIString(300, 100, "CLOSE MENU", 50, 0xFF0000, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 100, "HELP", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(300, 500, "TITLE", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 500, "EXIT GAME", 50, 0x0000FF, 0x0000FF);

	}
	else if (select == 1)
	{
		//HELP選択中
		DrawBoxUI::DrawBoxUIString(300, 100, "CLOSE MENU", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 100, "HELP", 50, 0xFF0000, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(300, 500, "TITLE", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 500, "EXIT GAME", 50, 0x0000FF, 0x0000FF);

		//HELP画面
		if (helpFlg == true)
		{
			DrawGraph(0, 0, pauseImage, FALSE);
			SetFontSize(50);
			DrawString(100, 180, "             ～～遊び方～～            ", 0xffffff, 0);
			DrawString(100, 260, "このゲームは上下にスライドするブロックを", 0xffffff, 0);
			DrawString(100, 320, "タイミングを合わせて繋げていくゲームです。", 0xffffff, 0);
			DrawString(100, 380, "繋げるのに失敗したり,2マス以上の段差を作ると", 0xffffff, 0);
			DrawString(100, 440, "　　　　　　ゲームオーバーです。　　　　　", 0xffffff, 0);

			SetFontSize(30);
			DrawString(320, 660, "    ---- [A]ボタンを押して戻る ----     ", 0xffff00, 0);
		}
		
	}
	else if (select == 2)
	{
		//TITLE選択中
		DrawBoxUI::DrawBoxUIString(300, 100, "CLOSE MENU", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 100, "HELP", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(300, 500, "TITLE", 50, 0xFF0000, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 500, "EXIT GAME", 50, 0x0000FF, 0x0000FF);
	}
	else if (select == 3)
	{
		//終了選択中
		DrawBoxUI::DrawBoxUIString(300, 100, "CLOSE MENU", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 100, "HELP", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(300, 500, "TITLE", 50, 0x0000FF, 0x0000FF);
		DrawBoxUI::DrawBoxUIString(800, 500, "EXIT GAME", 50, 0xFF0000, 0x0000FF);
	}
	else {
		DrawBoxUI::DrawBoxUIString(300, 100, "ERROR", 50, 0x0000FF, 0x0000FF);

	}

}

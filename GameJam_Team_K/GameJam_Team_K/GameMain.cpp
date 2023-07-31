#include "DxLib.h"
#include "GameMain.h"
#include "Controll.h"
#include "Title.h"
#include "InputRanking.h"


//コンストラクタ
GameMain::GameMain()
{
	timer = 0;

	backGroundImage[0] = LoadGraph("Resource/Image/backGround_asa.png");
	backGroundImage[1] = LoadGraph("Resource/Image/backGround_yuugata.png");
	backGroundImage[2] = LoadGraph("Resource/Image/backGround_yoru.png");
	backGround = 0;

	world = new World();
}



//更新
void GameMain::Update() 
{
	timer++;
	if (timer <= 1800)
	{
		backGround = backGroundImage[0];
	}
	else if (timer > 1800 && timer <= 3600)
	{
		backGround = backGroundImage[1];
	}
	else if (timer > 3600)
	{
		backGround = backGroundImage[2];
	}
	if (timer >= 5400)
	{
		timer = 0;
	}

	world->Update();
}



//描画
void GameMain::Draw() const 
{
	DrawExtendGraph(0, 0, 1280, 720, backGround, FALSE);
	world->DrawBlock();
}



//シーン切り替え
AbstractScene* GameMain::ChangeScene()
{
	if (world->GetGameOver() == true)
	{
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A) == true)
		{
			return new InputRanking(world->GetScore());
		}
	}
	return this;
}
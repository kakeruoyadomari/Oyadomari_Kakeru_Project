#include "End.h"

End::End()
{
	endImage = LoadGraph("Resource/Image/Ranking.png");

	waitTime = 0;
	posY = 0;
}

void End::Update()
{
	//エンディングスクロール
	if (++waitTime < 600) posY = 300 - waitTime / 2;
}

void End::Draw() const
{
	SetFontSize(24);
	DrawGraph(0, 0, endImage, FALSE);
	DrawString(100, 170 + posY, "タイトル　　　はしをつなげっぱなし", 0xFFFFFF);
	DrawString(100, 200 + posY, "バージョン　　1.0", 0xFFFFFF);
	DrawString(100, 230 + posY, "制作者　　　　国際電子ビジネス専門学校", 0xFFFFFF);
	DrawString(100, 260 + posY, "　　　　　　　☆親泊 翔", 0xFFFFFF);
	DrawString(100, 290 + posY, "　　　　　　　・阿次富 心", 0xFFFFFF);
	DrawString(100, 320 + posY, "　　　　　　　・當銘 耀斗", 0xFFFFFF);
	DrawString(100, 350 + posY, "　　　　　　　・松竹 武人", 0xFFFFFF);
	DrawString(100, 380 + posY, "　　　　　　　・横田 雷揮", 0xFFFFFF);
	DrawString(100, 410 + posY, "　　　　　　　・菅 翔希", 0xFFFFFF);
}

AbstractScene* End::ChangeScene()
{
	if (++waitTime > 1000)
	{
		return nullptr;
	}
	return this;
}

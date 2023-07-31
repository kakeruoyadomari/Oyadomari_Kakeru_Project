#include "DxLib.h"
#include "Controll.h"
#include "DrawRanking.h"
#include "Title.h"


DrawRanking::DrawRanking()
{
	RankingImage = LoadGraph("Resource/Image/Ranking.png");
	titleFlg = false;

	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	fp = fopen("Resource/Score/Score.txt", "r");

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < RANK_MAX; i++) {
		fscanf(fp, "%2d %10d", &g_Ranking[i].no, &g_Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);
}

void DrawRanking::Update()
{
	if (Controll::JudgeChatteButton(XINPUT_BUTTON_A))
	{
		titleFlg = true;
	}
}

void DrawRanking::Draw() const
{
	DrawGraph(0, 0, RankingImage, FALSE);

	SetFontSize(65);
	DrawFormatString(500, 100, 0xFFFFFF, "Ranking!!");
	for (int i = 0; i < RANK_MAX; i++)
	{
		DrawFormatString(500, 300 + i * 70, 0xffffff, "%2d %5d", g_Ranking[i].no, g_Ranking[i].score);
	}

	SetFontSize(40);
	DrawString(280, 660, "---- [A]を押してタイトルへ戻る　----", 0xFFFFFF, 0);
}

AbstractScene* DrawRanking::ChangeScene()
{
	if (titleFlg == true)
	{
		return new Title();
	}

	return this;
}

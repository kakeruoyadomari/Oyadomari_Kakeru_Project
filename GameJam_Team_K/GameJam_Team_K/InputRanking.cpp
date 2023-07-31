#include "DxLib.h"
#include "InputRanking.h"
#include "DrawRanking.h"

InputRanking::InputRanking(int gameScore)
{
	this->gameScore = gameScore;
	ReadRanking();
}

void InputRanking::ReadRanking()
{
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

void InputRanking::SortRanking()
{
	int i, j;
	RankingData work;

	for (int i = 0; i < RANK_MAX - 1; i++) {
		for (int j = i + 1; j < RANK_MAX; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}
	// 順位付け
	for (i = 0; i < RANK_MAX; i++) {
		g_Ranking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位にする
	// 同順位があった場合の次の順位はデータ個数が加算された順位にする
	for (int i = 0; i < RANK_MAX - 1; i++) {
		for (int j = i + 1; j < RANK_MAX; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}

void InputRanking::SaveRanking()
{
	FILE* fp;
	// ファイルを開く
	fopen_s(&fp, "Resource/Score/Score.txt", "w");	//wは書き込み
	if (fp != NULL) {
		// ランキングデータ分、配列データを書き込む
		for (int i = 0; i < RANK_MAX; i++) {
			fprintf(fp, "%d %d\n", g_Ranking[i].no, g_Ranking[i].score);
		}
		//ファイルを閉じる
		fclose(fp);
	}
}

void InputRanking::Update()
{
	if (gameScore >= g_Ranking[RANK_MAX - 1].score)
	{
		g_Ranking[RANK_MAX - 1].score = gameScore;
		g_Ranking[RANK_MAX - 1].no = RANK_MAX;
		SortRanking();
		SaveRanking();
	}
}

void InputRanking::Draw() const
{

}

AbstractScene* InputRanking::ChangeScene()
{
	return new DrawRanking();
}

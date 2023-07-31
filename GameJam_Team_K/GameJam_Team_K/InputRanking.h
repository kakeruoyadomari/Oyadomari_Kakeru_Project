#pragma once
#include "AbstractScene.h"


#define RANK_MAX 3

struct RankingData 
{
	int no;
	long score;
};

class InputRanking : public AbstractScene
{
private:
	struct RankingData g_Ranking[RANK_MAX];		//ランキングデータ変数
	int gameScore;

public:
	InputRanking(int gameScore);

	void ReadRanking();
	void SortRanking();
	void SaveRanking();

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理
};


#pragma once
#include "AbstractScene.h"
#include "InputRanking.h"

class DrawRanking : public AbstractScene
{
private:
	int RankingImage;
	bool titleFlg;

	struct RankingData g_Ranking[RANK_MAX];		//ランキングデータ変数

public:
	DrawRanking();


	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理
};


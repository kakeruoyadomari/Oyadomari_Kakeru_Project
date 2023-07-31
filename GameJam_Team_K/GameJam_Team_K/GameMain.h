#pragma once
#include "AbstractScene.h"
#include "World.h"


class GameMain : public AbstractScene
{
private:
	World* world;

	int backGroundImage[3];		//背景画像配列
	int backGround;				//背景画像格納用
	int timer;					//背景画像切り替え用タイマー

public:
	//コンストラクタ
	GameMain();


	World GetWorld() { return *world; }

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理
};
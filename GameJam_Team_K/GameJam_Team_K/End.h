#pragma once
#include "AbstractScene.h"

class End : public AbstractScene
{
private:
	int endImage;			//end画像

	int waitTime;			//スクロール用時間変数
	int posY;				//スクロース用座標

public:
	End();

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理

};


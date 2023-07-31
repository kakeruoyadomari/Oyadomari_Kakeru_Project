#pragma once
#include "AbstractScene.h"

class Help : public AbstractScene
{
private:
	int helpImage;								//Help背景画像

public:
	Help();

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理
};


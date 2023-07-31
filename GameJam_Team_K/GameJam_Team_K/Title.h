#pragma once
#include "AbstractScene.h"

#define D_SCREEN_WIDTH 1280
#define D_SCREEN_HEIGHT 720
#define D_PRESS_FONTSIZE 36
#define D_TITLE_FONTSIZE 120
#define D_TITLE_SELECT_GAME		0
#define D_TITLE_SELECT_RANKING	1
#define D_TITLE_SELECT_HELP		2
#define D_TITLE_SELECT_END		3

class Title : public AbstractScene 
{
private:
	int flgnumber;
	int MenuNumber;
	int Cursor_Y;

	int TitleImage;
public:
	Title();

	// デストラクタ
	~Title() 
	{

	};

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理
};

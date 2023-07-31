#pragma once
#define D_BLOCK_SIZE 20
#define D_WORLD_HEIGHT 36
#define D_WORLD_WIDTH 64

class World
{
private:
	//ブロックの配列リスト
	int blockList[4][4][3] =
	{
		{
			{1,1,1},
			{1,1,1},
			{1,1,1},
			{1,1,1}
		},

		{
			{0,0,0},
			{1,1,1},
			{1,1,1},
			{0,0,0}
		},

		{
			{0,0,0},
			{1,0,0},
			{1,1,0},
			{1,1,1}
		},

		{
			{0,0,0},
			{0,0,1},
			{0,1,1},
			{1,1,1}
		},
	};

	int player[3] = { 8,8,8	};					//Player情報
	int jumpHeight;								//Playerが登れる高さ

	int nowBlock[4][4];							//置くブロック
	int world[D_WORLD_HEIGHT][D_WORLD_WIDTH];	//World分割
	int block_x, block_y;						//置くブロックの位置

	int overnum;								//ラインを超えた列数

	int makeGroundLeft;
	int groundHeight;							//地面の高さ

	int score;									//Score

	int moveTime;								//nowBlockの上下移動タイマー

	bool gameOver;								//GameOverFlg

	int blockImage;
	int playerImage;							//Player画像
	bool resultFlg;								//RezultFlg
	int resultTime;								//Result表示時間

public:
	World();									//コンストラクタ

	void CreateBlock();							//次のブロック作成
	void MoveBlock();							//ブロックの上下移動
	int CheckOverlap(int x2, int y2);			//ブロックとステージが繋がるか
	void LockBlock(int x2, int y2);				//ブロックをステージに固定
	void OverLineBlock();						//ステージがどれだけラインを超えているか
	void LeftBring();							//ステージをラインまで詰める

	void MakeGround();							//崖生成

	void SetPlayer();							//Player位置更新

	int GetScore() { return score; }
	bool GetGameOver() { return gameOver; }

	void DrawResult();							//Result描画

	void Update();								//更新
	void DrawBlock();							//描画

};
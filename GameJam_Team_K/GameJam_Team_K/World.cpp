#include "DxLib.h"
#include "World.h"
#include "Controll.h"

World::World()
{
	SetFontSize(60);
	block_x = 15;
	block_y = 3;
	jumpHeight = D_BLOCK_SIZE;
	score = 0;
	makeGroundLeft = 0;
	groundHeight = 0;
	moveTime = 0;
	gameOver = false;
	resultFlg = false;
	resultTime = 0;
	blockImage = LoadGraph("Resource/Image/mokuzai_n.png");
	playerImage = LoadGraph("Resource/Image/runman4.png");

	for (int i = 0; i < D_WORLD_HEIGHT; i++)
	{
		for (int j = 0; j < D_WORLD_WIDTH; j++)
		{
			if ( i == 0 || i == 35)
			{
				world[i][j] = 9;
			}
			else if((j >= 0 && j < 10) && i > 20)
			{
				world[i][j] = 1;
			}
			else
			{
				world[i][j] = 0;
			}

		}
	}
	CreateBlock();		//次のブロック作成
	SetPlayer();		//Player位置更新
}



//次のブロック生成
void World::CreateBlock()
{
	//ランダム選択
	int r = GetRand(3);

	//新しいブロックをセット
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			nowBlock[i][j] = blockList[r][i][j];
		}
	}
}



//ブロックの上下移動
void World::MoveBlock()
{
	moveTime++;
	if (moveTime <= 56)
	{
		if (moveTime % 2 == 0)
		{
			block_y++;			//下移動
		}
	}
	else if (moveTime >= 56)
	{
		if (moveTime % 2 == 0)
		{
			block_y--;			//上移動
		}

		if (moveTime == 112)
		{
			moveTime = 0;		//リセット
		}
	}
}



//ブロックがステージと繋がるかの判定
//引数：ブロックのX座標、ブロックのY座標
int World::CheckOverlap(int x2, int y2)
{
	//接触の確認
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (nowBlock[i][j] != 0)
			{
				if (world[y2 + i][x2 + j] != 0 && world[y2 + i][x2 + j] != 8)
				{
					return 1;	//1なら接触
				}
			}
		}
	}
	return 0;	//0なら非接触
}



//ブロックをステージに固定する
//引数：ブロックX座標、ブロックY座標
void World::LockBlock(int x2, int y2)
{
	//ブロックを固定する
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (nowBlock[i][j] != 0)
			{
				world[y2 + i][x2 + j] = nowBlock[i][j];
			}
		}
	}
}



//ステージがどれだけラインを超えているかの確認
void World::OverLineBlock()
{
	overnum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j < 34; j++)
		{
			if (world[j][10 + i] != 0)
			{
				overnum++;
				break;
			}
		}
	}
}



//ラインまで左に詰める
void World::LeftBring()
{
	for (int i = 0; i < overnum; i++)
	{
		for (int j = 0; j < D_WORLD_HEIGHT - 1; j++)
		{
			for (int k = 0; k < D_WORLD_WIDTH - 1; k++)
			{
				world[j][k] = world[j][k+1];
			}
		}
		MakeGround();			//崖の作成
		SetPlayer();			//Playerの位置更新
		score = score + 10;
	}
}



//崖の作成
void World::MakeGround()
{
	//スコア300毎に崖を作成する
	if ((score % 300) == 0)
	{
		makeGroundLeft = 3;
		groundHeight = GetRand(25);
	}
	if (makeGroundLeft > 0)
	{
		for (int i = groundHeight; i < (35 - 5); i++)
		{
			world[i + 5][D_WORLD_WIDTH - 3] = 1;
		}
		makeGroundLeft--;
	}
}



//Playerの位置更新
void World::SetPlayer()
{
	for (int i = 0; i < D_WORLD_HEIGHT - 1; i++)
	{
		//上から一番近い地面を探す
		if (world[i][5] != 0 && world[i][5] != 9 && world[i][5] != 8)
		{
			if (jumpHeight - i >= 2)
			{
				resultFlg = true;
				break;
				//ここでゲームオーバー
			}
			jumpHeight = i;
			for (int j = 0; j < 3; j++)
			{
				i--;
				if (i < 0) i = 0;
				world[i][5] = player[j];
			}
			break;
		}
	}
}


//Resultの表示
void World::DrawResult()
{
	resultTime++;
	DrawBox(426, 240, 852, 480, 0x00ff00, true);
	DrawFormatString(500, 320, 0xffffff, "SCORE:%d", score);

	if (gameOver == true)
	{
		SetFontSize(24);
		DrawFormatString(600, 450, 0xff0000, "PLESS:A");
	}
}


//更新
void World::Update()
{
	if (resultFlg == false)
	{
		MoveBlock();
		if (Controll::JudgeChatteButton(XINPUT_BUTTON_A) == true)
		{
			block_x = 10;
			//ブロックが繋がるかの判定
			while ((CheckOverlap(block_x - 1, block_y) == 0))
			{
				block_x--;
			}

			if (block_x > 0)
			{
				LockBlock(block_x, block_y);	//ブロックをステージに固定
			}
			else	//ブロックを固定するステージが無い
			{
				resultFlg = true;
				//ここでゲームオーバー
			}
			block_x = 15;

			OverLineBlock();		//ステージがどれだけラインを超えているかの確認
			LeftBring();			//ラインまで左に詰める
			CreateBlock();			//次のブロック作成
		}
	}
	else
	{
		resultTime++;
		if (resultTime > 180)
		{
			resultTime = 0;
			gameOver = true;
		}
	}
}



//描画
void World::DrawBlock()
{
	//ステージ表示
	for (int i = 0; i < D_WORLD_HEIGHT; i++)
	{
		for (int j = 0; j < D_WORLD_WIDTH; j++)
		{
			if (world[i][j] == 1)
			{
				DrawExtendGraph(j * D_BLOCK_SIZE, i * D_BLOCK_SIZE, j * D_BLOCK_SIZE + 20, i * D_BLOCK_SIZE + 20, blockImage, false);
			}
		}
	}

	//Player表示
	DrawGraph(4 * D_BLOCK_SIZE, (jumpHeight - 3 )* D_BLOCK_SIZE, playerImage, false);

	SetFontSize(20);

	//次のブロック表示
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nowBlock[j][i] != 0)
			{
				DrawFormatString((block_x + i) * D_BLOCK_SIZE, (block_y + j) * D_BLOCK_SIZE, 0xffffff, "■", nowBlock[i][j]);
			}
		}
	}
	SetFontSize(60);

	//罫線
	for (int x = 0; x < 1280;)
	{
		DrawLine(x, 0, x, 720, 0x49677D);
		x += 20;
	}

	for (int y = 0; y < 720;)
	{
		DrawLine(0, y, 1280, y, 0x49677D);
		y += 20;
	}

	DrawLine(200, 0, 200, 720, 0xff00ff);
	DrawFormatString(0, 50, 0xff0000, "score:%d", score);


	//Result表示
	if (resultFlg == true)
	{
		DrawResult();
	}

}

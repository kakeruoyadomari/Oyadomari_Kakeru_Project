#pragma once
#define D_BLOCK_SIZE 20
#define D_WORLD_HEIGHT 36
#define D_WORLD_WIDTH 64

class World
{
private:
	//�u���b�N�̔z�񃊃X�g
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

	int player[3] = { 8,8,8	};					//Player���
	int jumpHeight;								//Player���o��鍂��

	int nowBlock[4][4];							//�u���u���b�N
	int world[D_WORLD_HEIGHT][D_WORLD_WIDTH];	//World����
	int block_x, block_y;						//�u���u���b�N�̈ʒu

	int overnum;								//���C���𒴂�����

	int makeGroundLeft;
	int groundHeight;							//�n�ʂ̍���

	int score;									//Score

	int moveTime;								//nowBlock�̏㉺�ړ��^�C�}�[

	bool gameOver;								//GameOverFlg

	int blockImage;
	int playerImage;							//Player�摜
	bool resultFlg;								//RezultFlg
	int resultTime;								//Result�\������

public:
	World();									//�R���X�g���N�^

	void CreateBlock();							//���̃u���b�N�쐬
	void MoveBlock();							//�u���b�N�̏㉺�ړ�
	int CheckOverlap(int x2, int y2);			//�u���b�N�ƃX�e�[�W���q���邩
	void LockBlock(int x2, int y2);				//�u���b�N���X�e�[�W�ɌŒ�
	void OverLineBlock();						//�X�e�[�W���ǂꂾ�����C���𒴂��Ă��邩
	void LeftBring();							//�X�e�[�W�����C���܂ŋl�߂�

	void MakeGround();							//�R����

	void SetPlayer();							//Player�ʒu�X�V

	int GetScore() { return score; }
	bool GetGameOver() { return gameOver; }

	void DrawResult();							//Result�`��

	void Update();								//�X�V
	void DrawBlock();							//�`��

};
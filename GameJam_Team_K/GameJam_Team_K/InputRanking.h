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
	struct RankingData g_Ranking[RANK_MAX];		//�����L���O�f�[�^�ϐ�
	int gameScore;

public:
	InputRanking(int gameScore);

	void ReadRanking();
	void SortRanking();
	void SaveRanking();

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};


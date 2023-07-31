#pragma once
#include "AbstractScene.h"
#include "InputRanking.h"

class DrawRanking : public AbstractScene
{
private:
	int RankingImage;
	bool titleFlg;

	struct RankingData g_Ranking[RANK_MAX];		//�����L���O�f�[�^�ϐ�

public:
	DrawRanking();


	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};


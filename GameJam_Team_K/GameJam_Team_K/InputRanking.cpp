#include "DxLib.h"
#include "InputRanking.h"
#include "DrawRanking.h"

InputRanking::InputRanking(int gameScore)
{
	this->gameScore = gameScore;
	ReadRanking();
}

void InputRanking::ReadRanking()
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	fp = fopen("Resource/Score/Score.txt", "r");

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANK_MAX; i++) {
		fscanf(fp, "%2d %10d", &g_Ranking[i].no, &g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}

void InputRanking::SortRanking()
{
	int i, j;
	RankingData work;

	for (int i = 0; i < RANK_MAX - 1; i++) {
		for (int j = i + 1; j < RANK_MAX; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}
	// ���ʕt��
	for (i = 0; i < RANK_MAX; i++) {
		g_Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂɂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂɂ���
	for (int i = 0; i < RANK_MAX - 1; i++) {
		for (int j = i + 1; j < RANK_MAX; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}

void InputRanking::SaveRanking()
{
	FILE* fp;
	// �t�@�C�����J��
	fopen_s(&fp, "Resource/Score/Score.txt", "w");	//w�͏�������
	if (fp != NULL) {
		// �����L���O�f�[�^���A�z��f�[�^����������
		for (int i = 0; i < RANK_MAX; i++) {
			fprintf(fp, "%d %d\n", g_Ranking[i].no, g_Ranking[i].score);
		}
		//�t�@�C�������
		fclose(fp);
	}
}

void InputRanking::Update()
{
	if (gameScore >= g_Ranking[RANK_MAX - 1].score)
	{
		g_Ranking[RANK_MAX - 1].score = gameScore;
		g_Ranking[RANK_MAX - 1].no = RANK_MAX;
		SortRanking();
		SaveRanking();
	}
}

void InputRanking::Draw() const
{

}

AbstractScene* InputRanking::ChangeScene()
{
	return new DrawRanking();
}

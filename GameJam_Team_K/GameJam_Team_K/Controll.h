#pragma once
#include"DxLib.h"

#define DEADZONE_STICK_ 23000
#define MIX_STICK 10000
#define STICK_LX 1
#define STICK_LY 2
#define STICK_RX 3
#define STICK_RY 4
#define D_STICK_L 1
#define D_STICK_R 2

class Controll
{
private:
	static XINPUT_STATE nowkey;		//���݂̓���
	static XINPUT_STATE oldkey;		//�Â�����
	static XINPUT_STATE keyflg;		//���݂̃L�[
	static float angle;				//�X�e�B�b�N����̃A���O��
	static bool lockFlg;			//���Ă��邩�̃t���O
	static bool stickFlg;			//�X�e�B�b�N�𓮂����Ă��邩�̃t���O
	static int reflg;				//�X�e�B�b�N�̖߂�l�Ɏg���Ă���
public:
	Controll();

	//���݂̃L�[�̎擾
	static XINPUT_STATE GetKey() { return nowkey; }

	//���݂̃{�^���i�`���^�i�V�j
	static bool JudgeButton(unsigned char data) {
		if (nowkey.Buttons[data] == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	//���݂̃{�^���i�`���^�A���j
	static bool JudgeChatteButton(unsigned char data) {
		if (keyflg.Buttons[data] == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	//���݂̃{�^���i�����[�X�j
	static bool JudgeReleaseButton(unsigned char data) {
		if (oldkey.Buttons[data] == 1 && nowkey.Buttons[data] == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//���݂̃X�e�B�b�N
	static short GetStick(int data) {
		switch (data)
		{
		case 1:
			return nowkey.ThumbLX;
			break;
		case 2:
			return nowkey.ThumbLY;
			break;
		case 3:
			return nowkey.ThumbRX;
			break;
		case 4:
			return nowkey.ThumbRY;
			break;
		default:
			break;
		}
		return short(-128);
	}

	//�����Ńf�t�@�C���̃X�e�B�b�N����āAX+�Ȃ�1�EX-�Ȃ�Q Y+�Ȃ�3�AY-�Ȃ�4���A���Ă���A����ȊO��0
	static int GetJudgeStick(int data);

	//���݂̃X�e�B�b�N����̃A���O��
	static float GetNowAngle();

	static void Update();
};
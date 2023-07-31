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
	static XINPUT_STATE nowkey;		//現在の入力
	static XINPUT_STATE oldkey;		//古い入力
	static XINPUT_STATE keyflg;		//現在のキー
	static float angle;				//スティックからのアングル
	static bool lockFlg;			//見ているかのフラグ
	static bool stickFlg;			//スティックを動かしているかのフラグ
	static int reflg;				//スティックの戻り値に使っている
public:
	Controll();

	//現在のキーの取得
	static XINPUT_STATE GetKey() { return nowkey; }

	//現在のボタン（チャタナシ）
	static bool JudgeButton(unsigned char data) {
		if (nowkey.Buttons[data] == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	//現在のボタン（チャタアリ）
	static bool JudgeChatteButton(unsigned char data) {
		if (keyflg.Buttons[data] == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	//現在のボタン（リリース）
	static bool JudgeReleaseButton(unsigned char data) {
		if (oldkey.Buttons[data] == 1 && nowkey.Buttons[data] == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//現在のスティック
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

	//引数でデファインのスティック入れて、X+なら1・X-なら２ Y+なら3、Y-なら4が帰ってくる、それ以外は0
	static int GetJudgeStick(int data);

	//現在のスティックからのアングル
	static float GetNowAngle();

	static void Update();
};
#include "Controll.h"
#include <math.h>

XINPUT_STATE Controll::nowkey{};
XINPUT_STATE Controll::oldkey{};
XINPUT_STATE Controll::keyflg{};
float Controll::angle = 0;
bool Controll::lockFlg = false;
bool Controll::stickFlg = false;
int Controll::reflg = 0;

Controll::Controll()
{

}

//引数でデファインのスティック入れて、X+なら1・X-なら２ Y+なら3、Y-なら4が帰ってくる、それ以外は0
int Controll::GetJudgeStick(int data)
{
	switch (data)
	{
	case 1:
		if (stickFlg == false) {
			if (nowkey.ThumbLX >= DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 1;
			}
			else if (nowkey.ThumbLX <= -DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 2;
			}
			else if (nowkey.ThumbLY >= DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 3;
			}
			else if (nowkey.ThumbLY <= -DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 4;
			}
			else {
				reflg = 0;
			}
		}
		else {
			if ((nowkey.ThumbLX <= DEADZONE_STICK_ && nowkey.ThumbLX >= -DEADZONE_STICK_)
				&& (nowkey.ThumbLY <= DEADZONE_STICK_ && nowkey.ThumbLY >= -DEADZONE_STICK_)) {
				stickFlg = false;
			}
			else {
				reflg = 0;
			}
		}
		return reflg;
		break;
	case 2:
		if (stickFlg == false) {
			if (nowkey.ThumbRX >= DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 1;
			}
			else if (nowkey.ThumbRX <= -DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 2;
			}
			else if (nowkey.ThumbRY >= DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 3;
			}
			else if (nowkey.ThumbRY <= -DEADZONE_STICK_) {
				stickFlg = true;
				reflg = 4;
			}
			else {
				reflg = 0;
			}

		}
		else {
			if ((nowkey.ThumbRX <= DEADZONE_STICK_ && nowkey.ThumbRX >= -DEADZONE_STICK_)
				&& (nowkey.ThumbRY <= DEADZONE_STICK_ && nowkey.ThumbRY >= -DEADZONE_STICK_)) {
				stickFlg = false;
			}
			else {
				reflg = 0;
			}
		}
		return reflg;
		break;
	default:
		stickFlg = false;
		return 0;
		break;
	}
}

float Controll::GetNowAngle()
{
	if (nowkey.Buttons[XINPUT_BUTTON_LEFT_SHOULDER] == true) {
		lockFlg = true;
	}
	else {
		lockFlg = false;
	}

	if (lockFlg == false) {
		if (oldkey.ThumbRX != 128 || oldkey.ThumbRY != 128) {
			angle = atan2f(oldkey.ThumbRY - 128, oldkey.ThumbRX - 128);
		}
		else if (oldkey.ThumbLX != 128 || oldkey.ThumbLY != 128) {
			angle = atan2f(oldkey.ThumbLY - 128, oldkey.ThumbLX - 128);
		}
	}
	else {

	}

	return angle;
}

void Controll::Update()
{
	//ここで古いボタンの更新
	for (int i = 0; i < 16; i++) {
		oldkey.Buttons[i] = nowkey.Buttons[i];
	}

	GetJoypadXInputState(DX_INPUT_PAD1, &nowkey);
	for (int i = 0; i < 16; i++) {
		keyflg.Buttons[i] = nowkey.Buttons[i] & ~oldkey.Buttons[i];
	}

	if (nowkey.ThumbLX >= DEADZONE_STICK_ || nowkey.ThumbLY >= DEADZONE_STICK_ ||
		nowkey.ThumbLX <= -DEADZONE_STICK_ || nowkey.ThumbLY <= -DEADZONE_STICK_) {
		oldkey.ThumbLX = nowkey.ThumbLX;
		oldkey.ThumbLY = nowkey.ThumbLY;
	}
	else {
		oldkey.ThumbLX = 128;
		oldkey.ThumbLY = 128;

	}

	if (nowkey.ThumbRX >= DEADZONE_STICK_ || nowkey.ThumbRY >= DEADZONE_STICK_
		|| nowkey.ThumbRX <= -DEADZONE_STICK_ || nowkey.ThumbRY <= -DEADZONE_STICK_) {
		oldkey.ThumbRX = nowkey.ThumbRX;
		oldkey.ThumbRY = nowkey.ThumbRY;
	}
	else {
		oldkey.ThumbRX = 128;
		oldkey.ThumbRY = 128;
	}


}
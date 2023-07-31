#pragma once
#include"DxLib.h"
#include<iostream>
#include<string>

using namespace std;

class DrawBoxUI
{
public:

	/*DrawBoxUIString(int x, int y, string str, int fontSize, int backColor, int frontColor)
	���WX,Y�@������(�p���̂�)�@�t�H���g�T�C�Y�@�{�b�N�X�̔w�i�@�{�b�N�X�̑O�ʐF�@*/
	static void DrawBoxUIString(int x, int y, const TCHAR* str, int fontSize, unsigned int backColor, unsigned int frontColor);

	/*DrawChargeBox(float x, float y, float width, float height, float value, unsigned int color, unsigned int type)
	���WX,Y�@�傫��Width,Height�@ChargeValue�@�F�@�c���̃^�C�v(0:�c 1:��)*/
	static void DrawChargeBox(float x, float y, float width, float height, float value, unsigned int color, unsigned int type);

};


#pragma once
#include"DxLib.h"

#define AVERAGE_FPS 60 //���ς����T���v����
#define ATTACH_FLAME 60 //�ݒ肵��FPS

class  FrameRateControll 
{
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
public:
	FrameRateControll() 
	{
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update();

	void Draw();

	void Wait();
};


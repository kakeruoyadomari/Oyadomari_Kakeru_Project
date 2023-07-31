#pragma once
class ExitDisplay
{
private:
	bool exitFlg;
	bool retryFlg;
	bool helpFlg;
	bool titleFlg;
	int selectX;
	int selectY;
	int select;
	int flgnumber;

	int pauseImage;

public:
	ExitDisplay();

	void Update();
	void Draw() const;
	bool GetExitFlg() { return exitFlg; }
	bool GetRetryFlg() { return retryFlg; }
	bool GetHelpFlg() { return helpFlg; }
	bool GetTitleFlg() { return titleFlg; }
};


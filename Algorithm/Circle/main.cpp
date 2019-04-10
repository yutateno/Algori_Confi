#include "DxLib.h"
#include <math.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	double x1 = 320, y1 = 240;
	double x2 = 80, y2 = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawCircle(static_cast<int>(x1), static_cast<int>(y1), 2, 255, true);
		DrawCircle(static_cast<int>(x2 + x1), static_cast<int>(y2 + y1), 2, 255, true);

		if (CheckHitKey(KEY_INPUT_A) >= 1)
		{
			double xd = x2 * cos(DX_PI_F / 180) - y2 * sin(DX_PI_F / 180);
			double yd = x2 * sin(DX_PI_F / 180) + y2 * cos(DX_PI_F / 180);
			x2 = xd;
			y2 = yd;
		}
		if (CheckHitKey(KEY_INPUT_D) >= 1)
		{
			double xd = x2 * cos(-DX_PI_F / 180) - y2 * sin(-DX_PI_F / 180);
			double yd = x2 * sin(-DX_PI_F / 180) + y2 * cos(-DX_PI_F / 180);
			x2 = xd;
			y2 = yd;
		}
	}

	DxLib_End();
	return 0;
}
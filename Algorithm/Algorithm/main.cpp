#include "Input.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	int mouseX, mouseY;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		KeyData::UpDate();
		MouseData::Mouse_UpDate();
		MouseWheelData::MouseWheel_Update();

		GetMousePoint(&mouseX, &mouseY);

		if (mouseX >= 320)
		{
			printfDx("�E\n");
		}
		if (mouseY >= 240)
		{
			printfDx("��\n");
		}

		if (MouseData::GetClick(0) == 1)	// 0: 1: 2:
		{
			printfDx("���N���b�N\n");
		}

		if (MouseWheelData::GetMouseWheel(GetMouseWheelRotVol()) >= 1)
		{
			printfDx("�O�z�C�[\n");
		}
		if (MouseWheelData::GetMouseWheel(GetMouseWheelRotVol()) <= -1)
		{
			printfDx("���z�C�[\n");
		}
	}

	DxLib_End();
	return 0;
}
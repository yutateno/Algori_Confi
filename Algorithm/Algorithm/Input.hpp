#pragma once
#include "DxLib.h"

// �L�[�{�[�h�̓��͏��
class KeyData
{
private:
	static int key[256];	// �L�[�̓��͏�Ԋi�[�p�ϐ�
	static char tmpKey[256];	// ���݂̃L�[�̓��͏�Ԃ��i�[����

public:
	KeyData();
	~KeyData();

	static void UpDate();	// �L�[���͂̏�ԍX�V
	static int Get(int KeyCode);	// �L�[���͏�Ԏ擾
	static bool CheckEnd();	// �����I��
};


class MouseData
{
private:
	static int m_Mouse[3];
	static int MouseInput;

public:
	MouseData();
	~MouseData();

	static void Mouse_UpDate(); //�}�E�X�̃N���b�N�̏�Ԃ��X�V����
	static int GetClick(int MouseCode); //�}�E�X�̃N���b�N�̏�Ԃ�Ԃ�
};


class MouseWheelData
{
private:
	static int m_MouseWheel;
	static int old_MouseWheel;

public:
	MouseWheelData();
	~MouseWheelData();

	static void MouseWheel_Update(); //�}�E�X�̃z�C�[���̏�Ԃ��X�V
	static int GetMouseWheel(int MouseWheelCode); //�}�E�X�z�C�[���̏�Ԃ�Ԃ�
};
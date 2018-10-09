#include "input.hpp"

//////////////////////////////////////////////�L�[�{�[�h////////////////////////////////////////////////////
KeyData::KeyData()
{

}

KeyData::~KeyData()
{

}

int KeyData::key[256];
char KeyData::tmpKey[256];

void KeyData::UpDate()
{
	KeyData::tmpKey[256];			// ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(KeyData::tmpKey);	// �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++)
	{
		// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		if (KeyData::tmpKey[i] != 0)
		{
			KeyData::key[i]++;   // ���Z
		}
		// �L�[�������ꂽ�u��
		else if (KeyData::key[i] > 0)
		{
			KeyData::key[i] = -1; // -1�ɂ���
		}
		// ����ȊO
		else
		{
			KeyData::key[i] = 0; // 0�ɂ���
		}
	}
}

bool KeyData::CheckEnd()
{
	return KeyData::key[KEY_INPUT_ESCAPE] <= 0;
}

int KeyData::Get(int KeyCode)
{
	return KeyData::key[KeyCode];
}


//////////////////////////////////////////////�}�E�X�֘A////////////////////////////////////////////////////

MouseData::MouseData()
{

}

MouseData::~MouseData()
{

}

int MouseData::m_Mouse[3];
int MouseData::MouseInput;

void MouseData::Mouse_UpDate() {
	MouseInput = GetMouseInput();    //�}�E�X�̉�������Ԏ擾
	for (int i = 0; i < 3; i++) {
		if ((MouseInput & 1 << i) != 0) {
			m_Mouse[i]++;   //������Ă�����J�E���g�A�b�v
		}
		else {
			m_Mouse[i] = 0; //������ĂȂ�������0
		}
	}
}

int MouseData::GetClick(int MouseCode) {
	return m_Mouse[MouseCode];
}

//////////////////////////////////////////////�}�E�X�z�C�[���֘A////////////////////////////////////////////////////
MouseWheelData::MouseWheelData()
{

}

MouseWheelData::~MouseWheelData()
{

}

int MouseWheelData::m_MouseWheel;
int MouseWheelData::old_MouseWheel;

void MouseWheelData::MouseWheel_Update() {
	old_MouseWheel = m_MouseWheel;
	if (old_MouseWheel - m_MouseWheel > 0) {
		m_MouseWheel++;
	}
	else if (old_MouseWheel - m_MouseWheel < 0) {
		m_MouseWheel--;
	}
	else {
		m_MouseWheel = 0;
	}
}

int MouseWheelData::GetMouseWheel(int MouseWheelCode) {
	return m_MouseWheel += MouseWheelCode;
}
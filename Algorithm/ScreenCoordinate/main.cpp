#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1024, 768, 32);
	DxLib_Init();

	// �r���[�s��Ǝˉe�s��̎擾
	MATRIX view = GetCameraViewMatrix();
	MATRIX proj = GetCameraProjectionMatrix();

	// �r���[�|�[�g�s��i�X�N���[���s��j�̍쐬
	float w = 1024.0f / 2.0f;
	float h = 768.0f / 2.0f;

	MATRIX viewport = {
		w , 0 , 0 , 0 ,
		0 ,-h , 0 , 0 ,
		0 , 0 , 1 , 0 ,
		w , h , 0 , 1
	};

	VECTOR screenPos, tmp = VGet(320.0f, 200.0f, 0.0f);
	// �r���[�ϊ��ƃv���W�F�N�V�����ϊ�
	tmp = VTransform(tmp, view);
	tmp = VTransform(tmp, proj);
	// z�Ŋ�����-1~1�͈̔͂Ɏ��߂�
	tmp.x /= tmp.z; tmp.y /= tmp.z; tmp.z /= tmp.z;
	// �X�N���[���ϊ�
	screenPos = VTransform(tmp, viewport);


	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);

	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);

	// �R�c��ԏ�ɋ���`�悷��
	DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

	DrawCircle(static_cast<int>(screenPos.x), static_cast<int>(screenPos.y), 10, 255, true);

	// �L�[���͑҂�������
	WaitKey();

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
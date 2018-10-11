//#include "Camera.hpp"
//
//
//// �R���X�g���N�^
//Camera::Camera()
//{
//	cameraArea = VGet(0, 350, 0);
//
//	circleArea = Vector2(0.0f, 100.0f);
//
//	speed = DX_PI_F / 180;
//	angle = 0.0f;
//
//	SetCameraNearFar(1.0f, 5000.0f);	// �J�����̕`��͈͂��w��
//
//	// �������̎��_����������̃^�[�Q�b�g������p�x�ɃJ������ݒu
//	SetCameraPositionAndTarget_UpVecY(cameraArea, VAdd(cameraArea, VGet(circleArea.x, -200.0f, circleArea.y)));
//}
//
//// �f�X�g���N�^
//Camera::~Camera()
//{
//}
//
//const VECTOR Camera::GetArea() const
//{
//	return cameraArea;
//}
//
//
//// ���C���v���Z�X
//void Camera::Process(int mouseX, int mouseY)
//{
//	SetCameraPositionAndTarget_UpVecY(cameraArea, VAdd(cameraArea, VGet(circleArea.x, 0.0f, circleArea.y + 50.0f)));
//}
//
//
//// ang�p��]����
//void Camera::RLrotate(const float speed, VECTOR& p_cameraArea)
//{
//	float tempX = p_cameraArea.x;
//	p_cameraArea.x = tempX * cosf(speed) + p_cameraArea.z *sinf(speed);
//	p_cameraArea.z = -tempX * sinf(speed) + p_cameraArea.z * cosf(speed);
//}
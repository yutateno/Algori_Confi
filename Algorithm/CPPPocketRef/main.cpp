#include <iostream>



// �񋓌^�̊�b�ƂȂ�^��ύX
enum class EnumChangeType : char { Red = 'a', Green, Blue };



// �ϒ��e���v���[�g�̗v�f�������߂�
template<class... Types>
struct S {
	static const size_t count = sizeof...(Types);
};



// ���ۃN���X(���ۃN���X�͂̃I�u�W�F�N�g�͐������邱�Ƃ��ł��Ȃ�
class Shape {
public:
	virtual void Draw(int x, int y, int width, int height) = 0;
};

// ���ۃN���X��p���Ďl�p�`��`�悷��N���X
class Box : public Shape {
public:
	void Draw(int x, int y, int width, int height) override {
		std::cout << "�l�p�`��`�悷��" << std::endl;
	}
};



int main()
{
	S<int, char, double> t;
	std::cout << t.count << std::endl;

	// Box* b = new Shape();
	Box* b = new Box();
	b->Draw(0, 0, 1, 1);

	return 0;
}
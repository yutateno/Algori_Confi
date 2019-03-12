#include <iostream>
#include <limits>
#include <complex>
#include <memory>
#include <iomanip>
#include <vector>

using namespace std;


// auto �� template �̈Ⴂ�Q�l�F<https://qiita.com/_EnumHack/items/a3724dead343b5aecb4e>
auto AB(int a)
{
	return a + 1;
}
template<typename T>
T BC(T a, T b)
{
	return a * b;
}


// �ċA�t�B�{�i�b�`����֐�
int Fibonacci(int n)
{
	if (n < 3) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}


// �ċA�K��֐�
int Factorial(int n)
{
	if (n < 2) return 1;
	return n * Factorial(n - 1);
}


// �����̎Q��
void FuncRefe1(int& x) { cout << "int&\t" << ++x << endl; }
// �����̕ύX�s�Q��
void FuncRefe2(const int& x) { cout << "const int&\t" << x + 1 << endl; }
// �����̉E�Ӓl�Q��
void FuncRefe3(int&& x) { cout << "int&&\t" << ++x << endl; }
// �����̕ύX�s�E�Ӓl�Q��
void FuncRefe4(const int&& x) { cout << "const int&&\t" << x + 1 << endl; }
// �A�h���X�̃R�s�[
void FuncPoin1(int* p) { cout << "int*\t" << ++(*p) << endl; }
// �ύX�s�A�h���X�̃R�s�[
void FuncPoin2(const int* p) { cout << "const int*\t" << (*p) + 1 << endl; }


int main()
{
	// ���l�̏���l
	cout << numeric_limits<size_t>::lowest() << endl;
	cout << numeric_limits<size_t>::max() << endl << endl;


	// �|�C���^��{
	int a = 10;
	int* pA = &a;
	int** ppA = &pA;
	a = 30;
	cout << **ppA << "\t" << *pA << "\t" << a << endl;
	**ppA = 20;
	cout << **ppA << "\t" << *pA << "\t" << a << endl << endl;


	// ���̕]���ɂ�镛��p
	int b = 10;
	cout << (b = 20) << endl;
	cout << b << endl;
	cout << (b = 1, b = 2) << endl << endl;


	// 16�i���\��
	cout << hexfloat << 0.1f  << endl;
	cout << defaultfloat << 0.1f << endl << endl;


	// ���f��
	using cplx = complex<double>;
	cplx c{};
	cout << c << endl;
	c = { 3.,4. };
	cplx d{ c };
	cout << d << endl;
	cout << d.real() << "\t" << d.imag() << endl;


	/*
	�����������F�I�u�W�F�N�g�������I�ɊǗ�����郁�����B�T�C�Y�͔�r�I�������i��1MB�j�B
		�X�^�b�N���邢�̓X�^�b�N�������A�X�^�b�N�L���̈�A�����L���̈�Ƃ��Ă΂��B
		�u���b�N�i�X�R�[�v�j�̏I���ŉ�̂����B
	�t���[�X�g�A�F�I�u�W�F�N�g���v���O���}���Ǘ����郁�����B�T�C�Y�͔�r�I�傫���B
		���I��������q�[�v�A�󂫗̈�Ƃ��Ă΂��B
		�v���O�������I�����Ȃ��Ǝc�葱����B�����I�ɉ�̂��K�v�B

	new ���g��Ȃ��Ő��������I�u�W�F�N�g�́A�����������B
	new ���g���Đ��������I�u�W�F�N�g�́A�t���[�X�g�A�B
	*/


	// �X�}�[�g�|�C���^ �Q�l�F<https://qiita.com/hmito/items/db3b14917120b285112f>
	// unique_ptr �̕��� shared_ptr ��葬�����Ashared_ptr �̕����ȒP
	unique_ptr<cplx> e = make_unique<cplx>();
	cout << *e << endl;
	auto f = make_unique<cplx>(3., 4.);
	cout << *f << endl;
	unique_ptr<cplx> g = move(e);
	if (e) cout << "e�ɏ��L��������(�󂶂�Ȃ�)" << *g << endl;
	else cout << "e�ɏ��L�����Ȃ�(��ł���)" << *g << endl << endl;
	// e.reset();
	f.reset();
	g.reset();


	// 3������
	for (int i = 0; i != 10; ++i)
	{
		for (int j = 0; j != 10; ++j)
		{
			cout << setw(3) << i * j;
		}
		cout << endl;
	}
	cout << endl;
	

	// ASCII�R�[�h
	cout << " | 0 1 2 3 4 5 6 7 8 9 A B C D E F" << endl;
	cout << "-|--------------------------------" << endl;
	char ch = 0x20;
	for (int i = 2; i != 8; ++i)
	{
		cout << i << '|';
		for (int j = 0; j != 16; ++j)
		{
			cout << ' ' << ch++;
		}
		cout << endl;
	}
	cout << endl;


	// �t�B�{�i�b�`����
	for (int i = 1; i != 10; ++i)
	{
		cout << i << "\t" << Fibonacci(i) << endl;
	}
	cout << endl;


	// �K��
	for (int i = 0; i != 10; ++i)
	{
		cout << i << "\t" << Factorial(i) << endl;
	}
	cout << endl;


	int h = 100;

	h = 100;
	cout << h << endl;
	FuncRefe1(h);
	cout << h << endl;
	//FuncRefe1(100);
	cout << endl;

	h = 100;
	cout << h << endl;
	FuncRefe2(h);
	cout << h << endl;
	//FuncRefe2(100);
	cout << endl;

	h = 100;
	cout << h << endl;
	FuncRefe3(static_cast<int&&>(h));
	cout << h << endl;
	//FuncRefe3(100);
	cout << endl;

	h = 100;
	cout << h << endl;
	FuncRefe4(static_cast<int&&>(h));
	cout << h << endl;
	//FuncRefe4(100);
	cout << endl;

	h = 100;
	int* A = &h;
	cout << h << endl;
	FuncPoin1(&h);
	cout << h << endl;
	//FuncPoin1(A);
	cout << endl;

	h = 100; 
	A = &h;
	cout << h << endl;
	FuncPoin2(&h);
	cout << h << endl;
	//FuncPoin2(A);
	cout << endl;

	
	// vector
	vector<int> v{ 2,3,5,7 };
	for (auto x : v) cout << x << ",";
	cout << endl << endl;

	
	// for auto �Q�Ƃɂ�鐔�l���Z
	for (auto& x : v) ++x;
	for (auto x : v) cout << x << ",";
	cout << endl << endl;


	/*
	vector
	capacity : �m�ۂ��Ă�������m�F�ł���
	reserve : �m�ۂ���������炩���ߎw��ł���
	pop_back : �w��̗v�f�̍폜
	erase : �w��̗v�f�̍폜
	*/


	/*
	list
	�����ȊO�ł̗v�f�̒ǉ���폜���N����ꍇ
	*/


	/*
	unorderd_map
	�v�f��p�ɂɌ�������ꍇ
	*/

	return 0;
}
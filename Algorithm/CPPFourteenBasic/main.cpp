#include <iostream>
#include <limits>
#include <complex>
#include <memory>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <utility>


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



// �X�}�[�g�|�C���^�֐��z��n��
auto FuncSmartPtr()
{
	unique_ptr<int[]> a(new int[4]{ 2,3,4,5 });
	return a;
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
	cout << hexfloat << 0.1f << endl;
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



	/// �ċA�֘A------------------------------------------------------
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
	/// �ċA�֘A------------------------------------------------------



	// vector
	vector<int> v{ 2,3,5,7 };
	for (auto x : v) cout << x << ",";
	cout << endl << endl;



	// for auto �Q�Ƃɂ�鐔�l���Z
	for (auto& x : v) ++x;
	for (auto x : v) cout << x << ",";
	cout << endl << endl << endl;



	/*
	vector
	capacity : �m�ۂ��Ă�������m�F�ł���
	reserve : �m�ۂ���������炩���ߎw��ł���
	pop_back : �w��̗v�f�̍폜
	erase : �w��̗v�f�̍폜

	begin() / end() : �擪�Ɩ����̎��������C�e���[�^�B++�Ō��ɐi�ށB
	cbegin() / cend() : �O�q�̂��̂�const�n�B
	rbegin() / rend() : �擪�Ɩ����̑O���w���C�e���[�^�B++�őO�ɐi�ށB
	crbegin() / crend() : �O�q�̂��̂�const�n�B
	*/



	/*
	list
	�����ȊO�ł̗v�f�̒ǉ���폜���N����ꍇ
	*/



	/*
	unorderd_map
	�v�f��p�ɂɌ�������ꍇ
	*/



	/// unordered_map-----------------------------------------------
	unordered_map<string, int> dictionary{
		{"one", 1}
		,{"two", 2}
		,{"three", 3}
	};



	// �\���e�X�g
	cout << "two: " << dictionary.at("two") << endl;
	cout << "two: " << dictionary["two"] << endl;
	cout << "two change: " << (dictionary["two"] = 1) << endl;
	cout << "two change: " << (dictionary["two"] = 2) << endl << endl;



	// ���ǉ��e�X�g
	cout << "num: " << dictionary.size() << endl;
	cout << "four: " << dictionary["four"] << endl;
	cout << "num: " << dictionary.size() << endl;
	if (dictionary.find("five") == dictionary.end()) {}
	cout << "num: " << dictionary.size() << endl;
	dictionary["six"] = 6;
	cout << "num: " << dictionary.size() << endl << endl;



	// ���[�v�\��
	for (const auto& p : dictionary)
	{
		cout << p.first << ": " << p.second << endl;
	}



	// �I�u�W�F�N�g�쐬
	unordered_map<string, cplx> dic;
	dic["A"] = cplx(5., 12.);
	dic.emplace("B", 10);
	for (const auto& p : dic)
	{
		cout << p.first << ": " << p.second << endl;
	}
	cout << endl << endl;
	/// unordered_map-----------------------------------------------



	// �قȂ�^�ł܂Ƃ߂�(pair, tuple
	auto Jiro = make_pair("Jiro", 28);
	pair<string, int> taro("Taro", 32);

	auto ryouko = make_tuple("Ryoko", 18, 110.0f);
	tuple<string, int, double> hanako("Hanako", 26, 120.0);



	// �X�}�[�g�|�C���^�z��n��
	auto smartPtr = FuncSmartPtr();
	for (size_t i = 0; i != 4; ++i)
	{
		cout << smartPtr[i] << ",";
	}
	cout << endl << endl;



	// string
	string str1 = "Hello";
	cout << str1[4] << endl;														// 4�����ڏo��
	cout << str1.find("l") << endl;													// �����T��
	if (str1.find("HELLO") == string::npos) { cout << "������Ȃ�" << endl; }		// �����T��
	cout << str1.rfind("l") << endl;												// (��납��)�����T��
	{ // �����u������
		str1.replace(2, 3, "LLO");
		cout << str1 << endl;
	}
	cout << str1.substr(1, 2) << endl;												// �����o��
	cout << endl << endl;



	/// �}�j�s�����[�^--------------------------------------------------------------------------------------------------
	// boolalpha;			// bool�^�̒l��true/false�ŏo�͂���B
	// noboolalpha;			// bool�^�̒l��0/1�ŏo�͂���B

	// showbase;			// 8�i���̑O��0���A16�i���̑O��0x���o�͂���B
	// noshowbase;			// 8�i���̑O��0���A16�i���̑O��0x���o�͂��Ȃ��B

	// showpoint;			// �����I�ɏ����_���o�͂���B
	// noshowpoint;			// �����I�ɏ����_���o�͂��Ȃ��B

	// showpos;				// ���������o�͂���B
	// noshowpos;			// ���������o�͂��Ȃ��B

	// skipws;				// �󔒂�ǂݔ�΂��B
	// noskipws;			// �󔒂�ǂݔ�΂��Ȃ��B

	// uppercase;			// 16�i����啶���ŏo�͂���B
	// nouppercase;			// 16�i�����������ŏo�͂���B

	// internal;			// ���������[�ɁA���̑��͉E�[�ŏo�͂���B

	// left;				// ���񂹂ŏo�͂���B

	// right;				// �E�[�ŏo�͂���B

	// dec;					// 10�i���ŏo�͂���B
	
	// hex;					// 16�i���ŏo�͂���B

	// oct;					// 8�i���ŏo�͂���B

	// fixed;				// ���������_��0.1234�Ƃ����`���ŏo�͂���B

	// scientific;			// ���������_��1.234000e-001�Ƃ����`���ŏo�͂���B

	// hexfloat;			// ���������_��0x1.123abcp+1�Ƃ����`���ŏo�͂���B

	// defaultfloat;		// ���������_���f�t�H���g�ɖ߂��B

	// endl;				// '\n'��ǉ����ăt���b�V������B������\n�ŉ��s��������������������������B

	// ends;				// '\0'��ǉ����ăt���b�V������B

	// flush;				// �t���b�V������B�ʐM�n�Ŋ��p�B

	// ws;					// �󔒂���������B

	// resetiosflags(0);	// �t���O�����Z�b�g����B	<https://cpprefjp.github.io/reference/iomanip/resetiosflags.html>

	// setiosflags(0);		// �t���O���Z�b�g����B

	// setbase(8);			// �����ϐ��̐���i���l(8/10/16)�Ƃ��ďo�͂���B

	// setfill(0);			// �������s�����镪���������l�Ŗ��߂�B

	// setw(0);				// �������l���s���l�Ƃ��ďo�͂���B
	/// �}�j�s�����[�^--------------------------------------------------------------------------------------------------



	// ���K�\��



	return 0;
}
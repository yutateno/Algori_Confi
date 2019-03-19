#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <map>
#include <cfenv>
#include <string>
#include <cassert>


using namespace std;



// �����l�����������p�N���X
class A
{
public:
	int a;
	void DoSomething() { cout << "Hello" << endl; }
	A() { a = 0; }
	~A() { cout << "A�I�u�W�F�N�g�͉�̂��ꂽ" << endl; }
};

class B
{
public:
	A* pA;
	B() :pA(new A()) {}
	~B() { delete pA; }
};



// �W�F�l���b�N�v���O���~���O
class Circle
{
public:
	Circle() {}
	~Circle() {}
	void Draw() { cout << "�Z" << endl; }
};

class Rectangle
{
public:
	Rectangle() {}
	~Rectangle() {}
	void Draw() { cout << "��" << endl; }
};

template<typename T>
void MakeDraw(T t)
{
	t.Draw();
}



// throw��
[[noreturn]]		// �֐�������ɏI�����Ȃ����Ƃɑ΂���R���p�C���̌x����}�~����B
void DoSomething()
{
	throw exception("�����ُ킪�N����");
}





// ���������_����O
void Report_Fexcepts()
{
	if (fetestexcept(FE_DIVBYZERO))	 cout << "FE_DIVBYZERO	 : 0�ɂ�鏜�Z���s��ꂽ"		 << endl;
	if (fetestexcept(FE_INEXACT))	 cout << "FE_INEXACT	 : ���x��������v�Z���s��ꂽ"	 << endl;
	if (fetestexcept(FE_OVERFLOW))	 cout << "FE_OVERFLOW	 : �I�[�o�[�t���[���N������"	 << endl;
	if (fetestexcept(FE_UNDERFLOW))	 cout << "FE_UNDERFLOW	 : �A���_�[�t���[���N������"	 << endl;
	if (fetestexcept(FE_INVALID))	 cout << "FE_INVALID	 : �s���Ȍv�Z���s��ꂽ"		 << endl;
	feclearexcept(FE_ALL_EXCEPT);		// �ُ�̗������폜
	cout << endl;
}



int main()
{
	// ���o��
	// cout				// �W���o��
	// cerr				// �o�b�t�@���g��Ȃ��G���[�o��
	// clog				// �o�b�t�@���g���G���[�o��
	// cin				// �W������
	// ofstream			// �t�@�C���o��
	// ifstream			// �t�@�C������


	// �\�[�g
	vector<int> v{ 2,5,1,7,3,4 };
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << ",";
	cout << endl << endl;


	sort(v.rbegin(), v.rend());
	for (auto i : v) cout << i << ",";
	cout << endl << endl;


	// stable_sort �� sort <https://qiita.com/mima_ita/items/b4cb3be38d64a397216b>
	/*
	stable_sort : 32���܂ő}���\�[�g�A����ȍ~�̓}�[�W�\�[�g�@�������������������
	sort : 32���܂ő}���\�[�g�A����ȍ~�̓N�C�b�N�\�[�g
	stable_sort�̕���sort����0.5�b�قǑ����A�������n���ˑ�
	*/



	// ���`�T��(�O���������ׂĂ����T��
	auto begin = v.cbegin();
	auto end = v.cend();

	int target = 3;
	auto pos = find(begin, end, target);
	if (pos == end) cout << "������Ȃ�" << endl;
	else cout << "��������" << *pos << endl;
	cout << endl << endl;



	// �񕪒T��(�T���𔼕����Ɍ��炵�Ă����ĒT��(�\�[�g�̕K�v��������
	v.clear();
	v = { 503, 87, 512, 61, 908, 170, 897, 275, 200, 426 };

	sort(v.begin(), v.end());
	
	begin = v.cbegin();
	end = v.cend();
	
	target = 200;
	pos = lower_bound(begin, end, target);
	if (pos == end || *pos != target)cout << "������Ȃ�" << endl;
	else cout << "��������" << *pos << endl;
	cout << endl << endl;



	// ���Ԃ̑���
	auto t0 = chrono::high_resolution_clock::now();

	int s = 0;
	for (int i = 0; i != 10000; ++i)
	{
		for (int j = 0; j != 10000; ++j)
		{
			++s;
		}
	}
	cout << s << endl;

	auto t1 = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() / 1000. << "s" << endl;
	cout << endl << endl;



	// ��������
	random_device engine;
	mt19937 mt(engine());
	uniform_int_distribution<unsigned> dist1(1, 6);		// 1~6�𐶐�



	// ��������
	uniform_real_distribution<double> dist2(0.0, 1.0);	// 0.0~1.0�𐶐�



	// ���K���z�ɂ�镽��50�A�W���΍�3�̐��K����
	map<int, int> frequency;
	normal_distribution<double> dist3(50.0, 5.0);
	for (int i = 0; i != 500; ++i)
	{
		double x = dist3(mt);
		++frequency[static_cast<int>(x)];
	}
	for (auto p : frequency)
	{
		cout << p.first << " | ";
		for (int i = 0; i != p.second; ++i)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl;



	// �ő�E�ŏ�
	cout << min(3, 2) << endl;
	cout << max(3, 2) << endl;

	cout << min({ 3,2,1,5 }) << endl;
	cout << max({ 3,2,1,5 }) << endl;

	auto resulut = minmax({ 3,2,1,5 });
	cout << resulut.first << endl;
	cout << resulut.second << endl;
	cout << endl << endl;



	// �����l����������(RAII
	/*
	�A���S���Y����\���Ƃ������l�����ł���
	*/
	B b;
	// return 1;
	// b.pA->DoSomething();



	// ���[�u�R���X�g���N�^ p215
	// <https://ja.cppreference.com/w/cpp/language/move_constructor>
	// <https://marycore.jp/prog/cpp/move-constructor/>



	// �������z�֐�
	/*
	virtual void Draw() = 0;
	�Ⴆ�Ί��N���X��Draw�̒��g�𖾎����邱�Ƃ��o���Ȃ��ꍇ
	���̂悤�ȃN���X�𒊏ۃN���X�ƌĂ�

	virtual void Draw() {}
	���̂悤�Ȋ֐��͉��z�֐��ƌĂ�

	�ǂ���ɂ��Ă��h���N���X�Ń����o�֐��̍Ē�`�ƌ��� override ��t����(���ۂɂ͕t���Ȃ��Ă��������t��������������₷��)
	*/



	// �W�F�l���b�N�v���O���~���O �^�Ɉˑ����Ȃ��`
	Circle c;
	MakeDraw(c);
	Rectangle r;
	MakeDraw(r);
	cout << endl << endl;



	// try-catch��O����
	vector<int> ve{ 2,3,4 };
	int a = 0;
	try
	{
		//// �|��������s���܂��񂪁A�t���[�X�g�A���Ȃ��Ȃ�Ɨ�O����������B
		//while (true)
		//{
		//	int* p = new int[0x1fffffff];
		//	cout << p << endl;
		//}

		a = stoi("987654321987654321");		// int�̍ő�l�𒴂���
		cout << a << endl;

		a = stoi("abc");					// �^�ϊ�
		cout << a << endl;

		cout << ve.at(3) << endl;			// �z��O�Q��
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl << endl;


	//// try-catch�����Ȃ��Ńt���[�X�g�A���Ȃ��Ȃ����� nullptr ���Ԃ��悤�ɂȂ�
	//while (true)
	//{
	//	int* p = new(nothrow) int[0x1fffffff];
	//	if (p != nullptr)
	//	{
	//		cout << p << endl;
	//	}
	//	else
	//	{
	//		cout << "failure" << endl;
	//	}
	//}



	// throw���Œ��ړn��
	try
	{
		DoSomething();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl << endl;



	// �A�T�[�V���� Debug�̂ݎ��s�����Release�ł͎��s����Ȃ�
	int low = 10;
	int high = 2;

	// assert(low < high);



	return 0;
}
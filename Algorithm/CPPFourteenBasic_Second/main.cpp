#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <map>


using namespace std;


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




	return 0;
}
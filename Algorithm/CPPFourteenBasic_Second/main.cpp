#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <map>


using namespace std;


int main()
{
	// 入出力
	// cout				// 標準出力
	// cerr				// バッファを使わないエラー出力
	// clog				// バッファを使うエラー出力
	// cin				// 標準入力
	// ofstream			// ファイル出力
	// ifstream			// ファイル入力


	// ソート
	vector<int> v{ 2,5,1,7,3,4 };
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << ",";
	cout << endl << endl;


	sort(v.rbegin(), v.rend());
	for (auto i : v) cout << i << ",";
	cout << endl << endl;


	// stable_sort と sort <https://qiita.com/mima_ita/items/b4cb3be38d64a397216b>
	/*
	stable_sort : 32件まで挿入ソート、それ以降はマージソート　早いがメモリを消費する
	sort : 32件まで挿入ソート、それ以降はクイックソート
	stable_sortの方がsortよりも0.5秒ほど早い、が処理系環境依存
	*/



	// 線形探索(前から一つずつ調べていく探索
	auto begin = v.cbegin();
	auto end = v.cend();

	int target = 3;
	auto pos = find(begin, end, target);
	if (pos == end) cout << "見つからない" << endl;
	else cout << "見つかった" << *pos << endl;
	cout << endl << endl;



	// 二分探索(探索を半分ずつに減らしていって探索(ソートの必要性がある
	v.clear();
	v = { 503, 87, 512, 61, 908, 170, 897, 275, 200, 426 };

	sort(v.begin(), v.end());
	
	begin = v.cbegin();
	end = v.cend();
	
	target = 200;
	pos = lower_bound(begin, end, target);
	if (pos == end || *pos != target)cout << "見つからない" << endl;
	else cout << "見つかった" << *pos << endl;
	cout << endl << endl;



	// 時間の測定
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



	// 正数乱数
	random_device engine;
	mt19937 mt(engine());
	uniform_int_distribution<unsigned> dist1(1, 6);		// 1~6を生成



	// 実数乱数
	uniform_real_distribution<double> dist2(0.0, 1.0);	// 0.0~1.0を生成



	// 正規分布による平均50、標準偏差3の正規乱数
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
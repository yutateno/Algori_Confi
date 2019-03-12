#include <iostream>
#include <limits>
#include <complex>
#include <memory>
#include <iomanip>
#include <vector>

using namespace std;


// auto と template の違い参考：<https://qiita.com/_EnumHack/items/a3724dead343b5aecb4e>
auto AB(int a)
{
	return a + 1;
}
template<typename T>
T BC(T a, T b)
{
	return a * b;
}


// 再帰フィボナッチ数列関数
int Fibonacci(int n)
{
	if (n < 3) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}


// 再帰階乗関数
int Factorial(int n)
{
	if (n < 2) return 1;
	return n * Factorial(n - 1);
}


// 引数の参照
void FuncRefe1(int& x) { cout << "int&\t" << ++x << endl; }
// 引数の変更不可参照
void FuncRefe2(const int& x) { cout << "const int&\t" << x + 1 << endl; }
// 引数の右辺値参照
void FuncRefe3(int&& x) { cout << "int&&\t" << ++x << endl; }
// 引数の変更不可右辺値参照
void FuncRefe4(const int&& x) { cout << "const int&&\t" << x + 1 << endl; }
// アドレスのコピー
void FuncPoin1(int* p) { cout << "int*\t" << ++(*p) << endl; }
// 変更不可アドレスのコピー
void FuncPoin2(const int* p) { cout << "const int*\t" << (*p) + 1 << endl; }


int main()
{
	// 数値の上限値
	cout << numeric_limits<size_t>::lowest() << endl;
	cout << numeric_limits<size_t>::max() << endl << endl;


	// ポインタ基本
	int a = 10;
	int* pA = &a;
	int** ppA = &pA;
	a = 30;
	cout << **ppA << "\t" << *pA << "\t" << a << endl;
	**ppA = 20;
	cout << **ppA << "\t" << *pA << "\t" << a << endl << endl;


	// 式の評価による副作用
	int b = 10;
	cout << (b = 20) << endl;
	cout << b << endl;
	cout << (b = 1, b = 2) << endl << endl;


	// 16進数表示
	cout << hexfloat << 0.1f  << endl;
	cout << defaultfloat << 0.1f << endl << endl;


	// 複素数
	using cplx = complex<double>;
	cplx c{};
	cout << c << endl;
	c = { 3.,4. };
	cplx d{ c };
	cout << d << endl;
	cout << d.real() << "\t" << d.imag() << endl;


	/*
	自動メモリ：オブジェクトが自動的に管理されるメモリ。サイズは比較的小さい（約1MB）。
		スタックあるいはスタックメモリ、スタック記憶領域、自動記憶領域とも呼ばれる。
		ブロック（スコープ）の終わりで解体される。
	フリーストア：オブジェクトをプログラマが管理するメモリ。サイズは比較的大きい。
		動的メモリやヒープ、空き領域とも呼ばれる。
		プログラムを終了しないと残り続ける。明示的に解体が必要。

	new を使わないで生成したオブジェクトは、自動メモリ。
	new を使って生成したオブジェクトは、フリーストア。
	*/


	// スマートポインタ 参考：<https://qiita.com/hmito/items/db3b14917120b285112f>
	// unique_ptr の方が shared_ptr より速いが、shared_ptr の方が簡単
	unique_ptr<cplx> e = make_unique<cplx>();
	cout << *e << endl;
	auto f = make_unique<cplx>(3., 4.);
	cout << *f << endl;
	unique_ptr<cplx> g = move(e);
	if (e) cout << "eに所有権がある(空じゃない)" << *g << endl;
	else cout << "eに所有権がない(空である)" << *g << endl << endl;
	// e.reset();
	f.reset();
	g.reset();


	// 3文字分
	for (int i = 0; i != 10; ++i)
	{
		for (int j = 0; j != 10; ++j)
		{
			cout << setw(3) << i * j;
		}
		cout << endl;
	}
	cout << endl;
	

	// ASCIIコード
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


	// フィボナッチ数列
	for (int i = 1; i != 10; ++i)
	{
		cout << i << "\t" << Fibonacci(i) << endl;
	}
	cout << endl;


	// 階乗
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

	
	// for auto 参照による数値加算
	for (auto& x : v) ++x;
	for (auto x : v) cout << x << ",";
	cout << endl << endl;


	/*
	vector
	capacity : 確保している個数を確認できる
	reserve : 確保する個数をあらかじめ指定できる
	pop_back : 指定の要素の削除
	erase : 指定の要素の削除
	*/


	/*
	list
	末尾以外での要素の追加や削除が起こる場合
	*/


	/*
	unorderd_map
	要素を頻繁に検索する場合
	*/

	return 0;
}
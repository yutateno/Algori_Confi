#include <iostream>
#include <limits>
#include <complex>
#include <memory>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <utility>


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



// スマートポインタ関数配列渡し
auto FuncSmartPtr()
{
	unique_ptr<int[]> a(new int[4]{ 2,3,4,5 });
	return a;
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
	cout << hexfloat << 0.1f << endl;
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



	/// 再帰関連------------------------------------------------------
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
	/// 再帰関連------------------------------------------------------



	// vector
	vector<int> v{ 2,3,5,7 };
	for (auto x : v) cout << x << ",";
	cout << endl << endl;



	// for auto 参照による数値加算
	for (auto& x : v) ++x;
	for (auto x : v) cout << x << ",";
	cout << endl << endl << endl;



	/*
	vector
	capacity : 確保している個数を確認できる
	reserve : 確保する個数をあらかじめ指定できる
	pop_back : 指定の要素の削除
	erase : 指定の要素の削除

	begin() / end() : 先頭と末尾の次をさすイテレータ。++で後ろに進む。
	cbegin() / cend() : 前述のもののconst系。
	rbegin() / rend() : 先頭と末尾の前を指すイテレータ。++で前に進む。
	crbegin() / crend() : 前述のもののconst系。
	*/



	/*
	list
	末尾以外での要素の追加や削除が起こる場合
	*/



	/*
	unorderd_map
	要素を頻繁に検索する場合
	*/



	/// unordered_map-----------------------------------------------
	unordered_map<string, int> dictionary{
		{"one", 1}
		,{"two", 2}
		,{"three", 3}
	};



	// 表示テスト
	cout << "two: " << dictionary.at("two") << endl;
	cout << "two: " << dictionary["two"] << endl;
	cout << "two change: " << (dictionary["two"] = 1) << endl;
	cout << "two change: " << (dictionary["two"] = 2) << endl << endl;



	// 個数追加テスト
	cout << "num: " << dictionary.size() << endl;
	cout << "four: " << dictionary["four"] << endl;
	cout << "num: " << dictionary.size() << endl;
	if (dictionary.find("five") == dictionary.end()) {}
	cout << "num: " << dictionary.size() << endl;
	dictionary["six"] = 6;
	cout << "num: " << dictionary.size() << endl << endl;



	// ループ表示
	for (const auto& p : dictionary)
	{
		cout << p.first << ": " << p.second << endl;
	}



	// オブジェクト作成
	unordered_map<string, cplx> dic;
	dic["A"] = cplx(5., 12.);
	dic.emplace("B", 10);
	for (const auto& p : dic)
	{
		cout << p.first << ": " << p.second << endl;
	}
	cout << endl << endl;
	/// unordered_map-----------------------------------------------



	// 異なる型でまとめる(pair, tuple
	auto Jiro = make_pair("Jiro", 28);
	pair<string, int> taro("Taro", 32);

	auto ryouko = make_tuple("Ryoko", 18, 110.0f);
	tuple<string, int, double> hanako("Hanako", 26, 120.0);



	// スマートポインタ配列渡し
	auto smartPtr = FuncSmartPtr();
	for (size_t i = 0; i != 4; ++i)
	{
		cout << smartPtr[i] << ",";
	}
	cout << endl << endl;



	// string
	string str1 = "Hello";
	cout << str1[4] << endl;														// 4文字目出力
	cout << str1.find("l") << endl;													// 文字探索
	if (str1.find("HELLO") == string::npos) { cout << "見つからない" << endl; }		// 文字探索
	cout << str1.rfind("l") << endl;												// (後ろから)文字探索
	{ // 文字置き換え
		str1.replace(2, 3, "LLO");
		cout << str1 << endl;
	}
	cout << str1.substr(1, 2) << endl;												// 部分出力
	cout << endl << endl;



	/// マニピュレータ--------------------------------------------------------------------------------------------------
	// boolalpha;			// bool型の値をtrue/falseで出力する。
	// noboolalpha;			// bool型の値を0/1で出力する。

	// showbase;			// 8進数の前に0を、16進数の前に0xを出力する。
	// noshowbase;			// 8進数の前に0を、16進数の前に0xを出力しない。

	// showpoint;			// 強制的に小数点を出力する。
	// noshowpoint;			// 強制的に小数点を出力しない。

	// showpos;				// 正負号を出力する。
	// noshowpos;			// 正負号を出力しない。

	// skipws;				// 空白を読み飛ばす。
	// noskipws;			// 空白を読み飛ばさない。

	// uppercase;			// 16進数を大文字で出力する。
	// nouppercase;			// 16進数を小文字で出力する。

	// internal;			// 符号を左端に、その他は右端で出力する。

	// left;				// 左寄せで出力する。

	// right;				// 右端で出力する。

	// dec;					// 10進数で出力する。
	
	// hex;					// 16進数で出力する。

	// oct;					// 8進数で出力する。

	// fixed;				// 浮動小数点を0.1234という形式で出力する。

	// scientific;			// 浮動小数点を1.234000e-001という形式で出力する。

	// hexfloat;			// 浮動小数点を0x1.123abcp+1という形式で出力する。

	// defaultfloat;		// 浮動小数点をデフォルトに戻す。

	// endl;				// '\n'を追加してフラッシュする。だから\nで改行した方が少し処理早いかもよ。

	// ends;				// '\0'を追加してフラッシュする。

	// flush;				// フラッシュする。通信系で活用。

	// ws;					// 空白を除去する。

	// resetiosflags(0);	// フラグをリセットする。	<https://cpprefjp.github.io/reference/iomanip/resetiosflags.html>

	// setiosflags(0);		// フラグをセットする。

	// setbase(8);			// 引数変数の数を進数値(8/10/16)として出力する。

	// setfill(0);			// 桁数が不足する分を引数数値で埋める。

	// setw(0);				// 引数数値を行数値として出力する。
	/// マニピュレータ--------------------------------------------------------------------------------------------------



	// 正規表現



	return 0;
}
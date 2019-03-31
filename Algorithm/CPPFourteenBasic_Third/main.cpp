#include "main.hpp"
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <algorithm>


using namespace std;
using namespace std::chrono;


const int M = 100;
mutex m;
vector<int> primes;


// 3の倍数+1となる数だけを調べる
void ThreadFuncA()
{
	for (int i = 4; i <= M; i += 3)
	{
		if (IsPrime(i))
		{
			cout << i << ",";
		}
	}
}



// 3の倍数+2となる数だけを調べる
void ThreadFuncB()
{
	for (int i = 5; i <= M; i += 3)
	{
		if (IsPrime(i))
		{
			cout << i << ",";
		}
	}
}


// 3の倍数+(start - 3)となる数だけを調べる(排他制御
void ThreadFuncC(int N, int start)
{
	for (int i = start; i <= N; i += 3)
	{
		if (IsPrime(i))
		{
			unique_lock<mutex> lock(m);
			cout << i << ",";
		}
	}
}


void ThreadFuncD(int N, int start)
{
	for (int i = start; i <= N; i += 3)
	{
		if (IsPrime(i))
		{
			unique_lock<mutex> lock(m);
			primes.push_back(i);
		}
	}
}


int main()
{
	// 並列化しないで普通に素数列挙を出力
	auto t0 = high_resolution_clock::now();

	const int N = 200000;

	vector<int> prime;

	for (int i = 2; i <= N; ++i)
	{
		if (IsPrime(i))
		{
			prime.push_back(i);
		}
	}

	cout << "素数の音：" << prime.size() << endl;

	Report(prime.cbegin(), prime.cend());

	auto t1 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << "秒\n";


	// 単純並列化素数出力
	cout << "2, 3, ";

	thread threadA(ThreadFuncA);
	thread threadB(ThreadFuncB);

	threadA.join();
	threadB.join();
	cout << endl;


	// 排他制御を行ったうえでの並列化素数出力
	cout << "2, 3, ";
	
	thread threadC(ThreadFuncC, M, 4);
	thread threadD(ThreadFuncC, M, 5);

	threadC.join();
	threadD.join();
	cout << endl;


	// 並列化して素数列挙を出力
	auto t2 = high_resolution_clock::now();

	primes.push_back(2);
	primes.push_back(2);

	thread threadE(ThreadFuncD, N, 4);
	thread threadF(ThreadFuncD, N, 5);

	threadE.join();
	threadF.join();

	cout << "素数の音：" << primes.size() << endl;

	sort(primes.begin(), primes.end());
	Report(primes.cbegin(), primes.cend());

	auto t3 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t3 - t2).count() / 1000. << "秒\n";


	// 並列化方法にthreadではなくOpenMPを使う方法がある
	// <https://www.atmarkit.co.jp/fdotnet/bookpreview/bunpouvcpp_1302/bunpouvcpp_1302_04.html>
	// #include <omp.h>
	// int omp_get_dynaimc();		// スレッド数の動的制御が有効かどうか（0以外なら有効
	// void omp_set_dynamic(int);	// スレッド数の動的制御の有効無効を設定する（引数が0なら無効
	// int omp_get_max_threads();	// 最大のスレッド数を返す
	// int omp_get_nested();		// 並列実行領域のネストが有効かどうかを返す（0以外なら有効
	// void omp_set_nested(int);	// 並列実行領域のネストの有効無効を設定する（引数が0なら無効
	// int omp_get_num_procs();		// プログラムで使用可能なプロセッサ数を返す
	// int omp_get_num_threads();	// 並列実行領域のスレッド数を返す
	// int omp_set_num_threads(int);// 並列実行領域で使用するスレッド数を設定する
	// int omp_get_thread_num();	// 並列スレッドの番号を返す
	// int omp_in_parallel();		// 並列実行中かどうかを返す（0以外なら並列実行中

}
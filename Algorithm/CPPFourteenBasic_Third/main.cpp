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


// 3�̔{��+1�ƂȂ鐔�����𒲂ׂ�
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



// 3�̔{��+2�ƂȂ鐔�����𒲂ׂ�
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


// 3�̔{��+(start - 3)�ƂȂ鐔�����𒲂ׂ�(�r������
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
	// ���񉻂��Ȃ��ŕ��ʂɑf���񋓂��o��
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

	cout << "�f���̉��F" << prime.size() << endl;

	Report(prime.cbegin(), prime.cend());

	auto t1 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << "�b\n";


	// �P�����񉻑f���o��
	cout << "2, 3, ";

	thread threadA(ThreadFuncA);
	thread threadB(ThreadFuncB);

	threadA.join();
	threadB.join();
	cout << endl;


	// �r��������s���������ł̕��񉻑f���o��
	cout << "2, 3, ";
	
	thread threadC(ThreadFuncC, M, 4);
	thread threadD(ThreadFuncC, M, 5);

	threadC.join();
	threadD.join();
	cout << endl;


	// ���񉻂��đf���񋓂��o��
	auto t2 = high_resolution_clock::now();

	primes.push_back(2);
	primes.push_back(2);

	thread threadE(ThreadFuncD, N, 4);
	thread threadF(ThreadFuncD, N, 5);

	threadE.join();
	threadF.join();

	cout << "�f���̉��F" << primes.size() << endl;

	sort(primes.begin(), primes.end());
	Report(primes.cbegin(), primes.cend());

	auto t3 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t3 - t2).count() / 1000. << "�b\n";


	// ���񉻕��@��thread�ł͂Ȃ�OpenMP���g�����@������
	// <https://www.atmarkit.co.jp/fdotnet/bookpreview/bunpouvcpp_1302/bunpouvcpp_1302_04.html>
	// #include <omp.h>
	// int omp_get_dynaimc();		// �X���b�h���̓��I���䂪�L�����ǂ����i0�ȊO�Ȃ�L��
	// void omp_set_dynamic(int);	// �X���b�h���̓��I����̗L��������ݒ肷��i������0�Ȃ疳��
	// int omp_get_max_threads();	// �ő�̃X���b�h����Ԃ�
	// int omp_get_nested();		// ������s�̈�̃l�X�g���L�����ǂ�����Ԃ��i0�ȊO�Ȃ�L��
	// void omp_set_nested(int);	// ������s�̈�̃l�X�g�̗L��������ݒ肷��i������0�Ȃ疳��
	// int omp_get_num_procs();		// �v���O�����Ŏg�p�\�ȃv���Z�b�T����Ԃ�
	// int omp_get_num_threads();	// ������s�̈�̃X���b�h����Ԃ�
	// int omp_set_num_threads(int);// ������s�̈�Ŏg�p����X���b�h����ݒ肷��
	// int omp_get_thread_num();	// ����X���b�h�̔ԍ���Ԃ�
	// int omp_in_parallel();		// ������s�����ǂ�����Ԃ��i0�ȊO�Ȃ������s��

}
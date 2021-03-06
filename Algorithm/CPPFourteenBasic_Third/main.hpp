#pragma once
#include <iostream>



// 引数が素数かどうか
bool IsPrime(int n)
{
	if (n < 2) return false;
	if (n == 2) return true;

	for (int i = 2; i != n; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}



// 要素の最初と最後の5個を表示する
template<typename T>
void Report(T first, T last)
{
	const int num = 5;
	if (last - first < num)
	{
		for (T i = first; i != last; ++i)
		{
			std::cout << *i << ",";
		}
	}
	else
	{
		for (T i = first; i != first + num; ++i)
		{
			std::cout << *i << ",";
		}
		std::cout << std::endl;
		for (T i = last - num; i != last; ++i)
		{
			std::cout << *i << ",";
		}
	}
	std::cout << std::endl;
}
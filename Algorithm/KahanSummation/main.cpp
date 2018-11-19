# include <iostream>
# include <iomanip>

template <class T>
T Sum(T value, size_t count)
{
	T s = 0;

	for (size_t i = 0; i < count; ++i)
	{
		s += value;
	}

	return s;
}

// ƒJƒnƒ“‚Ì‰ÁŽZƒAƒ‹ƒSƒŠƒYƒ€
template <class T>
T SumK(T value, size_t count)
{
	T s = 0;
	T err = 0;

	for (size_t i = 0; i < count; ++i)
	{
		const T y = value - err;
		const T t = s + y;
		err = (t - s) - y;
		s = t;
	}

	return s;
}

int main()
{
	std::cout << std::setprecision(7);
	std::cout << "- float -\n";
	std::cout << Sum<float>(0.01f, 10000) << '\n';
	std::cout << Sum<float>(0.01f, 50000) << '\n';
	std::cout << "- float (Kahan) -\n";
	std::cout << SumK<float>(0.01f, 10000) << '\n';
	std::cout << SumK<float>(0.01f, 50000) << '\n';

	std::cout << std::setprecision(15);
	std::cout << "- double -\n";
	std::cout << Sum<double>(0.01, 10000) << '\n';
	std::cout << Sum<double>(0.01, 50000) << '\n';
	std::cout << "- double (Kahan) -\n";
	std::cout << SumK<double>(0.01, 10000) << '\n';
	std::cout << SumK<double>(0.01, 50000) << '\n';
}
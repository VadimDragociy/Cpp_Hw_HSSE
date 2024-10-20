#include <iostream>

template < auto N > struct Fibbonacci
{
	static constexpr auto value = Fibbonacci< N - 2 >::value + Fibbonacci < N - 1 >::value;
};

template <> struct Fibbonacci < 0 > 
{
	static constexpr auto value = 0; 
};
template <> struct Fibbonacci < 1 > 
{
	static constexpr auto value = 1; 
};

template < auto N > constexpr auto fibbonacciN = Fibbonacci< N > ::value;

int main()
{
	std::cout << fibbonacciN < 8 > << std::endl;

	return 0;
}


#include <iostream>
template < auto N > struct Factorial
{
	static constexpr auto value = N * Factorial < N - 1 > ::value;
};

template <> struct Factorial < 0 > 
{ 
	static constexpr auto value = 1; 
};

template < auto N > constexpr auto factorial_v = Factorial < N > ::value;

template <auto N, auto K> struct BinCoeff
{
	static constexpr auto value = factorial_v<N>/(factorial_v<K>*factorial_v<N-K>);
};

template < auto N, auto M> constexpr auto binCoeffNM = BinCoeff< N, M> ::value;

int main()
{
	std::cout << binCoeffNM < 8, 8 > << std::endl;

	return 0;
}

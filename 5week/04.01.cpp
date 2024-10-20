#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <iostream>

template <typename T>
const T* binary_search(const T* array, std::size_t size, T key)
{
	if (size > 0)
	{
		std::size_t l = 0, r = size - 1, m{};

		while (l < r)
		{		
			array[m = std::midpoint(l, r)] < key ? l = m + 1 : r = m;
		}

		return (array[l] == key ? array + l : nullptr);
	}
	else
	{
		return nullptr;
	}
}

int main()
{
	const std::size_t size = 5;
	const double array[size] { 1.1, 2.1, 3.1, 4.1, 5.1 };

	assert(binary_search(array, size, 1.1) == array + 0);
	assert(binary_search(array, size, 2.1) == array + 1);
	assert(binary_search(array, size, 3.1) == array + 2);
	assert(binary_search(array, size, 4.1) == array + 3);
	assert(binary_search(array, size, 5.1) == array + 4);

	return 0;
}
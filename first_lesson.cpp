#include <iostream>
#include <vector>


long Sum(long N)
{
    long sum = 1, i, beg = 2, d = 1;
    if (N & 1)
    {
        d = 2;
        beg = 3;
    }
    for (i = beg; i * i < N; i += d)
        if (N % i == 0)
            sum += (i + N / i);
    if (i * i == N)
        sum += i;
    return sum;
}
 
int main()
{
    long long M{0}, N{0}, k{0};
    std::cout << "Введите N: ";
    std::cin >> N;

    std::vector<int> vec;

    for (int i = 0; i < N; i++)
       vec.push_back(Sum(i + 1));
    k = 0;
    for (int i = 0; i < N; i++)
        if (vec[i] >= 1 && vec[i] < N && vec[vec[i] - 1] == i + 1 && i + 1 < vec[i])
        {
            std::cout << i + 1 << " " << vec[i] << "; " << vec[i] << " " << i + 1 << std:: endl;
 
            k++;
        }

}
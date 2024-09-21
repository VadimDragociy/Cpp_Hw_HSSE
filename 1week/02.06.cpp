#include <iostream>
#include <unordered_map>
 
long long int ColatzSequece(long long int n)
{
    if (n == 1) return 1;
    static std::unordered_map<long long int, long long int> m;

    if (m.find(n) != m.end()) return(m.find(n) -> second);

    return m[n] = 1 + ColatzSequece(n % 2 == 0 ? n / 2 : n * 3 + 1);
}


int main()
{
    int imax = 1;
    for (auto i = 2; i <= 100; i++) {
        if (ColatzSequece(i) > ColatzSequece(imax)) imax = i;
    }
    std::cout << "Max sequence: " << imax << ", max count: " << ColatzSequece(imax) << std::endl;
}

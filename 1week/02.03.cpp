#include <iostream>
#include <cmath>
#include <vector>

void prime_factors(int N){
    int n = N;
    std::cout << "Prime factors of N: ";

    while(n % 2 == 0)
    {
        std::cout << 2 <<" ";
        n /= 2;
    }

    for (auto i{3}; i <= std::sqrt(N); i+=2){
        while(n % i == 0)
        {
            std::cout << i <<" ";
            n /= i;
        }
    }
    if (n != 1) std::cout << n;

}

int main(){


    int N{0};
    bool flag{true};
    std::cout << "Enter N" << std::endl;
    std::cin >> N;

    prime_factors(N);

}
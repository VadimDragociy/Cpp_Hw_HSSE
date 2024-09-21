#include <iostream>
#include <cmath>
#include <vector>

void _print_prime_factors(std::vector<int>& to_print){
    std::cout << "Prime factors of N: ";

    for(auto i{0}; i < to_print.size(); i++){
        std::cout << to_print[i] << " ";
    }
}

void prime_factors(int N){
    int n = N;
    static std::vector<int> memory;

    while(n % 2 == 0)
    {
        if(memory.size() == 0 || memory.back() != 2) memory.push_back(2);
        n /= 2;
    }

    for (auto i{3}; i <= std::sqrt(N); i+=2){
        while(n % i == 0)
        {
            if(memory.size() == 0 || memory.back() != i) memory.push_back(i);
            n /= i;
        }
    }
    if (n != 1) memory.push_back(n);
    _print_prime_factors(memory);

}

int main(){


    int N{0};
    bool flag{true};
    std::cout << "Enter N" << std::endl;
    std::cin >> N;

    prime_factors(N);

}
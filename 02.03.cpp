#include <iostream>
#include <cmath>

int main(){


    long long int N{0};
    bool flag{true};
    std::cout << "Enter N" << std::endl;
    std::cin >> N;

    for (auto i{2}; i <= N; i++){
        if (N % i != 0) continue;

        for (auto j{2}; j <= std::sqrt(i); j++){
            if(i % j == 0) flag = false;
        }
        if(flag) std::cout << i << std::endl;
        flag = true;
    }

}
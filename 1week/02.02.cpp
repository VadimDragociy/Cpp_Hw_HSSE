#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

int sum_del(int n)
{
    auto j{2};
    auto sum{1};
    while(j <= std::sqrt(n)){
        if (n % j == 0) j != std::sqrt(n) ? sum += j + n/j: sum += j;
        j++;
    }
    return sum;
}

void ArmstrongNumbers(int N)
{
    int num_len{0};
    int i{1};
    auto j{0};
    auto literal{0};
    auto ArmstrongSum{0};

    std::cout << "Armstrong numbers: ";

    while(i<=N){
        num_len = ceil(log10(i));
        j = i;
        while(j != 0){
            literal = j%10;
            ArmstrongSum += pow(literal, num_len);
            j = j / 10;
        }
        if (i == ArmstrongSum) std::cout << i << " ";
        ArmstrongSum = 0;
        i++;
    }
    std::cout << std::endl;
}

void FibbonacciNumbers(int N)
{
    int last{1}, prelast{0}, support{0};

    std::cout << "Fibbonacci Sequence: ";

    while(prelast < N){
        std::cout << prelast << " ";
        support = prelast;
        prelast = last;
        last = support + last;
    }
    std::cout << std::endl;
}

void AbundantNumbers(int N)
{
    int i{1};
    auto sum{0};

    std::cout << "Abudant numbers: ";

    while(i<=N){
        sum = sum_del(i);
        if (i < sum) std::cout << i << " ";

        i++;
    }
    std::cout << std::endl;
}

void FriendlyNumbers(int N)
{
    int i;
    std::vector<int> sum_for_numbers;
    static std::unordered_map<int, int> memory;

    std::cout << "Friendly numbers: ";

    for (i = 0; i < N; i++)
       sum_for_numbers.push_back(sum_del(i));

    for (i = 1; i < N; i++){
        auto sum_i = sum_for_numbers[i];
        if (!(sum_i < N)) continue;

        if (i == sum_for_numbers[sum_i] && sum_i != i && memory.find(sum_i) == memory.end()){
            memory[i] = sum_i;
            std::cout << i << " and " << sum_for_numbers[i] << "; ";
        }
    }
}



int main(){
    int N{0};

    std::cout << "Enter N" << std::endl;
    std::cin >> N;

    ArmstrongNumbers(N);
    FibbonacciNumbers(N);
    AbundantNumbers(N);
    FriendlyNumbers(N);

    std::cout << std::endl << "That`s it";

}
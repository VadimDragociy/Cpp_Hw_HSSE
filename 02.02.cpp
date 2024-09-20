#include <iostream>
#include <cmath>
#include <vector>

int speedpow(int number, int k)
{
    float count{1};
    if (!k) return 1;
    while (k) {
        if (k % 2 == 0) {
            k /= 2;
            number *= number;
        } else {
            k--;
            count *= number;
        }
    }
    return count;
}

long long int sum_del(long long int n)
{
    auto j{2};
    auto sum{1};
    while(j <= std::sqrt(n)){
        if (n % j == 0) j != std::sqrt(n) ? sum += j + n/j: sum += j;
        j++;
    }
    return sum;
}

void ArmstrongNumbers(long long int N)
{
    int num_len{0};
    long long int i{1};
    auto j{0};
    auto literal{0};
    auto ArmstrongSum{0};

    std::cout << "Armstrong numbers: ";

    while(i<=N){
        num_len = ceil(log10(i));
        j = i;
        while(j != 0){
            literal = j%10;
            ArmstrongSum += speedpow(literal, num_len);
            j = j / 10;
        }
        if (i == ArmstrongSum) std::cout << i << " ";
        ArmstrongSum = 0;
        i++;
    }
    std::cout << std::endl;
}

void FibbonacciNumbers(long long int N)
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

void AbundantNumbers(long long int N)
{
    long long int i{1};
    auto sum{0};

    std::cout << "Abudant numbers: ";

    while(i<=N){
        sum = sum_del(i);
        if (i < sum) std::cout << i << " ";

        i++;
    }
    std::cout << std::endl;
}

void FriendlyNumbers(long long int N)
{
    int i, j;
    std::vector<long int> numbers;

    std::cout << "Friendly numbers: ";

    for (i = 0; i < N; i++)
       numbers.push_back(sum_del(i));

    for (i = 1; i < N-1; i++)
        for (j = i + 1; j < N; j++)
            if (i == numbers[j] && j == numbers[i])
                std::cout << i << " and " << j << "; ";
}



int main(){
    long long int N{0};

    std::cout << "Enter N" << std::endl;
    std::cin >> N;

    ArmstrongNumbers(N);
    FibbonacciNumbers(N);
    AbundantNumbers(N);
    FriendlyNumbers(N);

    std::cout << std::endl << "That`s it";

}
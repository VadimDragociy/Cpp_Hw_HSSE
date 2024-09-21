#include <iostream>
#include <vector>


void custom_reverse(std::vector<int>& unreversed){
    auto size = unreversed.size();
    for (int i{0}; i < size/2; i++)
        std::swap(unreversed[i], unreversed[size - i - 1]);

}

int main(){
    std::vector<int> test;
    for (int i = 10; i > 0; i--){
        test.push_back(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;
    custom_reverse(test);
    for (int i = 0; i < 10; i++){
        std::cout << test[i] << " ";
    }
}
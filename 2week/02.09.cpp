#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>& unsorted){
    int min_ind = 0;
    int n = unsorted.size();
    for (int i{0}; i < n - 1; i++){
        min_ind = i;
        for (int j{i + 1}; j < n; j++){
            if (unsorted[j] < unsorted[min_ind]) min_ind = j;
        }
        if(i != min_ind) std::swap(unsorted[i], unsorted[min_ind]);
    }

}

int main() {
    std::vector<int> vec = {10, 7, 8, 9, 1, 5, 119, 6, 4, 11, 12, 12, 5, 7};
    int n = vec.size();
    SelectionSort(vec);

    for (auto i : vec) {
        std::cout << i << " ";
    }
}
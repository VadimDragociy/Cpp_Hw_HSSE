#include <iostream>
#include <vector>


void shellSort(std::vector<int>& unsorted)
{
    int n = unsorted.size();
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = unsorted[i];
            int j{i};        
            for (j; j >= gap && unsorted[j - gap] > temp; j -= gap)
                unsorted[j] = unsorted[j - gap];

            unsorted[j] = temp;
        }
    }
}

int main() {
    std::vector<int> vec = {10, 7, 8, 9, 1, 5, 119, 6, 4, 11, 12, 12, 5, 7};
    int n = vec.size();
    shellSort(vec);

    for (auto i : vec) {
        std::cout << i << " ";
    }
}

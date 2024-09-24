#include <vector>
#include <iostream>

int partition(std::vector<int> &unsorted, int low, int high) {

    int pivot = unsorted[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (unsorted[j] <= pivot) {
            i++;
            std::swap(unsorted[i], unsorted[j]);
        }
    }

    std::swap(unsorted[i + 1], unsorted[high]);

    return (i + 1);
}

void quickSort(std::vector<int> &unsorted, int low, int high)
{
    if (low < high) {
        int pi = partition(unsorted, low, high);

        quickSort(unsorted, low, pi - 1);
        quickSort(unsorted, pi + 1, high);
    }
}

int main() {
    std::vector<int> vec = {10, 7, 8, 9, 1, 5, 119, 6, 4, 11, 12, 12, 5, 7};
    int n = vec.size();
    quickSort(vec, 0, n - 1);

    for (auto i : vec) {
        std::cout << i << " ";
    }
}

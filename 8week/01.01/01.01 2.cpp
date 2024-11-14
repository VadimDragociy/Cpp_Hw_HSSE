#include <iostream>

__attribute__((constructor))
void printMessage() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    return 0;
}

#include <iostream>
#include <cstdlib>

void printMessage() {
    std::cout << "Hello, World!" << std::endl;
}

int registerPrinter = (std::atexit(printMessage), 0);

int main() {
    return 0;
}
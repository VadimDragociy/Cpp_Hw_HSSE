#include <iostream>

struct print {
    print() {
        std::cout << "Hello, World!" << std::endl;
    }
};

print p;

int main() {
    return 0;
}
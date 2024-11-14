#include <iostream>
#include <string>

template <typename Implementation>
class Text {
public:
    void print() const {
        std::cout << static_cast<const Implementation*>(this)->test() << std::endl;
    }
};

class PlainText : public Text<PlainText> {
public:
    std::string test() const {
        return "plaintext";
    }
};

class UpperCase : public Text<UpperCase> {
public:
    std::string test() const {
        return "UPPERCASE";
    }
};

int main() {
    PlainText plainFormatter;
    UpperCase upperFormatter;

    Text<PlainText> plaintext;
    std::cout << "Plain text: ";
    plainFormatter.print();

    std::cout << "Upper case text: ";
    upperFormatter.print();

    return 0;
}
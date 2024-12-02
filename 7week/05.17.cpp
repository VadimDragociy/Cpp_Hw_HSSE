#include <iostream>
#include <string>

template <typename Implementation>
class Formatter {
public:
    std::string format() const {
        return static_cast<const Implementation*>(this)->formatImpl();
    }
};

class PlainText : public Formatter<PlainText> {
public:
    std::string formatImpl() const {
        return "plaintext";
    }
};

class UpperCase : public Formatter<UpperCase> {
public:
    std::string formatImpl() const {
        return "UPPERCASE";
    }
};

template <typename Formatter>
class Text {
protected:
    Formatter& formatter;
public:
    explicit Text(const Formatter& fmt) : formatter(fmt) {}

    void print() const {
        std::cout << "Regular: " << formatter.format() << std::endl;
    }
};

template <typename Formatter>
class DetailedText : protected Text<Formatter> {
public:
    using Text<Formatter>::Text;
    void print() const {
        std::cout << "Detailed format: [" << Text<Formatter>::formatter.format() << "]" << std::endl;
    }
};

int main() {
    PlainText plainFormatter;
    UpperCase upperFormatter;

    Text<PlainText> basicPlainText(plainFormatter);
    basicPlainText.print();

    Text<UpperCase> basicUpperText(upperFormatter);
    basicUpperText.print();

    DetailedText<PlainText> detailedPlainText(plainFormatter);
    detailedPlainText.print();

    DetailedText<UpperCase> detailedUpperText(upperFormatter);
    detailedUpperText.print();
}

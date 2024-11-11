#include <iostream>
#include <sstream>
#include <array>
#include <boost/operators.hpp>

class IPv4
    : public boost::less_than_comparable<IPv4>
    , public boost::equality_comparable<IPv4>
    , public boost::incrementable<IPv4>
    , public boost::decrementable<IPv4>
{
    std::array<unsigned char, 4> data;

public:
    constexpr IPv4() : data{ {0} } {}
    constexpr IPv4(unsigned char const a, unsigned char const b,
                    unsigned char const c, unsigned char const d):
        data{{a,b,c,d}} {}

    explicit constexpr IPv4(unsigned long a) :
        data{ { static_cast<unsigned char>((a >> 24)),
                static_cast<unsigned char>((a >> 16)),
                static_cast<unsigned char>((a >> 8)),
                static_cast<unsigned char>(a) } 
              } {}

    IPv4& operator=(IPv4 const & other) noexcept {
        data = other.data;
        return *this;
    }

    bool operator<(IPv4 const & other) const noexcept {
        return this->to_ulong() < other.to_ulong();
    }

    bool operator==(IPv4 const & other) const noexcept {
        return this->to_ulong() == other.to_ulong();
    }

    IPv4& operator++() { 
        *this = IPv4(1 + this->to_ulong());
        return *this;
    }

    IPv4& operator--() { 
        *this = IPv4(this->to_ulong() - 1);
        return *this;
    }

    constexpr unsigned long to_ulong() const noexcept {
        return (static_cast<unsigned long>(data[0]) << 24) +
               (static_cast<unsigned long>(data[1]) << 16) +
               (static_cast<unsigned long>(data[2]) << 8) +
               static_cast<unsigned long>(data[3]);
    }

    friend std::ostream& operator<<(std::ostream& os, IPv4 const& a) {
        os << static_cast<int>(a.data[0]) << '.'
           << static_cast<int>(a.data[1]) << '.'
           << static_cast<int>(a.data[2]) << '.'
           << static_cast<int>(a.data[3]);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, IPv4& a) {
        char d1, d2, d3;
        int b1, b2, b3, b4;

        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;

        if (d1 == '.' && d2 == '.' && d3 == '.')
            a = IPv4(b1, b2, b3, b4);
        else
            is.setstate(std::ios_base::failbit);
        return is;
    }
};

int main() {
    IPv4 address(168, 192, 0, 1);
    IPv4 diff_address(101635511);
    std::cout << address << std::endl;
    std::cout << diff_address << std::endl;

    std::cout << (address == diff_address) << std::endl;
    std::cout << (address <= diff_address) << std::endl;
    std::cout << (address >= diff_address) << std::endl;
    std::cout << (address < diff_address) << std::endl;
    std::cout << (address != diff_address) << std::endl;
    std::cout << (address > diff_address) << std::endl;

    IPv4 ip;
    std::cout << ip << std::endl;
    std::cin >> ip;
    std::cout << ip << std::endl;

    for (IPv4 i; i < IPv4(0, 0, 0, 10); i++) {
        std::cout << i << std::endl;
        ip = i;
    }

    std::cout << ip-- << std::endl;
    auto ip1 = IPv4{};
    std::cout << ip1 --;
}

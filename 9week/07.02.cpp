#include <variant>
#include <iostream>
#include <optional>
#include <string>

// Класс для представления точки
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

class Line {
public:
    double a, b, c;

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    bool isIdentical(const Line& other) const {
        double det = a * other.b - b * other.a;
        double det1 = c * other.b - b * other.c;
        double det2 = a * other.c - c * other.a;
        return det == 0 && det1 == 0 && det2 == 0;
    }

    bool isParallel(const Line& other) const {
        double det = a * other.b - b * other.a;
        return det == 0 && !isIdentical(other);
    }
};

using IntersectionResult = std::variant<std::monostate, int>;

IntersectionResult findIntersection(const Line& l1, const Line& l2) {
    double det = l1.a * l2.b - l1.b * l2.a;

    if (det == 0.0) {
        if (l1.isIdentical(l2)) {
            return std::monostate();
        } else {
            return 0;
        }
    }

    return 1;
}

void answer(IntersectionResult& result) {
    if (std::holds_alternative<std::monostate>(result)) {
        std::cout << "infinity" << std::endl;
        return;
    } else if (std::holds_alternative<int>(result)) {
        auto i = std::get<int>(result);
        std::cout << i << std::endl;
        return;
    }
    throw std::invalid_argument("Invalid argument result");
}

int main() {
    Line l1(1, -1, -1);
    Line l2(2, -2, -2);
    Line l3(0, 1, -2);
    Line l4(1, 1, -4);

    auto result1 = findIntersection(l1, l2);
    answer(result1);

    auto result2 = findIntersection(l3, l4);
    answer(result2);
}


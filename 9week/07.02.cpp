#include <variant>
#include <iostream>
#include <optional>
#include <string>

double determinant(double this_a, double this_b, double other_a, double other_b) {
  	return this_a * other_b - this_b * other_a;
}

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

    Line() : a(0), b(0), c(0) {}

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    bool isIdentical(const Line& other) const {
        double det = determinant(a, b, other.a, other.b);
        double det1 = determinant(c, b, other.c, other.b);
        double det2 = determinant(a, c, other.a, other.c);
        return det == 0 && det1 == 0 && det2 == 0;
    }

    bool isParallel(const Line& other) const {
        double det = a * other.b - b * other.a;
        return det == 0 && !isIdentical(other);
    }
};

using IntersectionResult = std::variant<Line, int, Point>;

IntersectionResult findIntersection(const Line& l1, const Line& l2) {
    double det = determinant(l1.a, l1.b, l2.a, l2.b);
    if (det == 0.0) {
        if (l1.isIdentical(l2)) {
            return l1;
        } else {
            return 0;
        }
    }

    double x = (-l1.c * l2.b + l2.c * l1.b) / det;
    double y = (-l1.a * l2.c + l2.a * l1.c) / det;
    return Point(x, y);
}

void answer(const IntersectionResult& result) {
    if (std::holds_alternative<Line>(result)) {
        auto line = std::get<Line>(result);
        std::cout << "infinity: "<< line.a << "x + "<< line.b << "y + " << line.c << std::endl;
        return;
    } else if (std::holds_alternative<Point>(result)) {
        auto pnt = std::get<Point>(result);
        std::cout << pnt << std::endl;
        return;
    } else if (std::holds_alternative<int>(result)) {
        auto i = std::get<int>(result);
        std::cout << i << std::endl;
        return;
    }
    throw std::invalid_argument("Invalid argument result");
}

int main() {
  	try {
    Line l1(1, -1, -1);
    Line l2(2, -2, -2);
    Line l3(0, 1, -2);
    Line l4(1, 1, -4);

    auto result1 = findIntersection(l1, l2);
    answer(result1);

    auto result2 = findIntersection(l3, l4);
    answer(result2);
    } catch (const std::invalid_argument& e) {
      std::cout << e.what() << std::endl;
    } catch (...) {
      std::cout << "unknown error" << std::endl;
    }
}


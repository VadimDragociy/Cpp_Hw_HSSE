#include <future>
#include <iostream>
#include <valarray>
#include <variant>

void validateQuadraticEquation(const double& a, const double& b, const double& c) {
    if (a == 0.0) {
        throw std::invalid_argument("Invalid argument a == 0.0");
    }
}

using QuadraticSolution = std::variant<std::monostate, double, std::pair<double, double>>;

QuadraticSolution solveQuadraticEquation(const double& a, const double& b, const double& c) {
    validateQuadraticEquation(a, b, c);
    if (const double discriminant = b * b - 4 * a * c; discriminant > 0.0) {
        double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return std::make_pair(x1, x2);
    } else {
        if (discriminant == 0.0) {
            double x = -b / (2 * a);
            return x;
        }
        return std::monostate{};
    }
}

void answer(QuadraticSolution result) {
    if (std::holds_alternative<std::monostate>(result)) {
        std::cout << "No solution" << std::endl;
    } else if (std::holds_alternative<std::pair<double, double>>(result)) {
        auto [fst, snd] = std::get<std::pair<double, double>>(result);
        std::cout << fst << " " << snd<< std::endl;
    } else if (std::holds_alternative<double>(result)) {
        std::cout << std::get<double>(result) << std::endl;
    }
    throw std::invalid_argument("Invalid argument result");
}

int main() {
    auto a = 0.0, b = 0.0, c = 0.0;
    std::cin >> a >> b >> c;
    const auto result = solveQuadraticEquation(a, b, c);
    answer(result);
}
#include <iostream>

struct AddStrategy {
    int execute(int a, int b) const {
        return a + b;
    }
};

struct SubStrategy {
    int execute(int a, int b) const {
        return a - b;
    }
};

template <typename Strategy>
class Context {
public:
    Context(Strategy strategy) : strategy(strategy) {}

    int executeStrategy(int a, int b) const {
        return strategy.execute(a, b);
    }

private:
    Strategy strategy;
};

int main() {
    Context<AddStrategy> contextAdd(AddStrategy{});
    std::cout << contextAdd.executeStrategy(5, 3) << std::endl;

    Context<SubStrategy> contextSub(SubStrategy{});
    std::cout << contextSub.executeStrategy(5, 3) << std::endl;

    return 0;
}
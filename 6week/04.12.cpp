#include <iostream>
#include <type_traits>

template <typename T>
struct add_const {
    using type = const T;
};

template <typename T>
struct add_const<const T> {
    using type = const T;
};

template <typename T>
struct remove_const {
    using type = T;
};

template <typename T>
struct remove_const<const T> {
    using type = T;
};

int main() {
    static_assert(std::is_same<add_const<int>::type, const int>::value, "add_const<int> не работает!");
    static_assert(std::is_same<add_const<const int>::type, const int>::value, "add_const<const int> не работает!");
    
    static_assert(std::is_same<remove_const<const int>::type, int>::value, "remove_const<const int> не работает!");
    static_assert(std::is_same<remove_const<int>::type, int>::value, "remove_const<int> не работает!");

    std::cout << "Все проверки пройдены успешно!" << std::endl;
    return 0;
}

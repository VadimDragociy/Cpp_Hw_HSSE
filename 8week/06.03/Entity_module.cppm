export module Entity1;
#include <string>
using namespace std::literals;

export class Entity {
public:
    Entity();

    Entity(const int& data_1, int data_2, int data_3);

    Entity(const int& data_1, int data_2);

    ~Entity();

    auto data_1() const;
    auto data_2() const;
    auto data_3() const;

    const auto& data_as_string() const;

    void set_data_3(int data);

    static void test();

private:
    struct Cached_Data {
        void update(const Entity& entity);

        std::string string;
        bool is_invalid = true;
    };

    static inline auto s_data_1 = 0;

    static const auto s_data_2 = 0;

    static inline const auto s_data_4 = "aaaaa"s;

    const int& m_data_1 = 0;

    const int m_data_2 = 0;

    int m_data_3 = 0;

    mutable Cached_Data m_cached_data;
};
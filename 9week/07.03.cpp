#include <string>
#include <iostream>
#include <optional>

struct Person{
    Person() : name(""), age(std::nullopt), height(std::nullopt) {}
    std::string& getName() {
        return name;
    };
    int getAge() {
        return age.value();
    };
    int getHeight() {
        return height.value();
    };

    std::string name;
    std::optional<int> age;
    std::optional<int> height;

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " ";
        if (person.age.has_value()) {
            os << person.age.value() << " ";
        }
        if (person.height.has_value()) {
            os << person.height.value() << " ";
        }
        return os;

    }

};

struct Builder {
    Builder() : person() {}

    Builder& Name(const std::string &name) {
        person.name = name;
        return *this;
    }
    Builder& Height(int height) {
        person.height = height;
        return *this;
    }
    Builder& Age(int age) {
        person.age = age;
        return *this;
    }
    Person& get(){
        return person;
    }

private:
    Person person;
};

int main(){
    Builder builder;
    Builder builder2;
    Person p = builder.Name("Ivan").Age(26).Height(180).get();
    std::cout << p << std::endl;
    Person p1 = builder2.Name("unIvan").get();
    std::cout << p1;
}
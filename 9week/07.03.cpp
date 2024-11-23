#include <string>
#include <iostream>
#include <optional>

struct Person{
    Person() : name(""), age(0), height(0) {}
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

};

struct Builder {
    Builder() : person() {}

    Builder& Name(const std::string &name) {
        person.name = name;
        return *this;
    }
    Builder& Height(std::optional<int> height) {
        person.height = height;
        return *this;
    }
    Builder& Age(std::optional<int> age) {
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
    std::cout << p.getAge() << p.getHeight() << p.getName() << std::endl;
    Person p1 = builder2.Name("unIvan").get();
    std::cout << p1.getAge() << p1.getHeight() << p1.getName();
}
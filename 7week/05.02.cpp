#include <string>
#include <iostream>

struct Person{
    std::string name;
    int age;
    int height;
    Person() : name(""), age(0), height(0) {}

};

struct Builder{
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
    Person p = builder.Name("Ivan").Age(26).Height(180).get();
    std::cout << p.age << p.height << p.name;
}
#include <cassert>
#include <iostream>
#include <string>

import Entity1;

using namespace std::literals;
using namespace Entity_nmspc;

int main() {
    Entity1::Entity entity_1;

    entity_1.set_data_3(1);

    assert(entity_1.data_3() == 1);

    assert(entity_1.data_as_string() == "0/0/1");

    const Entity1::Entity entity_2;

    assert(entity_2.data_3() == 0);

    assert(entity_2.data_as_string() == "0/0/0");

    Entity1::Entity entity_3;

    Entity1::Entity entity_4(1, 2, 3);

    Entity1::Entity entity_5(1, 2);

    entity_1.test();
    Entity1::Entity::test();
}
cmake_minimum_required(VERSION 3.29.6)
project(06_03)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")
#add_module(Entity_module Entity.cppm)
#add_module(Entity_module Entity_module.cppm)
add_executable(06_03
    main.cpp
        Entity.cppm
        Entity_module.cppm
)

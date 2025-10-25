cmake_minimum_required(VERSION 4.0)
project(Odev_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Odev_1
        Bolum1/bolum1.cpp
)
add_executable(new_target Bolum2/bolum2.cpp
        Bolum1/bolum1.cpp
)
add_executable(new_target1 Bolum1/bolum1.cpp)

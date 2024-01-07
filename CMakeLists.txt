cmake_minimum_required(VERSION 3.26)
project(main.cpp)

set(CMAKE_CXX_STANDARD 17)
link_libraries(libeasyx.a)
add_executable(11111 main.cpp
        Button.h
        Widget.h
        Game.h
        map.h
        HEAD.h)

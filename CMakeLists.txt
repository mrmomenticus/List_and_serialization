cmake_minimum_required(VERSION 3.5)

project(test_saber LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_saber main.cpp listnote.h listnote.cpp listrand.h listrand.cpp )

install(TARGETS test_saber
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

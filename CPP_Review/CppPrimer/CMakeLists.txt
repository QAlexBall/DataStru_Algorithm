cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)


#add_executable(CppPrimer main.cpp OOP/quote.h main.cpp C++11/cpp11.cpp C++11/use_vector.h BTree.cpp IO/iotest.cpp)
#add_executable(CppPrimer C++11/cpp11.cpp)
add_executable(CppPrimer solution.cpp)
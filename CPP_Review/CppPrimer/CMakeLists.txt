cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)


#add_executable(CppPrimer main.cpp OOP/quote.h main.cpp C++11/cpp11.cpp C++11/use_vector.h BTree.cpp IO/iotest.cpp)
#add_executable(CppPrimer C++11/cpp11.cpp)
add_executable(CppPrimer main.cpp C++11/StarBlob.h C++11/StarBlob.cpp
        Template/blob_ptr.h Template/blob.h Template/blob_use.h Template/blob_ptr_use.h TextQurey/text_query.h TextQurey/text_query.cpp TextQurey/query_result.h)
#add_executable(CppPrimer main.cpp)
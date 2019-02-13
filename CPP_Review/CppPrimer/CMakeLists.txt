cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

option(USE_MYTEXT
        "Use provided text implementation" ON)

# 是否加入TEXT库
if (USE_MYTEXT)
    include_directories("${PROJECT_SOURCE_DIR}/TextQurey")
    add_subdirectory(TextQurey)
    set (EXTRA_LIBS ${EXTRA_LIBS} Text)
endif(USE_MYTEXT)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 查找当前目录下的所有源文件
# 并将名称保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 指定生成目录
add_executable(CppPrimer ${DIR_SRCS})
target_link_libraries(CppPrimer ${EXTRA_LIBS})



#add_subdirectory(TextQurey)
#add_executable(CppPrimer main.cpp)
#target_link_libraries(CppPrimer Text)

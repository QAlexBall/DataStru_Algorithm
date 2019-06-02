cmake_minimum_required (VERSION 2.8)

project (demo2)

# 查找目录下的所有源文件并保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

# 添加math子目录
add_subdirectory(math)

add_executable(demo main.cc)

# 添加库链接
target_link_libraries(demo MathFunctions)

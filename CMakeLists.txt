cmake_minimum_required(VERSION 3.28)
project(tomagatchi)


add_compile_definitions(-DSTM32F030x8)

add_subdirectory(deps)
add_subdirectory(src)
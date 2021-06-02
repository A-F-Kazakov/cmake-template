cmake_minimum_required(VERSION 3.13)

project(Tmpl VERSION 0.0.1 DESCRIPTION "Cmake template project")

#include(doxygen)

set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib)
add_subdirectory(app)

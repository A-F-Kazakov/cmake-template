cmake_minimum_required(VERSION 3.16)

project(Tmpl)

option(TMPL_BUILD_TESTS "Build ${PROJECT_NAME} tests" OFF)
option(TMPL_BUILD_EXAMPLES "Build ${PROJECT_NAME} examples" OFF)
option(TMPL_EXCLUDE_DEPRECATED "Exclude deprecated parts of ${PROJECT_NAME}" OFF)

include(clang-tidy OPTIONAL)
include(sanitizers OPTIONAL)
include(warnings OPTIONAL)
include(interprocedural_optimizations OPTIONAL)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message(STATUS "Build type is: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

add_subdirectory(lib)
add_subdirectory(app)


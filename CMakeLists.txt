cmake_minimum_required(VERSION 3.13)

include(ProcessorCount)

project(Tmpl VERSION 0.0.1 DESCRIPTION "Cmake template project")

set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "Build type is: ${CMAKE_BUILD_TYPE}")

add_subdirectory(lib)
add_subdirectory(app)

#

set(CPACK_PACKAGE_VENDOR "VENDOR")
set(CPACK_PACKAGE_CONTACT "https://tmpl.org")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "support@tmpl.org")
set(CPACK_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})

set(CPACK_GENERATOR "ZIP")

include(CPack)

add_custom_target(${PROJECT_NAME}-pack
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND cpack -C $<CONFIGURATION> -j${N}
	DEPENDS lib app
)

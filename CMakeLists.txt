cmake_minimum_required(VERSION 3.16)

project(Tmpl VERSION 0.1.0 DESCRIPTION "Cmake template project")

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

option(${PROJECT_NAME_UPPER}_BUILD_TESTS "Enable compilation of shared libraries" OFF)

message(STATUS "Build type is: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)
include(CheckIPOSupported)
include(CheckPIESupported)

if(${PROJECT_NAME_UPPER}_BUILD_TESTS)
	enable_testing()
endif()

add_subdirectory(lib)
add_subdirectory(app)

check_ipo_supported(RESULT result OUTPUT output)
if(result)
	set_property(TARGET app PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
	message(WARNING "IPO is not supported: ${output}")
endif()

check_pie_supported(OUTPUT_VARIABLE output LANGUAGES C CXX)
set_property(TARGET app PROPERTY POSITION_INDEPENDENT_CODE TRUE)
if(NOT CMAKE_C_LINK_PIE_SUPPORTED OR NOT CMAKE_CXX_LINK_PIE_SUPPORTED)
  message(WARNING "PIE is not supported at link time: ${output}.\n"
                  "PIE link options will not be passed to linker.")
endif()

#

set(CPACK_PACKAGE_VENDOR "VENDOR")
set(CPACK_PACKAGE_CONTACT "https://tmpl.org")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "support@tmpl.org")
set(CPACK_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})

set(CPACK_GENERATOR "ZIP")

include(CPack)

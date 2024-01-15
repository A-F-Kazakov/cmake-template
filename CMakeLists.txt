cmake_minimum_required(VERSION 3.16)

project(Tmpl)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
endif()

option(TMPL_BUILD_TESTS "Build ${PROJECT_NAME} tests" OFF)
option(TMPL_BUILD_EXAMPLES "Build ${PROJECT_NAME} examples" OFF)
option(TMPL_EXCLUDE_DEPRECATED "Exclude deprecated parts of ${PROJECT_NAME}" OFF)
option(TMPL_BUILD_DOCUMENTATION "Create and install the API documentation" OFF)

include(clang-tidy OPTIONAL)
include(sanitizers OPTIONAL)
include(warnings OPTIONAL)
include(interprocedural_optimizations OPTIONAL)

message(STATUS "Build type is: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

add_subdirectory(lib)
add_subdirectory(app)

if(TMPL_BUILD_DOCUMENTATION)
	find_package(Doxygen OPTIONAL_COMPONENTS dot mscgen dia)

	if(NOT DOXYGEN_FOUND)
		message(FATAL_ERROR "Doxygen is required to build the documentation")
	endif()

	set(DOXYGEN_GENERATE_HTML NO)
	set(DOXYGEN_GENERATE_LATEX YES)
	#set(DOXYGEN_LATEX_HEADER headerFile)
	#set(DOXYGEN_LATEX_FOOTER footerFile)
	set(DOXYGEN_HAVE_DOT YES)
	set(DOXYGEN_PROJECT_NAME Tmpl)
	set(DOXYGEN_PROJECT_NUMBER 1.11.111)
	set(DOXYGEN_PROJECT_BRIEF "Base project to demostrate required features")
	#set(DOXYGEN_OUTPUT_LANGUAGE Russian)
	set(DOXYGEN_EXAMPLE_PATH ${PROJECT_SOURCE_DIR}/lib/examples)
	set(DOXYGEN_GENERATE_TODOLIST NO)
	set(DOXYGEN_GENERATE_BUGLIST NO)
	set(DOXYGEN_SHOW_USED_FILES NO)
	set(DOXYGEN_SHOW_FILES NO)
	set(DOXYGEN_PREDEFINED "TMPL_EXPORT;TMPL_DEPRECATED")
	set(DOXYGEN_MACRO_EXPANSION YES)
	#set(DOXYGEN_EXPAND_ONLY_PREDEF NO)

	set(DOXYGEN_CLASS_GRAPH YES)
	set(DOXYGEN_CALLER_GRAPH YES)
	set(DOXYGEN_CALL_GRAPH YES)
	set(DOXYGEN_GENERATE_TREEVIEW YES)
	set(DOXYGEN_DOT_IMAGE_FORMAT svg)
	set(DOXYGEN_DOT_TRANSPARENT YES)
	set(DOXYGEN_UML_LOOK YES)
	#set(DOXYGEN_PLANTUML_JAR_PATH )
	#\startuml [{file}] ["caption"] [<sizeindication>=<size>]
	# ...
	#\enduml
 

	doxygen_add_docs(documentation-latex ${PROJECT_SOURCE_DIR}/lib/include)
	add_custom_command(TARGET documentation-latex POST_BUILD COMMAND make WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/latex)
	install(FILES ${PROJECT_BINARY_DIR}/latex/refman.pdf DESTINATION doc RENAME api.pdf)
endif()


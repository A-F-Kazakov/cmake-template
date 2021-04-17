cmake_minimum_required(VERSION 3.13)

project(app VERSION 0.0.1)

add_executable(${PROJECT_NAME} MACOSX_BUNDLE src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME}::lib)
set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_RPATH @executable_path)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin COMPONENT ${PROJECT_NAME}
	LIBRARY DESTINATION lib COMPONENT ${PROJECT_NAME}
	ARCHIVE DESTINATION lib/static COMPONENT ${PROJECT_NAME}
)
install(FILES src/main.cpp DESTINATION src COMPONENT sources)

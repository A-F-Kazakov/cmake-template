message(STATUS "Build ${PROJECT_NAME} tests enabled")

set(TEST_HEAD ${PROJECT_NAME}_test)

set(TEST_NAME ${TEST_HEAD}_first)
add_executable(${TEST_NAME} first.cpp)
target_link_libraries(${TEST_NAME} PUBLIC ${PROJECT_NAME})

add_test(${TEST_NAME} ${TEST_NAME})

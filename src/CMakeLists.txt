add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

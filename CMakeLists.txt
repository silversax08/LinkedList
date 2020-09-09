cmake_minimum_required(VERSION 3.10)

project(UnitTest)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    unitTest.cpp
    )

target_link_libraries(${PROJECT_NAME}  ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})


cmake_minimum_required(VERSION 3.10)

project(Linked_List)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(${PROJECT_NAME} STATIC
        LinkedList.hpp
        LinkedListFunctions.hpp
        LinkedList.cpp
        LinkedListFunctions.cpp
  )

set(TEST_NAME ${PROJECT_NAME}_UnitTest)

add_executable(${TEST_NAME}
    convert_linked_list_to_string_test.cpp
    add_item_to_beginning_of_list_test.cpp
    add_item_to_end_of_list_test.cpp
    remove_first_item_in_list_test.cpp
    remove_last_item_in_list_test.cpp
    remove_all_instances_of_item_from_list_test.cpp
    clear_linked_list_test.cpp
    LinkedListAcceptanceTest.cpp
    LinkedListClassAcceptanceTest.cpp
    )

target_link_libraries(${TEST_NAME}  ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${PROJECT_NAME})


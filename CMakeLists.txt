cmake_minimum_required(VERSION 3.10)
project(piaa_lab6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(aho_corasick src/aho_corasick.cpp src/ACAlgorithm.cpp src/ACAlgorithm.h src/Node.h src/Bohr.cpp src/Bohr.h)
add_executable(joker src/joker.cpp src/ACAlgorithm.cpp src/ACAlgorithm.h src/Node.h src/Bohr.cpp src/Bohr.h)

add_executable(aho_corasick_test test/aho_corasick_test.cpp src/ACAlgorithm.cpp src/ACAlgorithm.h test/ACTest.h test/ACTest.cpp src/Node.h src/Bohr.cpp src/Bohr.h)
add_executable(joker_test test/joker_test.cpp src/ACAlgorithm.cpp src/ACAlgorithm.h test/ACTest.h test/ACTest.cpp src/Node.h src/Bohr.cpp src/Bohr.h)

target_link_libraries(aho_corasick_test gtest gtest_main)
target_link_libraries(joker_test gtest gtest_main)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)
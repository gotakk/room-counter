cmake_minimum_required(VERSION 3.0)
project(roomCounter VERSION 1.0 LANGUAGES CXX)


# BINARY
add_executable(roomCounter
  src/main.cpp
)

if ( CMAKE_COMPILER_IS_GNUCC )
  target_compile_options(roomCounter PRIVATE "-Wall")
  target_compile_options(roomCounter PRIVATE "-pedantic")
  target_compile_options(roomCounter PRIVATE "-ansi")
  target_compile_options(roomCounter PRIVATE "-Werror")
  target_compile_options(roomCounter PRIVATE "-std=c++11")
endif ( CMAKE_COMPILER_IS_GNUCC )


# TEST
enable_testing()
find_package(GTest REQUIRED)
add_executable(roomCounter.test
  test/test.cpp
  test/PlnLoaderTest.cpp
  test/PlanTest.cpp
  test/ArchitectTest.cpp
)
target_link_libraries(roomCounter.test ${GTEST_BOTH_LIBRARIES})
include_directories("src/")
add_test(unitTests roomCounter.test)

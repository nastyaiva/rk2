cmake_minimum_required(VERSION 3.10)

project(Command)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COMMAND_APP "Build Command1" OFF)
option(BUILD_TESTS "Build tests" OFF)

add_library(Command STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Command.cpp)

if(BUILD_COMMAND_APP)
    add_executable(Command1 main.cpp)
    target_link_libraries(Command1 Command)
endif()

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  add_executable(check ./tests/test.cpp)
  target_link_libraries(check Command gtest_main)
  add_test(NAME check COMMAND check)
endif()

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)
target_link_libraries(demo Command)
install(TARGETS demo RUNTIME DESTINATION bin)


include(CPackConfig.cmake)

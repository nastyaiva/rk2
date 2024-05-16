cmake_minimum_required(VERSION 3.10)

project(Command)

# Добавить исполняемый файл для abstract_factory.cpp
add_executable(Command Command.cpp)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB ${Command}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${Command}_TEST_SOURCES})
  target_link_libraries(check ${Command} gtest_main)
  add_test(NAME check COMMAND check)
endif()

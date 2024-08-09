CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# set the project name
PROJECT(ping)

# change where to put executables
set(EXECUTABLE_OUTPUT_PATH ../build)

# add the executable
SET(SOURCES ping.c ping.h)
# ADD_EXECUTABLE(ls ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

# TESTS

enable_testing()

add_library(src ${SOURCES})
add_executable(
  test_ping.cpp
  test/test_ping.cpp
  ${SOURCES}
)
target_link_libraries(
  test_ping.cpp
  GTest::gtest
  GTest::gtest_main
  src
)

include(GoogleTest)
gtest_discover_tests(test_ping.cpp)

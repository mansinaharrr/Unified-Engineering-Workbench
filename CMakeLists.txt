cmake_minimum_required(VERSION 3.20)
project(UnifiedEngineeringWorkbench VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(UEW_BUILD_TESTS "Build tests" ON)
add_library(uew_core
  src/thermal/thermal.cpp
  src/geometry/geometry.cpp
  src/performance/benchmark.cpp
  src/hardware/hardware.cpp
  src/backpropagation/backprop.cpp)
target_include_directories(uew_core PUBLIC include)
if(MSVC)
  target_compile_options(uew_core PRIVATE /W4 /O2)
else()
  target_compile_options(uew_core PRIVATE -Wall -Wextra -Wpedantic -O2)
endif()
find_package(Threads REQUIRED)
target_link_libraries(uew_core PUBLIC Threads::Threads)
add_executable(uew src/main.cpp)
target_link_libraries(uew PRIVATE uew_core)
if(UEW_BUILD_TESTS)
  enable_testing()
  add_executable(uew_tests tests/test_main.cpp)
  target_link_libraries(uew_tests PRIVATE uew_core)
  add_test(NAME uew_tests COMMAND uew_tests)
endif()
install(TARGETS uew RUNTIME DESTINATION .)

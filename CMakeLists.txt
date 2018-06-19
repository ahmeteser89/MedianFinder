# CMakeList.txt : CMake project for Median, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

if (MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING")
endif()

# Add source to this project's executable.
add_library(medianLib "Median.cpp" "ConsoleReader.cpp" "MedianManager.cpp" "ConsoleWriter.cpp")
add_executable (Median "main.cpp")

target_link_libraries(Median medianLib)

# TODO: Add tests and install targets if needed.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(tests/gtest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests "tests/DynamicContainerTest.cpp" "tests/PriorityQueueTest.cpp" "tests/MedianTest.cpp")

target_link_libraries(runUnitTests gtest gtest_main)

target_link_libraries(runUnitTests medianLib)
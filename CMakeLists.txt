cmake_minimum_required(VERSION 3.10)
project(XiaoyuanEatsApples)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Allow in-source builds
set(CMAKE_DISABLE_IN_SOURCE_BUILD OFF)
set(CMAKE_DISABLE_SOURCE_CHANGES OFF)

# Set output directory to current binary dir (project root for in-source build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Add executable
add_executable(code main.cpp)
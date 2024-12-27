# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(WavefunctionProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the source files
set(SOURCES
    app/main.cpp
    base/propagation.cpp
)

# Include the header directory
include_directories(base)

# Set the output directory for the executable (to be inside the 'app' folder)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/app)

# Add the executable target
add_executable(exe ${SOURCES})

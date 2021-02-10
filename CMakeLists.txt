#***********************************************************
# This is a simple cmake file for creating a
# single-file application, that depends on
# system libraries
#
# Reference: https://stackoverflow.com/questions/39598323/how-to-properly-link-libraries-with-cmake
#***********************************************************
cmake_minimum_required(VERSION 3.10)
project(blockchain)

# Set C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Define the main module, which also holds the executable
add_executable(blockchain
               Block.cpp
               Blockchain.cpp
               sha256.cpp
               main.cpp)

# Link system libaries
#target_link_libraries(ray_tracer -lX11)
#target_link_libraries(ray_tracer -lGL)
#target_link_libraries(ray_tracer -lpthread)
#target_link_libraries(ray_tracer -lpng)
#target_link_libraries(ray_tracer -lstdc++fs)


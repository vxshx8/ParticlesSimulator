# Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/sdl2/include)

link_directories(${CMAKE_SOURCE_DIR}/sdl2/lib)


file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/ParticleSimulator/src/*.cpp
)


add_executable(ParticleSimulator ${SOURCES})

target_link_libraries(ParticleSimulator SDL2)

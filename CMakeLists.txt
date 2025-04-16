cmake_minimum_required(VERSION 3.28)
project(StructuresAndAlgorithms LANGUAGES CXX)

add_executable(StructuresAndAlgorithms
    src/main.cpp
)

target_include_directories(StructuresAndAlgorithms PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)
target_compile_features(StructuresAndAlgorithms PRIVATE cxx_std_17)


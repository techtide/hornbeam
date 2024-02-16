cmake_minimum_required(VERSION 3.10)
project(hornbeam)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(mlpack REQUIRED)
find_package(OpenMP REQUIRED)

add_executable(hornbeam 
    src/Note.h
    src/VaultReader.cc
    src/VaultReader.h
    src/main.cc
    src/core.h
    src/Note.cc
    src/NoteEmbeddingModel.h
    src/NoteEmbeddingModel.cc
)

target_link_libraries(hornbeam PRIVATE mlpack)
target_link_libraries(hornbeam PRIVATE OpenMP::OpenMP_CXX)

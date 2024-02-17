cmake_minimum_required(VERSION 3.10)
project(hornbeam)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(mlpack REQUIRED)
find_package(OpenMP REQUIRED)
find_package(LAPACK REQUIRED)
find_package(BLAS REQUIRED)
find_package(Armadillo REQUIRED)
find_package(Boost REQUIRED)

add_executable(hornbeam 
    src/main.cc
    src/VaultReader.cc
    src/MongeElkanEmbedding.cc
    src/Note.cc
)

target_link_libraries(hornbeam PRIVATE ${BOOST})
target_link_libraries(hornbeam PRIVATE ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES})
target_link_libraries(hornbeam PRIVATE ${ARMADILLO_LIBRARIES})
target_link_libraries(hornbeam PRIVATE mlpack)
target_link_libraries(hornbeam PRIVATE OpenMP::OpenMP_CXX)

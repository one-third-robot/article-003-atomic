cmake_minimum_required(VERSION 3.5)
project(atomic-example)

set(CMAKE_CXX_STANDARD 11)

# ------------------------------
add_executable(
    no-atomic
    no-atomic.cpp
)
target_link_libraries(
    no-atomic
    pthread
)

# ------------------------------
add_executable(
    atomic-simple
    atomic-simple.cpp
)
target_link_libraries(
    atomic-simple
    pthread
    atomic
)

# ------------------------------
add_executable(
    atomic-class
    atomic-class.cpp
)
target_link_libraries(
    atomic-class
    pthread
    atomic
)
# ------------------------------
add_executable(
    atomic-mutex
    atomic-mutex.cpp
)

target_link_libraries(
    atomic-mutex
    pthread
    atomic
)

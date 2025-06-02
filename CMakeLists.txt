cmake_minimum_required(VERSION 3.30)
project(pong C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} main.c init.c loop.c player.c)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

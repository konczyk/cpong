cmake_minimum_required(VERSION 3.30)
project(cpong C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(vendor/SDL3_ttf EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} main.c init.c loop.c player.c ball.c score.c)

target_link_libraries(${PROJECT_NAME} PRIVATE m SDL3::SDL3 SDL3_ttf::SDL3_ttf)

cmake_minimum_required(VERSION 3.30)
project(cpong C)

set(CMAKE_C_STANDARD 23)

option(VENDOR "Use vendor libraries" OFF)

if(VENDOR)
    add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
    add_subdirectory(vendor/SDL3_ttf EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
    find_package(SDL3_ttf REQUIRED CONFIG REQUIRED COMPONENTS SDL3_ttf-shared)
endif()

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCES
        main.c
        init.c
        loop.c
        player.c
        ball.c
        score.c
)

list(TRANSFORM SOURCES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE m SDL3::SDL3 SDL3_ttf::SDL3_ttf)

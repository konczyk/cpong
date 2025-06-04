cmake_minimum_required(VERSION 3.30)
project(cpong C)

set(CMAKE_C_STANDARD 23)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(vendor/SDL3-3.2.16 EXCLUDE_FROM_ALL)
add_subdirectory(vendor/SDL3_ttf-3.2.2 EXCLUDE_FROM_ALL)

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

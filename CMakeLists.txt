cmake_minimum_required(VERSION 3.12)
project(Blitz-Demo)

add_subdirectory(Blitz)

add_executable(${PROJECT_NAME}
    ${Blitz}
    source/main.cpp
)

target_link_libraries(${PROJECT_NAME} Blitz)
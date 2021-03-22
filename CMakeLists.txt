cmake_minimum_required(VERSION 3.12)
project(Blitz-Demo)

find_package(OpenGL REQUIRED)

add_subdirectory(thirdparty/glad-cmake)
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/soil2-cmake)
add_subdirectory(thirdparty/imgui-cmake)

set(Blitz
    Blitz/Blitz-Core.hpp
    Blitz/Blitz-Core.cpp
    Blitz/Blitz-Window.hpp
    Blitz/Blitz-Window.cpp
    Blitz/Blitz-System.hpp
    Blitz/Blitz-System.cpp
    Blitz/Systems/Blitz-File.hpp
    Blitz/Systems/Blitz-File.cpp
    Blitz/Systems/Blitz-Time.hpp
    Blitz/Systems/Blitz-Time.cpp
    Blitz/Systems/Blitz-Clock.hpp
    Blitz/Systems/Blitz-Clock.cpp
    Blitz/Graphics/Blitz-Camera.hpp
    Blitz/Graphics/Blitz-Camera.cpp
    Blitz/Graphics/Blitz-Shader.hpp
    Blitz/Graphics/Blitz-Shader.cpp
    Blitz/Graphics/Blitz-Texture.hpp
    Blitz/Graphics/Blitz-Texture.cpp
    Blitz/Graphics/Blitz-VertexArray.hpp
    Blitz/Graphics/Blitz-VertexArray.cpp
    Blitz/Graphics/Blitz-VertexBuffer.hpp
    Blitz/Graphics/Blitz-VertexBuffer.cpp
    Blitz/Graphics/Blitz-IndexBuffer.hpp
    Blitz/Graphics/Blitz-IndexBuffer.cpp
)

add_executable(${PROJECT_NAME}
    ${Blitz}
    source/main.cpp
)

target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)

target_link_libraries(${PROJECT_NAME} opengl32 glad glfw glm soil2 imgui)
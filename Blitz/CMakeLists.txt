cmake_minimum_required(VERSION 3.12)
project(Blitz)

include_directories(../${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)

add_subdirectory(thirdparty/glad-cmake)
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/soil2-cmake)
add_subdirectory(thirdparty/imgui-cmake)

add_library(Blitz STATIC
    Blitz-Core.hpp
    Blitz-Core.cpp
    Blitz-Window.hpp
    Blitz-Window.cpp
    Blitz-System.hpp
    Blitz-System.cpp
    Systems/Blitz-File.hpp
    Systems/Blitz-File.cpp
    Systems/Blitz-Time.hpp
    Systems/Blitz-Time.cpp
    Systems/Blitz-Clock.hpp
    Systems/Blitz-Clock.cpp
    Graphics/Blitz-Camera.hpp
    Graphics/Blitz-Camera.cpp
    Graphics/Blitz-Shader.hpp
    Graphics/Blitz-Shader.cpp
    Graphics/Blitz-Texture.hpp
    Graphics/Blitz-Texture.cpp
    Graphics/Blitz-VertexArray.hpp
    Graphics/Blitz-VertexArray.cpp
    Graphics/Blitz-VertexBuffer.hpp
    Graphics/Blitz-VertexBuffer.cpp
    Graphics/Blitz-IndexBuffer.hpp
    Graphics/Blitz-IndexBuffer.cpp
)

target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
target_link_libraries(${PROJECT_NAME} opengl32 glad glfw glm soil2 imgui)
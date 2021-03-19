#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <../glm/glm/glm.hpp>
#include <../glm/glm/ext/matrix_clip_space.hpp>
#include <../glm/glm/gtc/type_ptr.hpp>
#include <SOIL2.h>
#include <../imgui-cmake/misc/single_file/imgui_single_file.h>
#include <../imgui-cmake/backends/imgui_impl_glfw.h>
#include <../imgui-cmake/backends/imgui_impl_opengl3.h>

namespace Blitz {
    using uint = uint32_t;
    using uchar = unsigned char;
    typedef void(*func)();
};

namespace Blitz {
    extern uint Init();
    extern uint Exit();
    extern void Pause();
    extern void Debugbreak();

    extern void GLClearError();
    extern bool GLLogCall(const char* function, const char* file, int line);
};

#define BLITZ_NULL 0
#define BLITZ_NULLPTR nullptr

#define BLITZ_TRUE true
#define BLITZ_FALSE false

#define ASSERT_BLITZ(val) if(!(val)) Blitz::Debugbreak();
#define BlitzGLCall(val) Blitz::GLClearError(); val; ASSERT_BLITZ(Blitz::GLLogCall(#val, __FILE__, __LINE__))

#if defined(_WIN64)
    #define BLITZ_WINDOWS
#elif defined(__linux__)
    #define BLITZ_LINUX
#elif defined(__APPLE__)
    #define BLITZ_APPLE
#else
    #error Not Supported Platform!
#endif

#if defined(NDEBUG) || defined(_DEBUG)
    #define BLITZ_DEBUG
#endif

#include "Blitz-Window.hpp"
#include "Graphics/Blitz-Shader.hpp"
#include "Graphics/Blitz-Texture.hpp"
#include "Graphics/Blitz-Camera.hpp"
#include "Graphics/Blitz-VertexArray.hpp"
#include "Graphics/Blitz-VertexBuffer.hpp"
#include "Graphics/Blitz-IndexBuffer.hpp"
#include "Blitz-Window.hpp"

namespace Blitz {
    Window::Window(glm::vec2 size, const char* title) {
        Create(size, title);
    }

    Window::~Window() {
        delete this;
    }

    void Window::Create(glm::vec2 size, const char* title) {
        if(!glfwInit()) {
            std::cerr << "GLFW Init Error!\n";
            Blitz::Exit();
        }
    
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #if defined(BLITZ_APPLE)
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        #endif
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow((int)size.x, (int)size.y, title, BLITZ_NULLPTR, BLITZ_NULLPTR);
        if(m_window == BLITZ_NULL) {
            std::cout << "GLFW Window Init Error!\n";
            glfwTerminate();
        }
        glfwMakeContextCurrent(m_window);
    }
    
    void Window::Display() {
        glfwSwapBuffers(m_window);
    }

    void Window::Close() {
        glfwSetWindowShouldClose(m_window, BLITZ_TRUE);
    }

    void Window::SetIcon(const char* filename) {
        GLFWimage* icon = new GLFWimage[1];
        icon[0].pixels = SOIL_load_image(filename, &icon[0].width, &icon[0].height, BLITZ_NULLPTR, SOIL_LOAD_RGBA);
        glfwSetWindowIcon(m_window, 1, icon);
        SOIL_free_image_data(icon[0].pixels);
    }

    bool Window::IsOpen() {
        return !glfwWindowShouldClose(m_window);
    }

    GLFWwindow* Window::GetWindow() {
        return m_window;
    }

    glm::vec2 Window::GetSize() {
        int width, height;
        glfwGetWindowSize(m_window, &width, &height);
        return glm::vec2(width, height);
    }
};
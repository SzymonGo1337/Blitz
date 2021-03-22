#pragma once

#include "Blitz-Core.hpp"

namespace Blitz {
    class Window {
    public:
        Window(glm::vec2 size = { 1280, 720 }, const char* title = "Blitz Framework");
        ~Window();

        void Create(glm::vec2 size, const char* title);
        void Display();
        void Close();
        
        void SetIcon(const char* filename);
        bool IsOpen();
        GLFWwindow* GetWindow();
        glm::vec2 GetSize();

    private:
        GLFWwindow* m_window;

    };
};
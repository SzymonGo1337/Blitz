#include "Blitz-Core.hpp"

namespace Blitz {
    uint Intit() {
        #if defined(BLITZ_WINDOWS)
            system("Setlocal");
        #endif
        return BLITZ_NULL;
    }
    
    uint Exit() {
        std::exit(-1);
        return BLITZ_NULL;
    }
    
    void Pause() {
        std::cin.get();
    }
    
    void Debugbreak() {
        std::cerr << "Debug Break Invoked!" << "\n";
        Pause();
        Exit();
    }

    void GLClearError() {
        while(glGetError() != GL_NO_ERROR);
    }
    
    bool GLLogCall(const char* function, const char* file, int line) {
        while(GLenum error = glGetError()) {
            std::cerr << "[ Blitz OpenGL Error ] :: " << error << " :: " << function << " :: " << file << " :: " << line << "\n";
            return BLITZ_FALSE;
        }
        return BLITZ_TRUE;
    }
};
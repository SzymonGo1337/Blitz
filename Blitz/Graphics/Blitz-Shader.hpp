#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    class Shader {
    public:
        Shader();
        Shader(const char* vSS, const char* fSS);
        ~Shader();

        void Bind();
        void Unbind();

        uint GetUniformLocation(char* uniform);
        int GetAttribLocation(char* attrib);
        uint& GetProgram();

    private:
        uint m_program;

    };
};
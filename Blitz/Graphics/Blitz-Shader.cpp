#include "Blitz-Shader.hpp"

namespace Blitz {
    Shader::Shader() { }

    Shader::Shader(const char* vSS, const char* fSS) {
        uint vS = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vS, 1, &vSS, BLITZ_NULL);
        glCompileShader(vS);

        uint fS = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fS, 1, &fSS, BLITZ_NULL);
        glCompileShader(fS);

        m_program = glCreateProgram();
        glAttachShader(m_program, vS);
        glAttachShader(m_program, fS);
        glLinkProgram(m_program);
    }
        
    Shader::~Shader() {
        delete this;
    }

    void Shader::Bind() {
        glUseProgram(m_program);
    }
        
    void Shader::Unbind() {
        glUseProgram(BLITZ_NULL);
    }

    uint Shader::GetUniformLocation(char* uniform) {
        return glGetUniformLocation(m_program, uniform);
    }
        
    int Shader::GetAttribLocation(char* attrib) {
        return glGetAttribLocation(m_program, attrib);
    }
        
    uint& Shader::GetProgram() {
        return (uint&)m_program;
    }
};
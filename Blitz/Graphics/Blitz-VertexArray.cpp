#include "Blitz-VertexArray.hpp"

namespace Blitz {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);
    }

    VertexArray::~VertexArray() {
        delete this;
    }

    void VertexArray::Bind() {
        glBindVertexArray(m_vao);
    }

    void VertexArray::Unbind() {
        glBindVertexArray(BLITZ_NULL);
    }

    uint& VertexArray::GetVao() {
        return (uint&)m_vao;
    }
};
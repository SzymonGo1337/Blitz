#include "Blitz-VertexArray.hpp"

namespace Blitz {
    VertexArray::VertexArray() {
        BlitzGLCall(glGenVertexArrays(1, &m_vao));
        BlitzGLCall(glBindVertexArray(m_vao));
    }

    VertexArray::~VertexArray() {
        delete this;
    }

    void VertexArray::Bind() {
        BlitzGLCall(glBindVertexArray(m_vao));
    }

    void VertexArray::Unbind() {
        BlitzGLCall(glBindVertexArray(BLITZ_NULL));
    }

    uint& VertexArray::GetVao() {
        return (uint&)m_vao;
    }
};
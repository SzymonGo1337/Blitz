#include "Blitz-VertexBuffer.hpp"

namespace Blitz {
    VertexBuffer::VertexBuffer(VertexBufferUsage usage) {
        m_usage = usage;
        glGenBuffers(1, &m_vbo);
    }

    VertexBuffer::~VertexBuffer() {
        delete this;
    }
    
    void VertexBuffer::Bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    }
        
    void VertexBuffer::Unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, BLITZ_NULL);
    }

    void VertexBuffer::SetData(uint size, const void* data) {
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        if(m_usage == VertexBufferUsage::STATIC) {
            glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        } else if(m_usage == VertexBufferUsage::DYNAMIC) {
            glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
        }
    }

    uint& VertexBuffer::GetVbo() {
        return (uint&)m_vbo;
    }
}
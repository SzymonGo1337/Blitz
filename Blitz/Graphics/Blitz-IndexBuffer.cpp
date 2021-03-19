#include "Blitz-IndexBuffer.hpp"

namespace Blitz {
    IndexBuffer::IndexBuffer(IndexBufferUsage usage) {
        m_usage = usage;
        glGenBuffers(1, &m_ibo);
    }
    
    IndexBuffer::~IndexBuffer() {
        delete this;
    }

    void IndexBuffer::Bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    }

    void IndexBuffer::Unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BLITZ_NULL);
    }

    void IndexBuffer::SetData(uint size, const void* data) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
        if(m_usage == IndexBufferUsage::STATIC) {
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        } else if(m_usage == IndexBufferUsage::DYNAMIC) {
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
        }
    }

    uint& IndexBuffer::GetIbo() {
        return (uint&)m_ibo;
    }
};
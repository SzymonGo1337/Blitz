#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    enum class VertexBufferUsage {
        STATIC,
        DYNAMIC
    };

    class VertexBuffer {
    public:
        VertexBuffer(VertexBufferUsage usage = VertexBufferUsage::STATIC);
        ~VertexBuffer();

        void Bind();
        void Unbind();

        void SetData(uint size, const void* data);

        uint& GetVbo();

    private:
        VertexBufferUsage m_usage;
        uint m_vbo;

    };
};
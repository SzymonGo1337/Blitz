#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    enum class IndexBufferUsage {
        STATIC,
        DYNAMIC
    };

    class IndexBuffer {
    public:
        IndexBuffer(IndexBufferUsage usage = IndexBufferUsage::STATIC);
        ~IndexBuffer();

        void Bind();
        void Unbind();

        void SetData(uint size, const void* data);

        uint& GetIbo();

    private:
        uint m_ibo;
        IndexBufferUsage m_usage;

    };
};
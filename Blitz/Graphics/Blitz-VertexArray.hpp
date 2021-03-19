#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    class VertexArray {
    public: 
        VertexArray();
        ~VertexArray();

        void Bind();
        void Unbind();

        uint& GetVao();

    private:
        uint m_vao;

    };
};
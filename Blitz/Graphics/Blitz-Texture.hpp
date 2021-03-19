#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    class Texture {
    public:
        Texture();
        ~Texture();

        void Bind();
        void Unbind();

        void LoadTexture(const char* filename);

        static uint DynamicLoad(const char* filename);

    private:
        uint m_texture;

    };
};
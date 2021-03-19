#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    class Layer {
    public:
        Layer();
        ~Layer();

        bool IsVisible();
        void SetVisible(bool visible);

        void Render(bool update);

    private:
        bool m_visible;

    };
}
#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    class Layer {
    public:
        Layer();
        ~Layer();

        bool IsVisible();
        void SetVisible(bool visible);

    private:
        bool m_visible;

    };
}
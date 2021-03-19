#include "Blitz-Layer.hpp"

namespace Blitz {
    Layer::Layer() { }

    Layer::~Layer() {
        delete this;
    }

    bool Layer::IsVisible() {
        return m_visible;
    }

    void Layer::SetVisible(bool visible) {
        m_visible = visible;
    }
}
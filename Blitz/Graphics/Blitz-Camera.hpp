#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    enum class CameraProjection {
        PROJECTION,
        ORTHOGRAPHIC
    };

    class Camera {
    public:
        Camera(glm::vec4 parameters = { -1.0f * 16.0f / 9.0f * 0.5f, 1.0f * 16.0f / 9.0f * 0.5f, -1.0f * 0.5f, 1.0f * 0.5f }, CameraProjection usage = CameraProjection::ORTHOGRAPHIC);
        ~Camera();

        void SetViewProjection(uint u_viewProjection);
        void Move(glm::vec3 position = { 0.0f, 0.0f, 0.0f });

        glm::mat4x4& GetView();

    private:
        glm::vec3 m_position;
        glm::mat4x4 m_view;
        glm::mat4x4 m_projection;
        CameraProjection m_usage;

    };
};
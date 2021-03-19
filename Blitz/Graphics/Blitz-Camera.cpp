#include "Blitz-Camera.hpp"

namespace Blitz {
    Camera::Camera(CameraProjection usage) {
        m_view = glm::mat4x4(1);
        m_projection = glm::ortho(-1.0f * 16.0f / 9.0f * 0.5f, 1.0f * 16.0f / 9.0f * 0.5f, -1.0f * 0.5f, 1.0f * 0.5f, -1.0f, 1.0f);
    }
        
    Camera::~Camera() {
        delete this;
    }

    void Camera::SetViewProjection(uint u_viewProjection) {
        glm::mat4x4 viewProjection = m_projection * glm::inverse(m_view);
        glUniformMatrix4fv(u_viewProjection, 1, BLITZ_FALSE, glm::value_ptr(viewProjection));
    }

    void Camera::Move(glm::vec3 position) {
        m_view = glm::translate(m_view, position);
    }

    glm::mat4x4& Camera::GetView() {
        return (glm::mat4x4&)m_view;
    }
};
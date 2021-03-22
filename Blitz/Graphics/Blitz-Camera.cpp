#include "Blitz-Camera.hpp"

namespace Blitz {
    Camera::Camera(glm::vec4 parameters, CameraProjection usage) {
        m_view = glm::mat4x4(1);
        if(usage == CameraProjection::ORTHOGRAPHIC) {
            m_projection = glm::ortho(parameters.x, parameters.y, parameters.z, parameters.w, -1.0f, 1.0f);
            // m_projection = glm::ortho(-1.0f * 16.0f / 9.0f * 0.5f, 1.0f * 16.0f / 9.0f * 0.5f, -1.0f * 0.5f, 1.0f * 0.5f, -1.0f, 1.0f);
        } else if(usage == CameraProjection::PROJECTION) {
            m_projection = glm::perspective(parameters.x, parameters.y, parameters.z, parameters.w);
            // m_projection = glm::perspective(glm::radians(90.0f), (float)1280.0f / (float)720.0f, 0.001f, 1000.0f);
        }
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
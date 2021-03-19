#include "Blitz-Texture.hpp"

namespace Blitz {
    Texture::Texture() { }
        
    Texture::~Texture() {
        delete this;
    }

    void Texture::Bind() {
        BlitzGLCall(glBindTexture(GL_TEXTURE_2D, m_texture));
    }
        
    void Texture::Unbind() {
        glBindTexture(GL_TEXTURE_2D, BLITZ_NULL);
    }

    void Texture::LoadTexture(const char* filename) {
        m_texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
        BlitzGLCall(glBindTexture(GL_TEXTURE_2D, m_texture));
        BlitzGLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
        BlitzGLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    }

    uint Texture::DynamicLoad(const char* filename) {
        return SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
    }
};
#ifndef ENGINE_FRAMEBUFFER_INCLUDE
#define ENGINE_FRAMEBUFFER_INCLUDE

namespace Engine {

class Framebuffer {
private:
    uint32 FBO, RBO, width, height, texture;
public:
    Framebuffer() {}
    Framebuffer(const Framebuffer& buffer) {}
    void operator=(const Framebuffer& buffer) {}

    void initialize(uint32 width, uint32 height) {
        uint32 framebuffer;
        glGenFramebuffers(1, &framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        uint32 textureColorbuffer;
        glGenTextures(1, &textureColorbuffer);
        glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureColorbuffer, 0);

        uint32 rbo;
        glGenRenderbuffers(1, &rbo);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n";
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        FBO = framebuffer;
        RBO = rbo;
        texture = textureColorbuffer;

        this->width  = width;
        this->height = height;
    }

    void bind() {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    }

    uint32 get2DSampler() {
        return texture;
    }

    static void clearColorBuffer() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    static void clearDepthBuffer() {
        glClear(GL_DEPTH_BUFFER_BIT);
    }

    static void bindDefault() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    static char* readPixels(uint32 width, uint32 height) {
        char * pixels;
        glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_INT_8_8_8_8, pixels);
        return pixels;
    }
};

};
#endif // ENGINE_FRAMEBUFFER_INCLUDE

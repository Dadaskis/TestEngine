#ifndef ENGINE_FRAMEBUFFER_INCLUDE
#define ENGINE_FRAMEBUFFER_INCLUDE

namespace Engine {

namespace GL {

class Framebuffer {
   private:
    unsigned int FBO, RBO, width, height, texture;

   public:
    Framebuffer() {}
    Framebuffer(const Framebuffer& buffer) {}
    void operator=(const Framebuffer& buffer) {}

    void initialize(unsigned int width, unsigned int height) {
        unsigned int framebuffer;
        glGenFramebuffers(1, &framebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

        unsigned int textureColorbuffer;
        glGenTextures(1, &textureColorbuffer);
        glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                               GL_TEXTURE_2D, textureColorbuffer, 0);

        unsigned int rbo;
        glGenRenderbuffers(1, &rbo);
        glBindRenderbuffer(GL_RENDERBUFFER, rbo);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width,
                              height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                                  GL_RENDERBUFFER, rbo);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n";
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        FBO = framebuffer;
        RBO = rbo;
        texture = textureColorbuffer;

        this->width = width;
        this->height = height;
    }

    void bind() { glBindFramebuffer(GL_FRAMEBUFFER, FBO); }

    Texture getTexture() { return Texture(texture); }

    static void clearColorBuffer() { glClear(GL_COLOR_BUFFER_BIT); }

    static void clearDepthBuffer() { glClear(GL_DEPTH_BUFFER_BIT); }

    static void setClearColor(const glm::vec4& color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    static void bindDefault() { glBindFramebuffer(GL_FRAMEBUFFER, NULL); }

    static char* readPixels(unsigned int width, unsigned int height) {
        char* pixels;
        glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_INT_8_8_8_8,
                     pixels);
        return pixels;
    }
};

};  // namespace GL

};  // namespace Engine

#endif  // ENGINE_FRAMEBUFFER_INCLUDE

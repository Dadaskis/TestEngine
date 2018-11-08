#ifndef ENGINE_LIGHT_OPENGLINFO_INCLUDE
#define ENGINE_LIGHT_OPENGLINFO_INCLUDE

namespace Engine {

struct OpenGLLightInfo {
    glm::vec3 position,
        color,
        intensive,
        direction;
    int type,
        power;
};

};

#endif // ENGINE_LIGHT_OPENGLINFO_INCLUDE

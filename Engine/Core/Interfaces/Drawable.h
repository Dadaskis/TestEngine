#ifndef ENGINE_INTERFACE_DRAWABLE_INCLUDE
#define ENGINE_INTERFACE_DRAWABLE_INCLUDE

#include "../../OpenGL/Shader/Shader.h"

namespace Engine {
class Drawable {
public:
    virtual void draw(GL::Shader* GL::Shader);
};
};

#endif // ENGINE_INTERFACE_DRAWABLE_INCLUDE

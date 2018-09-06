#ifndef ENGINE_INTERFACE_DRAWABLE_INCLUDE
#define ENGINE_INTERFACE_DRAWABLE_INCLUDE

#include "../Shader/Shader.h"

namespace Engine {
class Drawable {
public:
    virtual void draw(Shader* shader);
};
};

#endif // ENGINE_INTERFACE_DRAWABLE_INCLUDE

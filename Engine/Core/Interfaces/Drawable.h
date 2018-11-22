#ifndef ENGINE_INTERFACE_DRAWABLE_INCLUDE
#define ENGINE_INTERFACE_DRAWABLE_INCLUDE

namespace Engine {

namespace Interfaces {

class Drawable;
}

GLOBAL_RESOURCES_ARRAY_DEFINE(Interfaces::Drawable, drawables, GetDrawables);

namespace Interfaces {

class Drawable {
   public:
    Drawable() {
        GLOBAL_RESOURCES_ARRAY_REGISTER(drawables);
    }

    virtual void draw() = 0;

    ~Drawable() { GLOBAL_RESOURCES_ARRAY_REMOVE(drawables) }
};

};  // namespace Interfaces

};  // namespace Engine

#endif  // ENGINE_INTERFACE_DRAWABLE_INCLUDE

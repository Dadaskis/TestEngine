#ifndef ENGINE_INTERFACE_DRAWABLE_INCLUDE
#define ENGINE_INTERFACE_DRAWABLE_INCLUDE

namespace Engine {

namespace Interfaces {

class Drawable;
}

namespace Global {

namespace Private {

std::vector<::Engine::Interfaces::Drawable*> drawables;
}

const std::vector<::Engine::Interfaces::Drawable*>& getDrawables() {
    return Private::drawables;
}

};  // namespace Global

namespace Interfaces {

class Drawable {
   private:
    std::vector<Drawable*>::iterator drawableIterator;

   public:
    Drawable() {
        Global::Private::drawables.push_back(this);
        drawableIterator = Global::Private::drawables.end();
    }

    virtual void draw() = 0;

    ~Drawable() { Global::Private::drawables.erase(drawableIterator); }
};

};  // namespace Interfaces

};  // namespace Engine

#endif  // ENGINE_INTERFACE_DRAWABLE_INCLUDE

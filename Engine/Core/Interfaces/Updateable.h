#ifndef ENGINE_INTERFACE_UPDATEABLE_INCLUDE
#define ENGINE_INTERFACE_UPDATEABLE_INCLUDE

namespace Engine {

namespace Interfaces {

class Updateable;
};

namespace Global {

namespace Private {

std::vector<::Engine::Interfaces::Updateable*> updateables;
};

const std::vector<::Engine::Interfaces::Updateable*>& getUpdateables() {
    return Private::updateables;
}

};  // namespace Global

namespace Interfaces {

class Updateable {
   private:
    std::vector<Updateable*>::iterator iterator;

   public:
    Updateable() {
        Global::Private::updateables.push_back(this);
        iterator = Global::Private::updateables.end();
    }

    virtual void update() = 0;
};

};  // namespace Interfaces

};  // namespace Engine

#endif  // ENGINE_INTERFACE_UPDATEABLE_INCLUDE

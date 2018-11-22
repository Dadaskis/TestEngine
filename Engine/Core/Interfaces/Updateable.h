#ifndef ENGINE_INTERFACE_UPDATEABLE_INCLUDE
#define ENGINE_INTERFACE_UPDATEABLE_INCLUDE

namespace Engine {

namespace Interfaces {

class Updateable;
};

GLOBAL_RESOURCES_ARRAY_DEFINE(Interfaces::Updateable, updateables, GetUpdateables);

namespace Interfaces {

class Updateable {
   public:
    Updateable() {
        GLOBAL_RESOURCES_ARRAY_REGISTER(updateables);
    }

    virtual void update() = 0;

    ~Updateable(){
        GLOBAL_RESOURCES_ARRAY_REMOVE(updateables);
    }
};

};  // namespace Interfaces

};  // namespace Engine

#endif  // ENGINE_INTERFACE_UPDATEABLE_INCLUDE

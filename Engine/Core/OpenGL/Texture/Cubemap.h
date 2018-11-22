#ifndef ENGINE_CORE_OPENGL_TEXTURE_CUBEMAP
#define ENGINE_CORE_OPENGL_TEXTURE_CUBEMAP

namespace Engine {

namespace GL {

class Cubemap;
};


GLOBAL_RESOURCES_ARRAY_DEFINE(GL::Cubemap, cubemaps, GetCubemaps);

namespace GL {

class Cubemap : public Texture {
   public:
    Cubemap(int ID) {
        GLOBAL_RESOURCES_ARRAY_REGISTER(cubemaps);
    }

    ~Cubemap(){
        GLOBAL_RESOURCES_ARRAY_REMOVE(cubemaps);
    }
};

};  // namespace GL

};  // namespace Engine

#endif
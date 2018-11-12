#ifndef ENGINE_CORE_OPENGL_TEXTURE_CUBEMAP
#define ENGINE_CORE_OPENGL_TEXTURE_CUBEMAP

namespace Engine {

namespace GL {

class Cubemap;
};

namespace Global {

namespace Private {

std::vector<::Engine::GL::Cubemap*> cubemaps;
};

const std::vector<::Engine::GL::Cubemap*>& getCubemaps() {
    return Private::cubemaps;
}

};  // namespace Global

namespace GL {

class Cubemap : public Texture {
   private:
    std::vector<Cubemap*>::iterator iterator;

   public:
    Cubemap(int ID) {
        Engine::Global::Private::cubemaps.push_back(this);
        iterator = Global::Private::cubemaps.end();
    }
};

};  // namespace GL

};  // namespace Engine

#endif
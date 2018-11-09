#ifndef ENGINE_TEXTURE_INCLUDE
#define ENGINE_TEXTURE_INCLUDE

namespace Engine {

namespace GL {

class Texture;

};

namespace Global{

namespace Private{

std::vector<GL::Texture*> textures;

};

const std::vector<GL::Texture*>& getTextures(){
    return Private::textures;
}

};

namespace GL{

class Texture {
private:
    uint32 ID;
    int activeUnit;
    std::string type;
    std::string path;
    std::vector<Texture*>::iterator iterator;
public:
    Texture() {}
    Texture(int ID) {
        this->ID = ID;
        Engine::Global::Private::textures.push_back(this);
        iterator = Global::Private::textures.end();
    }

    const std::string& getPath() const {
        return path;
    }

    void setPath(const std::string& path){
        this->path = path;
    }

    const std::string& getType() const {
        return type;
    }

    void setType(const std::string& type){
        this->type = type;
    }

    const uint32& getID() const {
        return ID;
    }

    void setActiveUnit(int activeUnit){
        glActiveTexture(GL_TEXTURE0 + activeUnit);
        this->activeUnit = activeUnit;
    }

    int getActiveUnit() const {
        return activeUnit;
    }

    void bind() {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void bind(int unit){
        glBindTexture(GL_TEXTURE_2D, ID);
        setActiveUnit(unit);
    }

    void release(){
        glDeleteTextures(1, &ID);
        Global::Private::textures.erase(iterator);
    }
};

};

};

#endif // ENGINE_TEXTURE_INCLUDE

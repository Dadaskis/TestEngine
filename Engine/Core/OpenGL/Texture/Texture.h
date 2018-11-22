#ifndef ENGINE_TEXTURE_INCLUDE
#define ENGINE_TEXTURE_INCLUDE

namespace Engine {

namespace GL {

class Texture;

};

GLOBAL_RESOURCES_ARRAY_DEFINE(GL::Texture, textures, GetTextures);

namespace GL{

class Texture {
private:
    unsigned int ID;
    int activeUnit;
    std::string type;
    std::string path;
public:
    Texture() {}
    
    Texture(int ID) {
        this->ID = ID;
        GLOBAL_RESOURCES_ARRAY_REGISTER(textures);
    }

    Texture(const std::string& path){
        this->ID = TextureUtilities::loadTexture(path);
        this->path = path;
        Engine::Global::Private::textures.push_back(this);
        iterator = Global::Private::textures.end();
    }

    const std::string& getPath() const {
        return path;
    }

    const std::string& getType() const {
        return type;
    }

    void setType(const std::string& type){
        this->type = type;
    }

    const unsigned int getID() const {
        return ID;
    }

    void setActiveUnit(int activeUnit) {
        glActiveTexture(GL_TEXTURE0 + activeUnit);
        this->activeUnit = activeUnit;
    }

    void setActiveUnit(int activeUnit) const {
        glActiveTexture(GL_TEXTURE0 + activeUnit);
    }

    int getActiveUnit() const {
        return activeUnit;
    }

    void bind() const {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void bind(int unit) const {
        setActiveUnit(unit);
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void release(){
        glDeleteTextures(1, &ID);
        GLOBAL_RESOURCES_ARRAY_REMOVE(textures);
    }
};

};

};

#endif // ENGINE_TEXTURE_INCLUDE

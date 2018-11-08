#ifndef ENGINE_TEXTURE_INCLUDE
#define ENGINE_TEXTURE_INCLUDE

namespace Engine {

class Texture;

namespace Global{

namespace Private{

std::vector<Texture*> textures;

};

const std::vector<Texture*>& getTextures(){
    return Private::textures;
}

};

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
        Global::Private::textures.push_back(this);
        iterator = Global::Private::textures.end();
    }

    std::string& getPath(){
        return path;
    }

    void setPath(std::string& path){
        this->path = path;
    }

    std::string& getType(){
        return type;
    }

    void setType(std::string& type){
        this->type = type;
    }

    uint32& getID(){
        return ID;
    }

    void setActiveUnit(int activeUnit){
        glActiveTexture(GL_TEXTURE0 + activeUnit);
        this->activeUnit = activeUnit;
    }

    int getActiveUnit() {
        return activeUnit;
    }

    void bind() {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void bind(int unit){
        bind();
        setActiveUnit(unit);
    }

    void release(){
        glDeleteTextures(1, &ID);
        std::erase(iterator);
    }
};

};

#endif // ENGINE_TEXTURE_INCLUDE

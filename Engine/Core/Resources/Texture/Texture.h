#ifndef ENGINE_TEXTURE_INCLUDE
#define ENGINE_TEXTURE_INCLUDE

namespace Engine {

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

    unsigned int& getID(){
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
    }
};

};

#endif // ENGINE_TEXTURE_INCLUDE

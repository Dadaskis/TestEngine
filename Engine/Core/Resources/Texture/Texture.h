#ifndef ENGINE_TEXTURE_INCLUDE
#define ENGINE_TEXTURE_INCLUDE

namespace Engine {
struct Texture {
    int ID;
    std::string type;
    std::string path;
    int activeUnit;

    Texture() {}
    Texture(int ID) {
        this->ID = ID;
    }

    void bind(int unit) {
        glActiveTexture(GL_TEXTURE0 + unit);
        activeUnit = unit;
        glBindTexture(GL_TEXTURE_2D, ID);
        glActiveTexture(GL_TEXTURE0);
    }

    int getActiveUnit() {
        return activeUnit;
    }
};
};

#endif // ENGINE_TEXTURE_INCLUDE

#ifndef ENGINE_LIGHT_INTERFACE_INCLUDE
#define ENGINE_LIGHT_INTERFACE_INCLUDE

namespace Engine {

enum LIGHT_TYPES {
    LIGHT_TYPE_DEFAULT,
    LIGHT_TYPE_SUNLIKE
};

class LightInterface {
private:
    glm::vec3 color;
    glm::vec3 intensive;
    glm::vec3 position;
    int type;
    int power;
protected:
    void setType(int type) {
        this->type = type;
    }
public:
    void setColor(const glm::vec3& color) {
        this->color = color;
    }

    glm::vec3 getColor() {
        return color;
    }

    void setIntensive(const glm::vec3& intensive) {
        this->intensive = intensive;
    }

    glm::vec3 getIntensive() {
        return intensive;
    }

    void setPosition(const glm::vec3& position) {
        this->position = position;
    }

    glm::vec3 getPosition() {
        return position;
    }

    int getType() {
        return type;
    }

    void setPower(int power) {
        this->power = power;
    }

    int getPower() {
        return power;
    }

    virtual ~LightInterface() {}
};

};

#endif // ENGINE_LIGHT_INTERFACE_INCLUDE

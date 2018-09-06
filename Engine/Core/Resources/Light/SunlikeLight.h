#ifndef ENGINE_LIGHT_SUNLIKE_INCLUDE
#define ENGINE_LIGHT_SUNLIKE_INCLUDE

#include "LightInterface.h"

namespace Engine {

class SunlikeLight : protected LightInterface {
private:
    glm::vec3 direction;
public:
    SunlikeLight(const glm::vec3& color = glm::vec3(1.0),
                 const glm::vec3& intensive = glm::vec3(1.0),
                 const glm::vec3& direction = glm::vec3(1.0),
                 int power = 1) {
        this->setColor(color);
        this->setIntensive(intensive);
        this->direction = direction;
        this->setType(LIGHT_TYPE_SUNLIKE);
        this->setPower(power);
    }

    void setDirection(const glm::vec3& direction) {
        this->direction = direction;
        this->setPosition(this->direction * glm::vec3(2000000000));
    }

    glm::vec3 getDirection() {
        return direction;
    }
};

};
#endif // ENGINE_LIGHT_SUNLIKE_INCLUDE

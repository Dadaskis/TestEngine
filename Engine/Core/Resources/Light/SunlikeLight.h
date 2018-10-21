#ifndef ENGINE_LIGHT_SUNLIKE_INCLUDE
#define ENGINE_LIGHT_SUNLIKE_INCLUDE

#include "LightInterface.h"

namespace Engine {

class SunlikeLight : public LightInterface {
public:
    SunlikeLight(const glm::vec3& color = glm::vec3(1.0),
                 const glm::vec3& intensive = glm::vec3(1.0),
                 const glm::vec3& direction = glm::vec3(1.0),
                 int power = 1) {
        this->setColor(color);
        this->setIntensive(intensive);
        this->setType(LIGHT_TYPE_SUNLIKE);
        this->setPower(power);
    }
};

};
#endif // ENGINE_LIGHT_SUNLIKE_INCLUDE

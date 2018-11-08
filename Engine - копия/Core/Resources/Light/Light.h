#ifndef ENGINE_LIGHT_DEFAULT_INCLUDE
#define ENGINE_LIGHT_DEFAULT_INCLUDE

#include "LightInterface.h"

namespace Engine {

class Light : public LightInterface {
public:
    Light(const glm::vec3& color = glm::vec3(1.0),
          const glm::vec3& intensive = glm::vec3(1.0),
          const glm::vec3& position = glm::vec3(1.0),
          int power = 1) {
        this->setColor(color);
        this->setIntensive(intensive);
        this->setPosition(position);
        this->setType(LIGHT_TYPE_DEFAULT);
        this->setPower(power);
    }
};

};

#endif // ENGINE_LIGHT_DEFAULT_INCLUDE

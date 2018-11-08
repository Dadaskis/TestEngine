#ifndef ENGINE_GAME_OBJECT_DRAWABLE_INCLUDE
#define ENGINE_GAME_OBJECT_DRAWABLE_INCLUDE

#include "GameObject.h"
#include "../Interfaces/Drawable.h"

namespace Engine {

class DGameObject : GameObject, Drawable {
private:
    Model* model;
    glm::mat4 modelSpace = glm::mat4(1.0);
    glm::vec3 position = glm::vec3(0.0);
public:
    DGameObject(){}
    DGameObject(const DGameObject& gameObject){
        model = gameObject.model;
        modelSpace = gameObject.modelSpace;
        position = gameObject.position;
    }
    void operator=(const DGameObject& gameObject){
        model = gameObject.model;
        modelSpace = gameObject.modelSpace;
        position = gameObject.position;
    }

    Model* getModel() {
        return model;
    }

    void setModel(Model* model) {
        this->model = model;
    }

    void setModelMatrix(const glm::mat4& matrix){
        modelSpace = matrix;
    }

    glm::mat4* getModelMatrix(){
        return &modelSpace;
    }

    glm::vec3 getPosition() {
        return position;
    }

    void setPosition(const glm::vec3& position) {
        modelSpace = glm::translate(glm::mat4(1.0), position);
        this->position = position;
    }

    void draw(GL::Shader* GL::Shader) {
        GL::Shader->use();
        GL::Shader->setMat4("model", modelSpace);
        model->draw(GL::Shader);
    }
};

};

#endif // ENGINE_GAME_OBJECT_DRAWABLE_INCLUDE

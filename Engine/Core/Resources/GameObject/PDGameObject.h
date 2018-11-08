#ifndef ENGINE_GAME_OBJECT_DRAWABLE_PHYSICAL_INCLUDE
#define ENGINE_GAME_OBJECT_DRAWABLE_PHYSICAL_INCLUDE

#include "GameObject.h"
#include "../Interfaces/Drawable.h"
#include "../Interfaces/Updateable.h"
#include "../../Physics/Object.h"

namespace Engine{

class PDGameObject : GameObject, Drawable, Updateable{
private:
    DGameObject dObject;
    Physics::Object object;
public:
    PDGameObject(){}
    PDGameObject(const PDGameObject& pDGameObject)
    : dObject(pDGameObject.dObject)
    , object(pDGameObject.object)
    {}
    PDGameObject(const DGameObject& drawObject, const Physics::Object& physObject)
    : dObject(drawObject)
    , object(physObject)
    {}

    Model* getModel() {
        return dObject.getModel();
    }

    void setModel(Model* model) {
        dObject.setModel(model);
    }

    void setModelMatrix(const glm::mat4& matrix){
        dObject.setModelMatrix(matrix);
    }

    glm::mat4* getModelMatrix(){
        return dObject.getModelMatrix();
    }

    glm::vec3 getPosition() {
        return object.getPosition();
    }

    void setPosition(const glm::vec3& position) {
        object.setPosition(position);
        dObject.setPosition(position);
    }

    Physics::Object* getPhysicsObject(){
        return &object;
    }

    void draw(GL::Shader* GL::Shader) {
        dObject.draw(GL::Shader);
    }

    void update(float deltaTime){
        dObject.setModelMatrix(object.getMatrix());
    }
};

};

#endif // ENGINE_GAME_OBJECT_DRAWABLE_PHYSICAL_INCLUDE

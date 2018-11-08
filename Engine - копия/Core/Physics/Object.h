#ifndef ENGINE_PHYSICS_OBJECT_INCLUDE
#define ENGINE_PHYSICS_OBJECT_INCLUDE

namespace Engine{

namespace Physics{

class Object{
private:
    btDiscreteDynamicsWorld* world;
    btCollisionShape* collision;
    btRigidBody* body;
public:
    Object(){}
    Object(btDiscreteDynamicsWorld* world){
        this->world = world;
    }
    Object(const Object& object){
        this->world = object.world;
    }
    void operator=(const Object& object){
        this->world = object.world;
    }

    void setCollider(Model* model){
        collision = (btCollisionShape*)model->getCollision();
    }

    void setStaticCollider(Model* model){
        collision = (btCollisionShape*)model->getStaticCollision();
    }

    void setCollision(btCollisionShape* collision){
        this->collision = collision;
    }

    void createBody(){
        btDefaultMotionState* motionState = new btDefaultMotionState();
        body = new btRigidBody(1.0f, motionState, collision, btVector3(1, 1, 1));
        world->addRigidBody(body);
    }

    void setPosition(const glm::vec3& position){
        btTransform transform;
        transform = body->getWorldTransform();
        transform.setOrigin(btVector3(position.x, position.y, position.z));
        body->setWorldTransform(transform);
    }

    glm::vec3 getPosition(){
        btTransform transform;
        transform = body->getWorldTransform();
        btVector3 btPosition = transform.getOrigin();
        return glm::vec3(btPosition.x(), btPosition.y(), btPosition.z());
    }

    void setMatrix(const glm::mat4& matrix){
        btTransform transform;
        transform = body->getWorldTransform();
        transform.setFromOpenGLMatrix(&matrix[0][0]);
        body->setWorldTransform(transform);
    }

    glm::mat4 getMatrix(){
        btTransform transform;
        transform = body->getWorldTransform();
        glm::mat4 matrix;
        transform.getOpenGLMatrix(&matrix[0][0]);
        return matrix;
    }

    void setForce(const glm::vec3& force){
        body->applyCentralForce(btVector3(force.x, force.y, force.z));
    }

    glm::vec3 getForce(){
        btVector3 btForce = body->getTotalForce();
        return glm::vec3(btForce.x(), btForce.y(), btForce.z());
    }

    void setMass(const glm::vec4& mass){
        body->setMassProps(mass.w, btVector3(mass.x, mass.y, mass.z));
    }

    glm::vec4 getMass(){
        glm::vec4 mass;
        btVector3 btInertia = body->getLocalInertia();
        mass.x = btInertia.x();
        mass.y = btInertia.y();
        mass.z = btInertia.z();
        mass.w = body->getInvMass();
        return mass;
    }

    void setVelocity(const glm::vec3& velocity){
        body->setLinearVelocity(btVector3(velocity.x, velocity.y, velocity.z));
    }

    glm::vec3 getVelocity(){
        btVector3 btVelocity = body->getLinearVelocity();
        return glm::vec3(btVelocity.x(), btVelocity.y(), btVelocity.z());
    }

    bool isStatic(){
        return body->isStaticObject();
    }
};

};

};


#endif // ENGINE_PHYSICS_OBJECT_INCLUDE

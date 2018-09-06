#ifndef ENGINE_RESOURCE_MANAGER_INCLUDE
#define ENGINE_RESOURCE_MANAGER_INCLUDE

#include <vector>
#include <BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h>

#include "Camera/Camera.h"
#include "Model/Model.h"
#include "Shader/Shader.h"
#include "Light/SunlikeLight.h"
#include "Light/Light.h"
#include "Primitives/Plate/Plate.h"
#include "Light/OpenGLLightInfo.h"
#include "GameObject/DGameObject.h"
#include "GameObject/PDGameObject.h"

namespace Engine {

class ResourceManager {
private:
    std::vector<Camera*> cameras;
    std::vector<Model*> models;
    std::vector<Shader*> shaders;
    std::vector<SunlikeLight*> sunlikeLights;
    std::vector<Light*> lights;
    std::vector<int> skyboxCubemaps;
    std::vector<OpenGLLightInfo> lightsInfo;
    std::vector<Plate*> plates;
    std::vector<GameObject*> gameObjects;
    std::vector<DGameObject*> dGameObjects;
    std::vector<PDGameObject*> pDGameObjects;

    Camera* currentCamera;
    Texture* errorTexture;
    glm::mat4* projection;

    btDiscreteDynamicsWorld* physicsWorld;

    void translateLightInfo(LightInterface* light) {
        OpenGLLightInfo info;

        info.color = light->getColor();
        info.intensive = light->getIntensive();
        info.position = light->getPosition();
        info.direction = glm::vec3(-2.0, -2.0, -2.0);
        info.power = light->getPower();
        info.type = light->getType();
        if(light->getType() == LIGHT_TYPE_SUNLIKE) {
            SunlikeLight* sunLight = reinterpret_cast<SunlikeLight*>(light);
            info.direction = sunLight->getDirection();
        }

        lightsInfo.push_back(info);
    }

public:
    ResourceManager() {
        btBroadphaseInterface* bpInterface = new btDbvtBroadphase();
        btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
        btCollisionConfiguration* config = new btDefaultCollisionConfiguration();
        btCollisionDispatcher* dispatcher = new btCollisionDispatcher(config);
        btGImpactCollisionAlgorithm::registerAlgorithm(dispatcher);

        physicsWorld = new btDiscreteDynamicsWorld(dispatcher, bpInterface, solver, config);
    }

    ResourceManager(const ResourceManager& manager) {}
    void operator=(const ResourceManager& manager) {}

    void setProjection(glm::mat4* projection) {
        this->projection = projection;
    }

    glm::mat4* getProjection() {
        return projection;
    }


    btDiscreteDynamicsWorld* getPhysicsWorld(){
        return physicsWorld;
    }


    void updateLightsInfo(Shader* shader) {
        shader->use();
        shader->setInt("lightsCount", lightsInfo.size());
        for(int index = 0; index < lightsInfo.size(); index++) {
            std::string lightUniform = std::string("lights[") + std::to_string(index) + std::string("]");
            shader->setVec3(lightUniform + ".color", lightsInfo[index].color);
            shader->setVec3(lightUniform + ".direction", lightsInfo[index].direction);
            shader->setVec3(lightUniform + ".intensive", lightsInfo[index].intensive);
            shader->setVec3(lightUniform + ".position", lightsInfo[index].position);
            shader->setInt(lightUniform + ".type", lightsInfo[index].type);
            shader->setInt(lightUniform + ".power", lightsInfo[index].power);
        }
    }


    Camera* createCamera() {
        Camera* newCamera = new Camera();
        cameras.push_back(newCamera);
        return newCamera;
    }

    Camera* getCamera(int key) {
        return cameras[key];
    }

    void setCurrentCamera(Camera* camera) {
        currentCamera = camera;
    }

    Camera* getCurrentCamera() {
        return currentCamera;
    }

    int getCamerasCount() {
        return cameras.size();
    }

    void deleteCamera(int key) {
        delete cameras[key];
        cameras.erase(cameras.begin() + key);
    }


    Model* loadModel(const std::string& path) {
        Model* model = new Model(physicsWorld, path);
        models.push_back(model);
        return model;
    }

    Model* getModel(int key) {
        return models[key];
    }

    int getModelsCount() {
        return models.size();
    }

    void deleteModel(int key) {
        delete models[key];
        models.erase(models.begin() + key);
    }


    Shader* createShader() {
        Shader* newShader = new Shader();
        shaders.push_back(newShader);
        return newShader;
    }

    Shader* getShader(int key) {
        return shaders[key];
    }

    int getShadersCount() {
        return shaders.size();
    }

    void deleteShader(int key) {
        delete shaders[key];
        shaders.erase(shaders.begin() + key);
    }


    SunlikeLight* createSunlikeLight(const glm::vec3& color = glm::vec3(1.0),
                                     const glm::vec3& intensive = glm::vec3(1.0),
                                     const glm::vec3& direction = glm::vec3(1.0)) {
        SunlikeLight* light = new SunlikeLight(color, intensive, direction, 1);
        sunlikeLights.push_back(light);
        translateLightInfo((LightInterface*)light);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)NULL);
        return light;
    }

    SunlikeLight* getSunlikeLight(int key) {
        return sunlikeLights[key];
    }

    int getSunlikeLightsCount() {
        return sunlikeLights.size();
    }

    void deleteSunlikeLight(int key) {
        delete sunlikeLights[key];
        sunlikeLights.erase(sunlikeLights.begin() + key);
    }


    Light* createLight(const glm::vec3& color = glm::vec3(1.0),
                       const glm::vec3& intensive = glm::vec3(1.0),
                       const glm::vec3& position = glm::vec3(1.0),
                       int power = 1) {
        Light* light = new Light(color, intensive, position, power);
        lights.push_back(light);
        translateLightInfo((LightInterface*)light);
        return light;
    }

    Light* getLight(int key) {
        return lights[key];
    }

    int getLightsCount() {
        return lights.size();
    }

    void deleteLight(int key) {
        delete lights[key];
        lights.erase(lights.begin() + key);
    }


    unsigned int loadSkybox(
        const std::string& right,
        const std::string& left,
        const std::string& top,
        const std::string& bottom,
        const std::string& back,
        const std::string& front
    ) {
        std::vector<std::string> skyboxTemplate = {
            right, left,
            top, bottom,
            back, front
        };
        unsigned int cubemap = TextureUtilities::loadCubemap(skyboxTemplate);
        skyboxCubemaps.push_back(cubemap);
        return cubemap;
    }

    unsigned int getSkyboxCubemap(int key) {
        return skyboxCubemaps[key];
    }

    int getSkyboxesCount() {
        return skyboxCubemaps.size();
    }

    void deleteSkybox(int key) {
        skyboxCubemaps.erase(skyboxCubemaps.begin() + key);
    }


    Plate* createPlate() {
        Plate* plate = new Plate();
        plates.push_back(plate);
        return plate;
    }

    Plate* getPlate(int key) {
        return plates[key];
    }

    int getPlatesCount() {
        return plates.size();
    }

    void deletePlate(int key) {
        delete plates[key];
        plates.erase(plates.begin() + key);
    }


    DGameObject* createDGameObject() {
        DGameObject* object = new DGameObject();
        dGameObjects.push_back(object);
        gameObjects.push_back((GameObject*)object);
        return object;
    }

    DGameObject* getDGameObject(int key) {
        return dGameObjects[key];
    }

    int getDGameObjectsCount() {
        return dGameObjects.size();
    }

    void deleteDGameObject(int key) {
        delete dGameObjects[key];
        dGameObjects.erase(dGameObjects.begin() + key);
    }


    PDGameObject* createPDGameObject(){
        PDGameObject* object = new PDGameObject(DGameObject(), Physics::Object(physicsWorld));
        pDGameObjects.push_back(object);
        gameObjects.push_back((GameObject*)object);
        return object;
    }

    PDGameObject* getPDGameObject(int key){
        return pDGameObjects[key];
    }

    int getPDGameObjectsCount(){
        return pDGameObjects.size();
    }

    void deletePDGameObject(int key){
        delete pDGameObjects[key];
        pDGameObjects.erase(pDGameObjects.begin() + key);
    }
};

};

#endif // ENGINE_RESOURCE_MANAGER_INCLUDE

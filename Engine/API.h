#ifndef ENGINE_INCLUDE
#define ENGINE_INCLUDE

#include <BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <btBulletDynamicsCommon.h>
#include <algorithm>
#include <assimp/Importer.hpp>
#include <fstream>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Core/Interfaces/InterfacesHeader.h"
#include "Core/Physics/Integration.h"
#include "Core/Utilities/Keys.h"
#include "Core/Utilities/Utilities.h"
#include "Core/Window/Window.h"
#include "Core/OpenGL/GLHeaders.h"
#include "Core/Resources/ResourcesHeaders.h"


namespace Engine {

class API : public Window{
   private:
    btDiscreteDynamicsWorld* physicsWorld;
    float physicsFramerate;

   public:
    void setPhysicsFramerate(float framerate) { physicsFramerate = framerate; }

    const float& getPhysicsFramerate() { return physicsFramerate; }

    void updatePhysics() { physicsWorld->stepSimulation(physicsFramerate); }

    void enableDepthTest() { glEnable(GL_DEPTH_TEST); }

    void disableDepthTest() { glDisable(GL_DEPTH_TEST); }

    void draw() {
        runBindings();
        swapBuffers();
    }

    void enableCulling() { glEnable(GL_CULL_FACE); }

    void disableCulling() { glDisable(GL_CULL_FACE); }

    void setCullingBack() { glCullFace(GL_BACK); }

    void setCullingFront() { glCullFace(GL_FRONT); }

    void setCullingBoth() { glCullFace(GL_FRONT_AND_BACK); }

    API(unsigned int width, unsigned int height, const std::string& title) {
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);

        glDepthFunc(GL_LESS);

        Global::Plate::initialize();

        // btDispatcher* dispatcher = btCollisionDispatcher();
        // btBroadphase* broadphase = btDbvt
        // physicsWorld = new btDiscreteDynamicsWorld(dispatcher, );
        // Engine::Physics::Dispatcher::Base::registerCollisionAlgorithm();
        // Dispatcher::registerCollisionAlgorithm
    }

    API() { API(800, 600, "Engine"); }

    ~API() {}
};

};  // namespace Engine

#endif  // ENGINE_INCLUDE

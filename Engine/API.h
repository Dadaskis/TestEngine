#ifndef ENGINE_INCLUDE
#define ENGINE_INCLUDE

#include <glad/glad.h>
#include <btBulletDynamicsCommon.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include <glm/glm.hpp>

#include "Core/Utilities/Utilities.h"
#include "Core/Utilities/Keys.h"
#include "Core/OpenGL/GLHeaders.h"
#include "Core/Window/Window.h"
#include "Core/Physics/Integration.h"
#include "Core/Resources/ResourcesHeaders.h"
#include "Core/Event/Event.h"
#include "Core/Framebuffer/Framebuffer.h"

namespace Engine {

class API : public Window, public Event {
private:
    btDiscreteDynamicsWorld* physicsWorld;
    float physicsFramerate;    
public:
    void setPhysicsFramerate(float framerate){
        physicsFramerate = framerate;
    }

    const float& getPhysicsFramerate(){
        return physicsFramerate;
    }

    void updatePhysics(){
        physicsWorld->stepSimulation(physicsFramerate);
    }

    void enableDepthTest() {
        glEnable(GL_DEPTH_TEST);
    }

    void disableDepthTest() {
        glDisable(GL_DEPTH_TEST);
    }

    void draw() {
        runEvent("Loop");
        runBindings();
        swapBuffers();
    }

    void enableCulling(){
        glEnable(GL_CULL_FACE);
    }

    void disableCulling(){
        glDisable(GL_CULL_FACE);
    }

    void setCullingBack(){
        glCullFace(GL_BACK);
    }

    void setCullingFront(){
        glCullFace(GL_FRONT);
    }

    void setCullingBoth(){
        glCullFace(GL_FRONT_AND_BACK);
    }

    API(uint32 width, uint32 height, const std::string& title) {
        createWindow(width, height, title);

        glEnable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
        
        glDepthFunc(GL_LESS);

        createEvent("Loop");

        Global::Plate::initialize();

        //btDispatcher* dispatcher = btCollisionDispatcher();
        //btBroadphase* broadphase = btDbvt
        //physicsWorld = new btDiscreteDynamicsWorld(dispatcher, );
        //Engine::Physics::Dispatcher::Base::registerCollisionAlgorithm();
        //Dispatcher::registerCollisionAlgorithm
    }

    API() {
        API(800, 600, "Engine");
    }

    ~API() {}
};

};

#endif // ENGINE_INCLUDE

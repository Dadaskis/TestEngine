#ifndef ENGINE_INCLUDE
#define ENGINE_INCLUDE

#include <glad/glad.h>
#include <btBulletDynamicsCommon.h>

#include "Core/OpenGL/Buffer/Buffer.h"
#include "Core/Window/Window.h"
#include "Core/Resources/ResourceManager.h"
#include "Core/Skybox/Skybox.h"
#include "Core/Event/Event.h"
#include "Core/Framebuffer/Framebuffer.h"

namespace Engine {

class API : public Window, public ResourceManager, public Event {
private:
    Skybox* skybox;

    glm::mat4 projection;
public:
    void updatePhysics(){
        getPhysicsWorld()->stepSimulation(getDeltaTime());
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

    API(unsigned int width, unsigned int height, const std::string& title) {
        createWindow(width, height, title);

        glEnable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
        
        glDepthFunc(GL_LESS);

        projection = glm::perspective(glm::radians(90.0f), getWidth() / getHeight(), 0.0001f, 10000000.0f);
        setProjection(&projection);

        Plate::getPlateBase()->initialize();

        skybox = new Skybox();
        skybox->setProjection(projection);

        createEvent("Loop");
    }

    API() {
        API(800, 600, "Engine");
    }

    ~API() {}
};

};

#endif // ENGINE_INCLUDE

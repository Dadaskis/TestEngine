#ifndef ENGINE_INCLUDE
#define ENGINE_INCLUDE

#include <glad/glad.h>
#include <glad/glad.h>

#include <btBulletDynamicsCommon.h>
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

    ImGuiIO& imguiIO;
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

    void drawSkybox() {
        skybox->setView(getCurrentCamera()->getViewMatrix());
        skybox->draw();
    }

    void draw() {
        ImGui::EndFrame();

        ImDrawData* drawData = ImGui::GetDrawData();
        drawData->CmdLists

        runEvent("Loop");
        runBindings();
        swapBuffers();
        ImGui::NewFrame();
        imguiIO.DeltaTime = getDeltaTime();
    }

    void setSkybox(unsigned int cubemap) {
        skybox->setCubemap(cubemap);
    }

    API(unsigned int width, unsigned int height, const std::string& title) {
        createWindow(width, height, title);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glDepthFunc(GL_LESS);

        projection = glm::perspective(glm::radians(90.0f), getWidth() / getHeight(), 0.0001f, 10000000.0f);
        setProjection(&projection);

        Plate::getPlateBase()->initialize();

        skybox = new Skybox();
        skybox->setProjection(projection);

        createEvent("Loop");

        ImGui::CreateContext();
        imguiIO = ImGui::GetIO();
    }

    API() {
        API(800, 600, "Engine");
    }

    ~API() {}
};

};

#endif // ENGINE_INCLUDE

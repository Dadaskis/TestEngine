#include <iostream>
#include <random>
#include <chrono>
#include "Engine/API.h"
//#include "IMGUI/imgui.h"

int main() {
    std::cout << 1;
    Engine::API engine(800, 600, "TestEngine");
    std::cout << 2;

    engine.getPhysicsWorld()->setGravity(btVector3(0, -10, 0));

    engine.disableCursor();

    engine.setSkybox(
        engine.loadSkybox(
            "Skybox\\skybox_side.tga",
            "Skybox\\skybox_side.tga",
            "Skybox\\skybox_up.tga",
            "Skybox\\skybox_down.tga",
            "Skybox\\skybox_side.tga",
            "Skybox\\skybox_side.tga"
        )
    );

    Engine::Model* houseModel = engine.loadModel("D:\\C++ Projects\\TestEngine\\Models\\Castle OBJ.obj");

    std::mt19937 generator;
    std::uniform_int_distribution<int> function(-10, 10);
    {
        using Clock = std::chrono::high_resolution_clock;
        Clock::time_point currentTimePoint = Clock::now();
        generator.seed(currentTimePoint.time_since_epoch().count());
    }

    Engine::PDGameObject* house = engine.createPDGameObject();
    house->setModel(houseModel);
    {
        Engine::Physics::Object* object = house->getPhysicsObject();
        object->setStaticCollider(houseModel);
        object->createBody();
        object->setMass(glm::vec4(0.0f));
    }


    Engine::Camera* camera = engine.createCamera();
    engine.setCurrentCamera(camera);
    Engine::Physics::Object cameraObject(engine.getPhysicsWorld());
    {
        btCollisionShape* collision = new btBoxShape(btVector3(0.5, 0.5, 0.5));
        cameraObject.setCollision(collision);
        cameraObject.createBody();
        cameraObject.setMass(glm::vec4(0, 0, 0, 1.0f));
    }

    engine.createSunlikeLight(glm::vec3(1.0, 1.0, 0.3), glm::vec3(0.2), glm::vec3(0, 1, 0));

    camera->setFOV(90.0f);
    camera->setSpeed(10.0f);
    camera->setPosition(glm::vec3(10, 100, 10));
    cameraObject.setPosition(glm::vec3(10, 100, 10));

    house->setPosition({10, 10, 10});

    bool pressed = false;
    int counter = 0;
    int lightCounter = 0;

    engine.setBinding("fly_front", KEY_W, [&]() {
        camera->processKeyboard(Engine::CAMERA_MOVE_FORWARD, engine.getDeltaTime());
        //cameraObject.setVelocity(camera->getFront() * glm::vec3(5));
    });

    engine.setBinding("fly_left", KEY_A, [&]() {
        camera->processKeyboard(Engine::CAMERA_MOVE_LEFT, engine.getDeltaTime());
    });

    engine.setBinding("fly_back", KEY_S, [&]() {
        camera->processKeyboard(Engine::CAMERA_MOVE_BACKWARD, engine.getDeltaTime());
    });

    engine.setBinding("fly_right", KEY_D, [&]() {
        camera->processKeyboard(Engine::CAMERA_MOVE_RIGHT, engine.getDeltaTime());
    });

    engine.setBinding("fly_up", KEY_SPACE, [&]() {
        camera->processKeyboard(Engine::CAMERA_MOVE_UP, engine.getDeltaTime());
    });

    engine.setBinding("fly_down", KEY_LEFT_CONTROL, [&]() {
        camera->processKeyboard(Engine::CAMERA_MOVE_DOWN, engine.getDeltaTime());
    });

    Engine::Light* light1 = engine.createLight(glm::vec3(1.0, 0, 0), glm::vec3(0.5), camera->getPosition(), 0.2);

    engine.setBinding("setLightPosition", MOUSE_BUTTON_LEFT, [&](){
        light1->setPosition(camera->getPosition());
    });

    engine.setBinding("return", KEY_R, [&](){
        //firstPlatform->setPosition(camera->getPosition() + glm::vec3(1));
        //secondPlatform->setPosition(camera->getPosition() + glm::vec3(-1));
    });

    Engine::Framebuffer lightBuffer;
    lightBuffer.initialize(engine.getWidth(), engine.getHeight());
    Engine::Framebuffer diffuse;
    diffuse.initialize(engine.getWidth(), engine.getHeight());

    Engine::Shader diffuseShader;
    diffuseShader.setVertex("Shaders\\Diffuse.vs");
    diffuseShader.setFragment("Shaders\\Diffuse.fs");
    diffuseShader.compile();

    Engine::Shader lightShader;
    lightShader.setVertex("Shaders\\LightBuffer.vs");
    lightShader.setFragment("Shaders\\LightBuffer.fs");
    lightShader.compile();

    Engine::Shader screenShader;
    screenShader.setVertex("Shaders\\ScreenSpace.vs");
    screenShader.setFragment("Shaders\\ScreenSpace.fs");
    screenShader.compile();

    lightShader.use();
    lightShader.setMat4("projection", *engine.getProjection());

    diffuseShader.use();
    diffuseShader.setMat4("projection", *engine.getProjection());

    Engine::Texture lightTexture(lightBuffer.get2DSampler());
    Engine::Texture diffuseTexture(diffuse.get2DSampler());

    Engine::Plate* screenSpace = engine.createPlate();

    lightTexture.bind(0);
    diffuseTexture.bind(1);
    screenShader.use();
    screenShader.setInt("lightBuffer", lightTexture.getActiveUnit());
    screenShader.setInt("diffuseBuffer", diffuseTexture.getActiveUnit());

    auto modelDrawing = [&](Engine::Shader* shader) {
        house->draw(shader);
    };

    //unsigned char* fontPixels = NULL;
  //  int fontSizeX, fontSizeY;
//    imguiIO.Fonts->GetTexDataAsRGBA32(&fontPixels, &fontSizeX, &fontSizeY);

    while(engine.isOpen()) {
        engine.updateLightsInfo(&lightShader);
        engine.updatePhysics();
//        imguiIO.DeltaTime = engine.getDeltaTime();
        //camera->setPosition(cameraObject.getPosition());

        //firstPlatform->update(engine.getDeltaTime());
        //secondPlatform->update(engine.getDeltaTime());
        //terrain->update(engine.getDeltaTime());


        glm::vec2 cursorPosition = engine.getCursorPosition();
        camera->processMouseMovement(cursorPosition.x, cursorPosition.y);

        /*diffuse.bind();
        Engine::Framebuffer::clearColorBuffer();
        Engine::Framebuffer::clearDepthBuffer();
        engine.drawSkybox();
        diffuseShader.use();
        diffuseShader.setMat4("view", camera->getViewMatrix());
        modelDrawing(&diffuseShader);*/

        lightBuffer.bind();
        Engine::Framebuffer::clearColorBuffer();
        Engine::Framebuffer::clearDepthBuffer();
        lightShader.use();
        lightShader.setMat4("view", camera->getViewMatrix());
        modelDrawing(&lightShader);

        engine.disableDepthTest();
        lightTexture.bind(0);
        diffuseTexture.bind(1);
        Engine::Framebuffer::bindDefault();
        Engine::Framebuffer::clearColorBuffer();
        screenSpace->draw(&screenShader);
        engine.enableDepthTest();

        engine.draw();
    }
    return 0;
}
















#include "Engine/API.h"

int main() {
    Engine::API engine(800, 600, "TestEngine");

    Engine::Camera camera;
    Engine::Plate plate;

    Engine::GL::Shader shader;
    shader.setVertex("Shaders/Simple.vs");
    shader.setFragment("Shaders/Simple.fs");
    shader.compile();
    
    engine.setBinding("flyUp", {KEY_W}, [&](){
        camera.processKeyboard(Engine::CAMERA_MOVE_FORWARD, engine.getDeltaTime());
    });

    engine.setBinding("flyLeft", {KEY_A}, [&](){
        camera.processKeyboard(Engine::CAMERA_MOVE_LEFT, engine.getDeltaTime());
    });

    engine.setBinding("flyBack", {KEY_S}, [&](){
        camera.processKeyboard(Engine::CAMERA_MOVE_BACKWARD, engine.getDeltaTime());
    });

    engine.setBinding("flyRight", {KEY_D}, [&](){
        camera.processKeyboard(Engine::CAMERA_MOVE_RIGHT, engine.getDeltaTime());
    });

    Engine::Framebuffer::setClearColor({0.1, 0.3, 0.5, 0.8});
    while(engine.isOpen()){
        Engine::Framebuffer::clearColorBuffer();
        Engine::Framebuffer::clearDepthBuffer();
        shader.use();
        for(auto drawable : Engine::Global::getDrawables()){
            std::cout << "Draw call ... \n";
            drawable->draw();
        }
        engine.draw();
    }

    return 0;
}

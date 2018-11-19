
#include "Engine/API.h"

class PlateWrap;

namespace Global{

namespace Private{

std::vector<PlateWrap*> plateWraps;
};

const std::vector<PlateWrap*>& getPlateWraps(){
    return Private::plateWraps;
}

};

class PlateWrap : public Engine::Plate {
   private:
    glm::mat4 modelSpace;
    std::vector<PlateWrap*>::iterator iterator;
   public:
    PlateWrap(const glm::mat4& modelSpace) { 
        this->modelSpace = modelSpace; 
        Global::Private::plateWraps.push_back(this);
        iterator = Global::Private::plateWraps.end();
    }
    const glm::mat4& getModelSpace() { return modelSpace; }

    ~PlateWrap(){
        Global::Private::plateWraps.erase(iterator);
    }
};

int main() {
    Engine::API engine(800, 600, "TestEngine");
    engine.disableCursor();

    Engine::Camera camera;
    camera.setSpeed(10.0f);

    Engine::GL::Shader shader;
    shader.setVertex("Shaders\\Simple.vs");
    shader.setFragment("Shaders\\Simple.fs");
    shader.compile();

    engine.setBinding("flyUp", {KEY_W}, [&]() {
        camera.processKeyboard(Engine::CAMERA_MOVE_FORWARD,
                               engine.getDeltaTime());
    });

    engine.setBinding("flyLeft", {KEY_A}, [&]() {
        camera.processKeyboard(Engine::CAMERA_MOVE_LEFT, engine.getDeltaTime());
    });

    engine.setBinding("flyBack", {KEY_S}, [&]() {
        camera.processKeyboard(Engine::CAMERA_MOVE_BACKWARD,
                               engine.getDeltaTime());
    });

    engine.setBinding("flyRight", {KEY_D}, [&]() {
        camera.processKeyboard(Engine::CAMERA_MOVE_RIGHT,
                               engine.getDeltaTime());
    });

    glm::mat4 projection =
        glm::perspective(glm::radians(90.0f),
                         engine.getWidth() / engine.getHeight(), 0.1f, 1000.0f);

    engine.setBinding("createPlate", {KEY_LEFT_ALT, MOUSE_BUTTON_LEFT}, [&]() {
        glm::mat4 model(glm::mat3(-camera.getViewMatrix()));
        model[3][0] = camera.getPosition().x + camera.getFront().x;
        model[3][1] = camera.getPosition().y + camera.getFront().y;
        model[3][2] = camera.getPosition().z + camera.getFront().z;
        new PlateWrap(model);
    });

    Engine::GL::Framebuffer::setClearColor({0.1, 0.3, 0.5, 1.0});

    int projectionUniformID = shader.getUniformPosition("projection"),
        viewUniformID = shader.getUniformPosition("view"),
        modelUniformID = shader.getUniformPosition("model");

    Engine::Model model("house[0].exterior.obj");

    while (engine.isOpen()) {
        Engine::GL::Framebuffer::clearColorBuffer();
        Engine::GL::Framebuffer::clearDepthBuffer();
        glm::vec2 cursorPos = engine.getCursorPosition();
        camera.processMouseMovement(cursorPos.x, cursorPos.y);
        for(auto& mesh : model.getMeshes()){
            shader.use();
            shader.setMat4(viewUniformID, camera.getViewMatrix());
            shader.setMat4(modelUniformID, glm::mat4(1.0));
            shader.setMat4(projectionUniformID, projection);
            mesh.bind();
            mesh.bindTextures(shader);
            mesh.draw();
            mesh.unbind();
        }
        engine.draw();
    }

    return 0;
}

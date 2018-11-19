#ifndef ENGINE_WINDOW_INCLUDE
#define ENGINE_WINDOW_INCLUDE

namespace Engine {

namespace WindowCallbacks {

void errorCallback(int error, const char* description) {
    // std::cout << error << "\n" << description << "\n";
}

void frameSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

};  // namespace WindowCallbacks

class Window {
   private:
    GLFWwindow* windowFrame;

    struct DeltaType {
        float time;

        float lastTime;

        void calculate(float currentTime) {
            time = currentTime - lastTime;
            lastTime = currentTime;
        }
    } Delta;

    struct BindingInfo {
        std::vector<int> keys;
        std::function<void(void)> function;
    };

    bool keyCheck(int keyCode, int status) {
        if (glfwGetKey(windowFrame, (int)keyCode) == status) {
            return true;
        }
        return false;
    }

    bool mouseCheck(int mouseCode, int status) {
        if (glfwGetMouseButton(windowFrame, (int)mouseCode) == status) {
            return true;
        }
        return false;
    }

    std::unordered_map<std::string, BindingInfo> bindings;

    void runBinding(const BindingInfo& info) {
        bool isPressed = false;
        for(auto key : info.keys){
            if (!(isKeyPressed(key) || isMousePressed(key))) {
                isPressed = true;
            }
        }
        if(!isPressed){
            info.function();
        }
    }

   public:
    void createWindow(unsigned int width,
                      unsigned int height,
                      const std::string& title) {
        if (!glfwInit()) {
            std::cerr << "GLFW initialize error.\n";
            exit(-1);
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwSetErrorCallback(WindowCallbacks::errorCallback);
        
        windowFrame =
            glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!windowFrame) {
            std::cerr << windowFrame << "\n"
                      << title << " window creating error.\n";
            exit(-1);
        }

        glfwMakeContextCurrent(windowFrame);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << title << " window OpenGL context creating failed\n";
            exit(-1);
        }

        glfwShowWindow(windowFrame);
    }

    Window() {
        createWindow(640, 480, "TestEngine");
    }

    Window(unsigned int width, unsigned int height, const std::string& title) {
        createWindow(width, height, title);
    }

    void swapBuffers() {
        Delta.calculate(glfwGetTime());
        glfwSwapBuffers(windowFrame);
        glfwPollEvents();
    }

    bool isOpen() { return !glfwWindowShouldClose(windowFrame); }

    bool isKeyPressed(int keyCode) { return keyCheck(keyCode, GLFW_PRESS); }

    bool isKeyReleased(int keyCode) { return keyCheck(keyCode, GLFW_RELEASE); }

    bool isMousePressed(int mouseCode) {
        return mouseCheck(mouseCode, GLFW_PRESS);
    }

    bool isMouseReleased(int mouseCode) {
        return mouseCheck(mouseCode, GLFW_RELEASE);
    }

    void enableCursor() {
        glfwSetInputMode(windowFrame, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    void disableCursor() {
        glfwSetInputMode(windowFrame, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    glm::vec2 getCursorPosition() {
        double X, Y;
        glfwGetCursorPos(windowFrame, &X, &Y);
        return glm::vec2(X, Y);
    }

    float getDeltaTime() { return Delta.time; }

    float getTime() { return (float)glfwGetTime(); }

    float getWidth() {
        int *width, *dummy;
        width = new int;
        dummy = new int;
        glfwGetWindowSize(windowFrame, width, dummy);
        delete dummy;
        return *width;
    }

    float getHeight() {
        int *height, *dummy;
        height = new int;
        dummy = new int;
        glfwGetWindowSize(windowFrame, dummy, height);
        delete dummy;
        return *height;
    }

    void setBinding(const std::string& bindName,
                    std::vector<int> keys,
                    std::function<void(void)> function) {
        BindingInfo bind;
        bind.keys = keys;
        bind.function = function;
        bindings[bindName] = bind;
    }

    void runBindings() {
        for (auto& binding : bindings) {
            runBinding(binding.second);
        }
    }
};

};  // namespace Engine

#endif  // ENGINE_WINDOW_INCLUDE

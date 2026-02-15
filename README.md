# TestEngine - A Lightweight 3D Game Engine

A C++/OpenGL game engine with Bullet Physics integration, featuring a modular architecture and real-time 3D rendering capabilities.

## Overview

TestEngine is a simple 3D game engine built from scratch, demonstrating modern OpenGL rendering techniques with physics simulation. The engine provides a foundation for 3D applications with a clean API design and resource management system.

## Features

- **OpenGL Rendering Pipeline**
  - Custom shader system (vertex/fragment shaders)
  - Advanced lighting with support for multiple light types (default and sun-like)
  - Framebuffer support for post-processing
  - Model loading via Assimp with texture support
  - Plates as primitive shapes

- **Physics Integration**
  - Bullet Physics engine integration
  - Collision detection and dynamics
  - Support for various collision shapes (triangle mesh, box, sphere)
  - Physics world management

- **Resource Management**
  - Automatic resource tracking with global arrays
  - Texture loading and management (2D and cubemap)
  - Model mesh processing
  - Camera system with movement controls

- **Input Handling**
  - Keyboard and mouse input binding system
  - Configurable key mappings
  - Real-time input callbacks

- **Cross-Platform Build System**
  - Windows batch build script
  - Linux shell build script
  - Configurable library paths

## Project Structure

```
TestEngine/
├── Engine/                 # Core engine implementation
│   ├── Core/               # Engine subsystems
│   │   ├── Interfaces/     # Abstract interfaces (Drawable, Updateable)
│   │   ├── OpenGL/         # OpenGL wrappers (Buffers, Shaders, Textures)
│   │   ├── Physics/        # Bullet Physics integration
│   │   ├── Resources/      # Game resources (Camera, Model, Primitives)
│   │   ├── Utilities/      # Helper functions and macros
│   │   └── Window/         # Window management
│   ├── Shaders/            # Engine shader files
│   └── API.h               # Main engine API entry point
├── Shaders/                 # Application shaders
├── Tools/                   # Third-party libraries (Windows)
├── LinuxTools/              # Third-party libraries (Linux)
├── Builder.bat              # Windows build script
├── Builder.sh               # Linux build script
└── Main.cpp                 # Example application
```

## Technologies Used

- **C++17** - Core language
- **OpenGL 3.3** - Graphics rendering
- **GLFW** - Window management and input
- **GLAD** - OpenGL extension loading
- **GLM** - Mathematics library
- **Assimp** - 3D model loading
- **Bullet Physics** - Physics simulation
- **stb_image** - Texture loading

## Building the Project

### Windows
```
Builder.bat
```

### Linux
```bash
chmod +x Builder.sh
./Builder.sh
```

## Example Usage

```cpp
#include "Engine/API.h"

int main() {
    // Initialize engine
    Engine::API engine(800, 600, "TestEngine");
    engine.disableCursor();

    // Create camera
    Engine::Camera camera;
    camera.setSpeed(10.0f);

    // Load and compile shaders
    Engine::GL::Shader shader;
    shader.setVertex("Shaders/Simple.vs");
    shader.setFragment("Shaders/Simple.fs");
    shader.compile();

    // Set up input bindings
    engine.setBinding("flyUp", {KEY_W}, [&]() {
        camera.processKeyboard(Engine::CAMERA_MOVE_FORWARD, 
                               engine.getDeltaTime());
    });

    // Load 3D model
    Engine::Model model("house[0].exterior.obj");

    // Main render loop
    while (engine.isOpen()) {
        // Clear buffers
        Engine::GL::Framebuffer::clearColorBuffer();
        Engine::GL::Framebuffer::clearDepthBuffer();

        // Update camera
        glm::vec2 cursorPos = engine.getCursorPosition();
        camera.processMouseMovement(cursorPos.x, cursorPos.y);

        // Render model
        for(auto& mesh : model.getMeshes()){
            shader.use();
            shader.setMat4(viewUniformID, camera.getViewMatrix());
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
```

## License

MIT License, happiness to everyone.

---

*Note: This is a development/test engine - perfect for learning OpenGL and game engine architecture!*

#ifndef ENGINE_PRIMITIVES_PLATE_INCLUDE
#define ENGINE_PRIMITIVES_PLATE_INCLUDE

#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

namespace Global{

namespace Plate{

GL::Buffer base;

void initialize(){
    base.create(3);
    
    float pos[] = {
        -1.0, -1.0, 0,
        1.0, -1.0, 0,
        -1.0, 1.0, 0,
        1.0, 1.0, 0
    };

    float normals[] = {
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0
    };

    float texCoords[] = {
        0.0, 1.0,
        1.0, 1.0,
        0.0, 0.0,
        1.0, 0.0
    };

    uint32 sequence[] = {
        0, 2, 3,
        0, 1, 3
    };

    base.setData<float>(0, &pos[0], 3 * 4);
    base.setData<float>(1, &normals[0], 3 * 4);
    base.setData<float>(2, &texCoords[0], 2 * 4);
    base.setSequence(&sequence[0], 3 * 2);
    
    base.enableAttribute(0);
    base.setAttribute<glm::vec3, float>(0, 3 * 4);

    base.enableAttribute(1);
    base.setAttribute<glm::vec3, float>(1, 3 * 4);

    base.enableAttribute(2);
    base.setAttribute<glm::vec2, float>(2, 2 * 4);

    base.unbind();
}

};

};

class Plate{
private:
    GL::Buffer* vertexData;
public:
    Plate(){
        vertexData = &Global::Plate::base;
    }

    void draw(const GL::Shader& shader) const {
        shader.use();
        vertexData->bind();
        glDrawElements(GL_TRIANGLES, 3 * 2, GL_UNSIGNED_INT, NULL);
        vertexData->unbind();
    }
};

};

#endif // ENGINE_PRIMITIVES_PLATE_INCLUDE

#ifndef ENGINE_PRIMITIVES_PLATE_INCLUDE
#define ENGINE_PRIMITIVES_PLATE_INCLUDE

#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

struct AllPlatesBase {
    unsigned int VAO = 0, VBO = 0;
    float verteces[24] = {
        -1.0f,  1.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
        1.0f, -1.0f,  1.0f, 0.0f,

        -1.0f,  1.0f,  0.0f, 1.0f,
        1.0f, -1.0f,  1.0f, 0.0f,
        1.0f,  1.0f,  1.0f, 1.0f
    };

    void initialize() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), &verteces[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)NULL);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glBindVertexArray(0);
    }

    void draw(Shader* shader) {
        glBindVertexArray(VAO);
        shader->use();
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
};

class Plate {
private:
    glm::mat4 modelSpace = glm::mat4(1.0);
    static AllPlatesBase plateBase;
public:
    Plate() {}
    Plate(const Plate& plate) {}
    void operator=(const Plate& plate) {}

    void setPosition(float X, float Y, float Z) {
        modelSpace = glm::translate(glm::mat4(1.0), glm::vec3(X, Y, Z));
    }

    void setPosition(const glm::vec3& position) {
        modelSpace = glm::translate(glm::mat4(1.0), position);
    }

    void setPositionCommutative(float X, float Y, float Z) {
        modelSpace = glm::translate(modelSpace, glm::vec3(X, Y, Z));
    }

    void setPositionCommutative(const glm::vec3& position) {
        modelSpace = glm::translate(modelSpace, position);
    }

    void setRotation(float X, float Y, float Z, float angle) {
        modelSpace = glm::rotate(glm::mat4(1.0), angle, glm::vec3(X, Y, Z));
    }

    void setRotation(const glm::vec3& rotateVector, float angle) {
        modelSpace = glm::rotate(glm::mat4(1.0), angle, rotateVector);
    }

    void setRotationCommutative(float X, float Y, float Z, float angle) {
        modelSpace = glm::rotate(modelSpace, angle, glm::vec3(X, Y, Z));
    }

    void setRotationCommutative(const glm::vec3& rotateVector, float angle) {
        modelSpace = glm::rotate(modelSpace, angle, rotateVector);
    }

    glm::mat4* getModelSpace() {
        return &modelSpace;
    }

    void draw(Shader* shader) {
        plateBase.draw(shader);
    }

    static AllPlatesBase* getPlateBase() {
        return &plateBase;
    }
};

AllPlatesBase Plate::plateBase = AllPlatesBase();

};

#endif // ENGINE_PRIMITIVES_PLATE_INCLUDE

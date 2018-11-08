#ifndef ENGINE_CAMERA_INCLUDE
#define ENGINE_CAMERA_INCLUDE

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace Engine {

enum CameraMove : int {
    CAMERA_MOVE_FORWARD,
    CAMERA_MOVE_BACKWARD,
    CAMERA_MOVE_LEFT,
    CAMERA_MOVE_RIGHT,
    CAMERA_MOVE_UP,
    CAMERA_MOVE_DOWN
};

class Camera {
private:
    static constexpr float YAW         = -90.0f;
    static constexpr float PITCH       =  0.0f;
    static constexpr float SPEED       =  2.5f;
    static constexpr float SENSITIVITY =  0.1f;
    static constexpr float MAX_FOV     =  360.0f;

    float MovementSpeed;
    float MouseSensitivity;
    float fov;

    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    float yaw;
    float pitch;

    float lastMouseX = 0, lastMouseY = 0;

    void updateCameraVectors() {
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->front = glm::normalize(front);

        right = glm::normalize(glm::cross(this->front, worldUp));
        up    = glm::normalize(glm::cross(right, this->front));
    }

public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
           glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
           float yaw = YAW,
           float pitch = PITCH)
        : front(glm::vec3(0.0f, 0.0f, -1.0f))
        , MovementSpeed(SPEED)
        , MouseSensitivity(SENSITIVITY)
        , fov(MAX_FOV) {
        this->position = position;
        worldUp = up;
        this->yaw = yaw;
        this->pitch = pitch;
        updateCameraVectors();
    }

    Camera(float posX, float posY, float posZ,
           float upX, float upY, float upZ,
           float yaw, float pitch)
        : front(glm::vec3(0.0f, 0.0f, -1.0f))
        , MovementSpeed(SPEED)
        , MouseSensitivity(SENSITIVITY)
        , fov(MAX_FOV) {
        position = glm::vec3(posX, posY, posZ);
        worldUp = glm::vec3(upX, upY, upZ);
        this->yaw = yaw;
        this->pitch = pitch;
        updateCameraVectors();
    }

    glm::mat4 getViewMatrix() {
        return glm::lookAt(position, position + front, up);
    }

    void processKeyboard(int direction, float deltaTime) {
        float velocity = MovementSpeed * deltaTime;
        if (direction == CAMERA_MOVE_FORWARD)
            position += front * velocity;
        if (direction == CAMERA_MOVE_BACKWARD)
            position -= front * velocity;
        if (direction == CAMERA_MOVE_LEFT)
            position -= right * velocity;
        if (direction == CAMERA_MOVE_RIGHT)
            position += right * velocity;
        if (direction == CAMERA_MOVE_UP)
            position += up * velocity;
        if (direction == CAMERA_MOVE_DOWN)
            position -= up * velocity;
    }

    void processMouseMovement(float X, float Y, GLboolean constrainPitch = true) {
        float xoffset, yoffset;

        xoffset = X - lastMouseX;
        yoffset = lastMouseY - Y;

        lastMouseX = X;
        lastMouseY = Y;

        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        yaw   += xoffset;
        pitch += yoffset;

        if (constrainPitch) {
            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;
        }

        updateCameraVectors();
    }

    void setFOV(float fov) {
        this->fov = fov;
    }

    void processMouseScroll(float yoffset) {
        if (fov >= 1.0f && fov <= MAX_FOV)
            fov -= yoffset;
        if (fov <= 1.0f)
            fov = 1.0f;
        if (fov >= MAX_FOV)
            fov = MAX_FOV;
    }

    void setSpeed(float speed) {
        MovementSpeed = speed;
    }

    float getSpeed() {
        return MovementSpeed;
    }

    void setSensitivity(float sense) {
        MouseSensitivity = sense;
    }

    float getSensitivity() {
        return MouseSensitivity;
    }

    void setPosition(const glm::vec3& position) {
        this->position = position;
    }

    glm::vec3 getPosition() {
        return position;
    }

    void setFront(const glm::vec3& front) {
        this->front = front;
    }

    glm::vec3 getFront() {
        return front;
    }
};

};

#endif // ENGINE_CAMERA_INCLUDE

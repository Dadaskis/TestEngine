#ifndef ENGINE_PRIMITIVES_PLATE_INCLUDE
#define ENGINE_PRIMITIVES_PLATE_INCLUDE

namespace Engine {

class Plate;

namespace Global {

namespace Plate {

GL::ModelBuffer* base;

void initialize() {
    base = new GL::ModelBuffer();
    base->bind();

    std::vector<glm::vec3> pos = {glm::vec3(-1.0, -1.0, 0), glm::vec3(1.0, -1.0, 0), glm::vec3(-1.0, 1.0, 0), glm::vec3(1.0, 1.0, 0)};

    std::vector<glm::vec3> normals(4, glm::vec3(0));

    std::vector<glm::vec2> texCoords = {glm::vec2(0.0, 1.0), glm::vec2(1.0, 1.0), glm::vec2(0.0, 0.0), glm::vec2(1.0, 0.0)};

    std::vector<unsigned int> indices = {0, 2, 3, 0, 1, 3};

    base->setPositions(pos);
    base->setNormals(normals);
    base->setTexCoords(texCoords);
    base->setIndices(indices);

    base->unbind();
}

};  // namespace Plate

};  // namespace Global

class Plate : public Interfaces::Drawable{
   private:
    GL::Buffer* vertexData;
   public:
    Plate() {
        vertexData = Global::Plate::base; 
    }

    void draw() {
        vertexData->bind();
        vertexData->draw();
        vertexData->unbind();
    }
};

};  // namespace Engine

#endif  // ENGINE_PRIMITIVES_PLATE_INCLUDE

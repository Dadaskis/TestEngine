#ifndef ENGINE_PRIMITIVES_PLATE_INCLUDE
#define ENGINE_PRIMITIVES_PLATE_INCLUDE

namespace Engine {

class Plate;

namespace Global {

namespace Private{

std::vector<Plate*> plates;

};

const std::vector<Plate*>& getPlates(){
    return Private::plates;
}

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

class Plate {
   private:
    GL::Buffer* vertexData;
    std::vector<Plate*>::iterator iterator;
   public:
    Plate() {
        Global::Private::plates.push_back(this);
        iterator = Global::Private::plates.end();
        vertexData = Global::Plate::base; 
    }

    void draw(const GL::Shader& shader) const {
        shader.use();
        vertexData->bind();
        glDrawElements(GL_TRIANGLES, 3 * 2, GL_UNSIGNED_INT, NULL);
        vertexData->unbind();
    }
};

};  // namespace Engine

#endif  // ENGINE_PRIMITIVES_PLATE_INCLUDE

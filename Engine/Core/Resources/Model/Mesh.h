#ifndef ENGINE_MESH_INCLUDE
#define ENGINE_MESH_INCLUDE

namespace Engine {

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

class Mesh : public GL::ModelBuffer {
   private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<GL::Texture> textures;

    void setupMesh() {
        bind();

        std::vector<glm::vec3> positions;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec2> texCoords;
        std::vector<glm::vec3> tangents;

        for(auto& vertex : vertices){
            positions.push_back(vertex.position);
            normals.push_back(vertex.normal);
            texCoords.push_back(vertex.texCoords);
            tangents.push_back(vertex.tangent);
        }

        setPositions(positions);
        setNormals(normals);
        setTexCoords(texCoords);
        setTangents(tangents);
        setIndices(indices);

        unbind();
    }

   public:
    Mesh(const std::vector<Vertex>& vertices,
         const std::vector<unsigned int>& indices,
         const std::vector<GL::Texture>& textures) {
        this->vertices = vertices;
        this->indices = indices;
        this->textures = textures;

        setupMesh();
    }

    void bindTextures(const GL::Shader& shader) const{
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr = 1;
        unsigned int heightNr = 1;
        for (unsigned int i = 0; i < textures.size(); i++) {
            textures[i].bind(i);
            // retrieve texture number (the N in diffuse_textureN)
            std::string number;
            std::string name = textures[i].getType();
            if (name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if (name == "texture_specular")
                number = std::to_string(specularNr++);
            else if (name == "texture_normal")
                number = std::to_string(normalNr++);
            else if (name == "texture_height")
                number = std::to_string(heightNr++);
            shader.setInt((name + number), i);
        }
    }

    const std::vector<Vertex>& getVertices() const { return vertices; }

    const std::vector<unsigned int>& getIndices() const { return indices; }
};

};  // namespace Engine
#endif

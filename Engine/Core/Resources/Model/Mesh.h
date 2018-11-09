#ifndef ENGINE_MESH_INCLUDE
#define ENGINE_MESH_INCLUDE

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../OpenGL/Shader/Shader.h"
#include "../Texture/Texture.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

namespace Engine {

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

class Mesh {
private:
    GL::ModelBuffer vertexData;
    std::vector<Vertex> vertices;
    std::vector<uint32> indices;
    std::vector<GL::Texture> textures;

    void setupMesh() {
        vertexData.create();

        vertexData.bind();
        
        vertexData.setData<Vertex>(0, &vertices[0], vertices.size());

        vertexData.setSequence(&indices[0], indices.size()); 
        
        vertexData.enableAttribute(0);
        vertexData.setAttribute<float, Vertex>(0, 3, offsetof(Vertex, position));
        
        vertexData.enableAttribute(1);
        vertexData.setAttribute<float, Vertex>(1, 3, offsetof(Vertex, normal));
        
        vertexData.enableAttribute(2);
        vertexData.setAttribute<float, Vertex>(2, 2, offsetof(Vertex, texCoords));
        
        vertexData.enableAttribute(3);
        vertexData.setAttribute<float, Vertex>(3, 3, offsetof(Vertex, tangent));

        vertexData.unbind();
    }

public:
    Mesh(const std::vector<Vertex>& vertices,
         const std::vector<uint32>& indices,
         const std::vector<GL::Texture>& textures) {
        this->vertices = vertices;
        this->indices = indices;
        this->textures = textures;

        setupMesh();
    }

    // render the mesh
    void draw(const GL::Shader& shader) {
        uint32 diffuseNr  = 1;
        uint32 specularNr = 1;
        uint32 normalNr   = 1;
        uint32 heightNr   = 1;
        for(uint32 i = 0; i < textures.size(); i++) {
            textures[i].setActiveUnit(i);
            // retrieve texture number (the N in diffuse_textureN)
            std::string number;
            std::string name = textures[i].getType();
            if(name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if(name == "texture_specular")
                number = std::to_string(specularNr++);
            else if(name == "texture_normal")
                number = std::to_string(normalNr++);
            else if(name == "texture_height")
                number = std::to_string(heightNr++);

            shader.setInt((name + number), i);
            
            textures[i].bind();
        }

        vertexData.bind();
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }
    
    const std::vector<Vertex>& getVertices() const{
        return vertices;
    }

    const std::vector<uint32>& getIndices() const{
        return indices;
    }

    void release(){
        vertexData.release();
    }
};

};
#endif

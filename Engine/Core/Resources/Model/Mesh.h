#ifndef ENGINE_MESH_INCLUDE
#define ENGINE_MESH_INCLUDE

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Shader/Shader.h"
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
    GL::Buffer vertexData;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

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
         const std::vector<unsigned int>& indices,
         const std::vector<Texture>& textures) {
        this->vertices = vertices;
        this->indices = indices;
        this->textures = textures;

        setupMesh();
    }

    // render the mesh
    void draw(Shader* shader) {
        unsigned int diffuseNr  = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr   = 1;
        unsigned int heightNr   = 1;
        for(unsigned int i = 0; i < textures.size(); i++) {
            textures[i].setActiveUnit(i);
            // retrieve texture number (the N in diffuse_textureN)
            std::string number;
            std::string name = textures[i].getType();
            if(name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if(name == "texture_specular")
                number = std::to_string(specularNr++); // transfer unsigned int to stream
            else if(name == "texture_normal")
                number = std::to_string(normalNr++); // transfer unsigned int to stream
            else if(name == "texture_height")
                number = std::to_string(heightNr++); // transfer unsigned int to stream

            // now set the sampler to the correct texture unit
            shader->setInt((name + number), i);
            // and finally bind the texture
            textures[i].bind();
        }

        // draw mesh
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }
    
    std::vector<Vertex>& getVertices(){
        return vertices;
    }

    void release(){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
};

};
#endif

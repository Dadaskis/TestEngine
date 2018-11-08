#ifndef ENGINE_MODEL_INCLUDE
#define ENGINE_MODEL_INCLUDE

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "../../OpenGL/Shader/Shader.h"
#include "../Texture/Texture.h"
#include "../Texture/TextureLoader.h"
#include "../../Utilities/Utilities.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

namespace Engine {

class Model;

namespace Global{

namespace Private{

std::vector<Model*> models;

};

const std::vector<Model*> getModels() const{
    return Private::models;
}

};

class Model {
private:
    btDiscreteDynamicsWorld* physicsWorld;
    btTriangleMesh* collider;

    void loadModel(const std::string& path) {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) { // if is Not Zero
            std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << "\n";
            return;
        }

        processNode(scene->mRootNode, scene);
    }


    void processNode(aiNode *node, const aiScene *scene) {
        for(uint32 i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

            meshes.push_back(processMesh(mesh, scene));
        }
        for(uint32 i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

    Mesh processMesh(aiMesh *mesh, const aiScene *scene) {
        std::vector<Vertex> vertices;
        std::vector<uint32> indices;
        std::vector<Texture> textures;
        std::vector<float> vertexVectors;

        for(uint32 i = 0; i < mesh->mNumVertices; i++) {
            Vertex vertex;
            glm::vec3 vector;

            vector.x = mesh->mVertices[i].x;
            vector.y = mesh->mVertices[i].y;
            vector.z = mesh->mVertices[i].z;
            vertex.Position = vector;

            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.Normal = vector;

            if(mesh->mTextureCoords[0]) {
                glm::vec2 vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.TexCoords = vec;
            } else
                vertex.TexCoords = glm::vec2(0.0f, 0.0f);

            vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            vertex.Tangent = vector;

            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            vertex.Bitangent = vector;
            vertices.push_back(vertex);
        }

        for(uint32 i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];

            for(uint32 j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        // diffuse: texture_diffuseN
        // specular: texture_specularN
        // normal: texture_normalN

        std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

        std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
        textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

        std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
        textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

        return Mesh(vertices, indices, textures);
    }

    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, const std::string& typeName) {
        std::vector<Texture> meshTextures;
        for(uint32 i = 0; i < mat->GetTextureCount(type); i++) {
            aiString str;
            mat->GetTexture(type, i, &str);

            bool skip = false;
            for(uint32 j = 0; j < textures_loaded.size(); j++) {
                if(std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0) {
                    textures.push_back(textures_loaded[j]);
                    skip = true;
                    break;
                }
            }
            if(!skip) {
                Texture texture(TextureUtilities::loadTexture(str.C_Str()));
                texture.setType(typeName);
                texture.setPath(str.C_Str());
                meshTextures.push_back(texture);
                textures.push_back(texture);
            }
        }
        return meshTextures;
    }
public:
    mutable std::vector<Texture> textures;
    mutable std::vector<Mesh> meshes;
    mutable std::string directory;
    mutable bool gammaCorrection;

    Model(btDiscreteDynamicsWorld* physicsWorld, const std::string& path, bool gamma = false)
        : gammaCorrection(gamma) {
        this->physicsWorld = physicsWorld;
        loadModel(path);

        collider = new btTriangleMesh();
        for(int meshIndex = 0; meshIndex < meshes.size(); meshIndex++){
            Mesh mesh = meshes[meshIndex];
            for(int indicesIndex = 0; indicesIndex < mesh.indices.size() - 2; indicesIndex += 3){
                collider->addTriangle(
                    Utilities::convertGlmVec3(mesh.vertices[mesh.indices[indicesIndex    ]].Position),
                    Utilities::convertGlmVec3(mesh.vertices[mesh.indices[indicesIndex + 1]].Position),
                    Utilities::convertGlmVec3(mesh.vertices[mesh.indices[indicesIndex + 2]].Position),
                    true
                );
            }

        }
    }

    std::vector<Texture>& getTextures(){
        return this->textures;
    }

    void setTextures(const std::vector<Texture>& textures){
        this->textures = textures;
    }

    std::vector<Mesh>& getMeshes(){
        return this->meshes;
    }

    std::string& getDirectory(){
        return this->directory;
    }

    void setDirectory(const std::string& directory){
        this->directory = directory;
    }

    bool& getGammaCorrection(){
        return this->gammaCorrection;
    }

    void setGammaCorrection(const bool& gammaCorrection){
        this->gammaCorrection = gammaCorrection;
    }

    btGImpactMeshShape* getCollision(){
        btGImpactMeshShape* collision = new btGImpactMeshShape(collider);
        collision->updateBound();

        return collision;
    }

    btBvhTriangleMeshShape* getStaticCollision(){
        btBvhTriangleMeshShape* collision = new btBvhTriangleMeshShape(collider, false);

        return collision;
    }

    void draw(GL::Shader* shader) {
        shader->use();
        for(auto mesh = meshes.begin(); mesh != meshes.end(); mesh++) {
            mesh->draw(shader);
        }
    }
};

};
#endif

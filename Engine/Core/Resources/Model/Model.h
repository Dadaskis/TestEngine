#ifndef ENGINE_MODEL_INCLUDE
#define ENGINE_MODEL_INCLUDE

#include "Mesh.h"

namespace Engine {

GLOBAL_RESOURCE_ARRAY_DEFINE(Model, models, GetModels);

class Model {
   private:
    btTriangleMesh* collider;
    std::vector<GL::Texture> textures;
    std::vector<Mesh> meshes;
    std::string directory;

    void loadModel(const std::string& path) {
        Assimp::Importer importer;
        const aiScene* scene =
            importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs |
                                        aiProcess_CalcTangentSpace);
        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
            !scene->mRootNode) {  // if is Not Zero
            std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString()
                      << "\n";
            return;
        }

        processNode(scene->mRootNode, scene);
    }

    void processNode(aiNode* node, const aiScene* scene) {
        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

            meshes.push_back(processMesh(mesh, scene));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

    Mesh processMesh(aiMesh* mesh, const aiScene* scene) {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<GL::Texture> textures;
        std::vector<float> vertexVectors;

        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
            Vertex vertex;
            glm::vec3 vector;

            vector.x = mesh->mVertices[i].x;
            vector.y = mesh->mVertices[i].y;
            vector.z = mesh->mVertices[i].z;
            vertex.position = vector;

            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.normal = vector;

            if (mesh->mTextureCoords[0]) {
                glm::vec2 vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.texCoords = vec;
            } else
                vertex.texCoords = glm::vec2(0.0f, 0.0f);

            vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            vertex.tangent = vector;

            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            vertex.bitangent = vector;
            vertices.push_back(vertex);
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];

            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        // diffuse: texture_diffuseN
        // specular: texture_specularN
        // normal: texture_normalN

        std::vector<GL::Texture> diffuseMaps = loadMaterialTextures(
            material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<GL::Texture> specularMaps = loadMaterialTextures(
            material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(),
                        specularMaps.end());

        std::vector<GL::Texture> normalMaps = loadMaterialTextures(
            material, aiTextureType_NORMALS, "texture_normal");
        textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

        std::vector<GL::Texture> heightMaps = loadMaterialTextures(
            material, aiTextureType_HEIGHT, "texture_height");
        textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

        return Mesh(vertices, indices, textures);
    }

    std::vector<GL::Texture> loadMaterialTextures(aiMaterial* mat,
                                                  aiTextureType type,
                                                  const std::string& typeName) {
        std::vector<GL::Texture> meshTextures;
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
            aiString str;
            mat->GetTexture(type, i, &str);

            bool skip = false;
            for (unsigned int j = 0; j < textures.size(); j++) {
                if (std::strcmp(textures[j].getPath().c_str(), str.C_Str()) ==
                    0) {
                    textures.push_back(textures[j]);
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                GL::Texture texture(str.C_Str());
                texture.setType(typeName);
                meshTextures.push_back(texture);
                textures.push_back(texture);
            }
        }
        return meshTextures;
    }

   public:
    Model(const std::string& path) {
        GLOBAL_RESOURCE_ARRAY_REGISTER(models);
        loadModel(path);

        collider = new btTriangleMesh();
        for (int meshIndex = 0; meshIndex < meshes.size(); meshIndex++) {
            Mesh& mesh = meshes[meshIndex];
            const std::vector<Vertex>& vertices = mesh.getVertices();
            const std::vector<unsigned int>& indices = mesh.getIndices();
            for (int indicesIndex = 0; indicesIndex < indices.size() - 2;
                 indicesIndex += 3) {
                collider->addTriangle(
                    Utilities::Vector::toPhysics(
                        vertices.at(indices.at(indicesIndex)).position),
                    Utilities::Vector::toPhysics(
                        vertices.at(indices.at(indicesIndex + 1)).position),
                    Utilities::Vector::toPhysics(
                        vertices.at(indices.at(indicesIndex + 2)).position),
                    true);
            }
        }
    }

    const std::vector<GL::Texture>& getTextures() const {
        return this->textures;
    }

    void setTextures(const std::vector<GL::Texture>& textures) {
        this->textures = textures;
    }

    const std::vector<Mesh>& getMeshes() const { return this->meshes; }

    const std::string& getDirectory() const { return this->directory; }

    btGImpactMeshShape* getCollision() {
        btGImpactMeshShape* collision = new btGImpactMeshShape(collider);
        collision->updateBound();

        return collision;
    }

    btBvhTriangleMeshShape* getStaticCollision() {
        btBvhTriangleMeshShape* collision =
            new btBvhTriangleMeshShape(collider, false);

        return collision;
    }

    ~Model(){
        GLOBAL_RESOURCE_ARRAY_REMOVE(models);
    }
};

};  // namespace Engine
#endif

#ifndef ENGINE_OPENGL_MODELBUFFER_INCLUDE
#define ENGINE_OPENGL_MODELBUFFER_INCLUDE

#define ENGINE_OPENGL_MODELBUFFER_DATA_HANDLER(vecType, vecDimension, index, array){\
    setData<const vecType>(index, array.data(), array.size());\
    enableAttribute(index);\
    setAttribute<vecType, float>(index, vecDimension);\
}


namespace Engine{

namespace GL{

class ModelBuffer : public Buffer{
private:

public:
    ModelBuffer(){}

    void setVertexPositions(const std::vector<glm::vec3>& data){
        ENGINE_OPENGL_MODELBUFFER_DATA_HANDLER(glm::vec3, 3, 0, data);
    }

    void setNormals(const std::vector<glm::vec3>& data){
        ENGINE_OPENGL_MODELBUFFER_DATA_HANDLER(glm::vec3, 3, 1, data);
    }

    void setTexCoords(const std::vector<glm::vec2>& data){
        ENGINE_OPENGL_MODELBUFFER_DATA_HANDLER(glm::vec2, 2, 2, data);
    }

    void setTangents(const std::vector<glm::vec3>& data){
        ENGINE_OPENGL_MODELBUFFER_DATA_HANDLER(glm::vec3, 3, 3, data);
    }

    void setIndices(const std::vector<uint32>& indices){
        setSequence(&indices[0], indices.size());
    }
};

};

};

#endif
#ifndef ENGINE_CORE_OPENGL_BUFFER_INCLUDE
#define ENGINE_CORE_OPENGL_BUFFER_INCLUDE

#include <vector>

namespace Engine{

namespace GL{

class Buffer{
private:
    unsigned int VAO, EBO;
    std::vector<unsigned int> VBOs;
public:
    Buffer(){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &EBO);
    }

    void bind(){
        glBindVertexArray(VAO);
    }

    void unbind(){
        glBindVertexArray(NULL);
    }

    void create(int count = 1){
        while(count--){
            VBOs.push_back(0);
            glGenBuffers(1, &VBOs.back());
        }
    }

    template<class Type>
    void setData(int index, Type* data, int count){
        glBindBuffer(GL_ARRAY_BUFFER, VBOs.at(index));
        glBufferData(GL_ARRAY_BUFFER, sizeof(Type) * count, data, GL_STATIC_DRAW);
    }

    void setSequence(unsigned int* sequence, int count){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, sequence, GL_STATIC_DRAW);
    }

    void enableAttribute(int index){
        glEnableVertexAttribArray(index);
    }

    void disableAttribute(int index){
        glDisableVertexAttribArray(index);
    }

    template<class TypeOnGPU, class Type>
    void setAttribute(int index, int size = 1, int pointer = 0){
        glVertexAttribPointer(index, size, TypeOnGPU, false, sizeof(Type), (void*)pointer);
    }

    void release(){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &EBO);
        glDeleteBuffers(VBOs.size(), &VBOs[0]);
    }
};

};

};

#endif
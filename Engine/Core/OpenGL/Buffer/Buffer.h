#ifndef ENGINE_CORE_OPENGL_BUFFER_INCLUDE
#define ENGINE_CORE_OPENGL_BUFFER_INCLUDE

namespace Engine {

namespace GL {

class Buffer : public ::Engine::Interfaces::Drawable{
   private:
    unsigned int VAO, EBO;
    std::vector<unsigned int> VBOs;
    int sequenceCount = 0;

   public:
    Buffer() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &EBO);
    }

    void bind() const { glBindVertexArray(VAO); }

    void unbind() const { glBindVertexArray(NULL); }

    void create(int count = 1) {
        while (count--) {
            VBOs.push_back(0);
            glGenBuffers(1, &VBOs.back());
        }
    }

    template <class Type>
    void setData(int index, const Type* data, int count) {
        glBindBuffer(GL_ARRAY_BUFFER, VBOs.at(index));
        glBufferData(GL_ARRAY_BUFFER, sizeof(Type) * count, data,
                     GL_STATIC_DRAW);
    }

    void setSequence(const unsigned int* sequence, int count) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count,
                     sequence, GL_STATIC_DRAW);
        this->sequenceCount = count;
    }

    void enableAttribute(int index) { glEnableVertexAttribArray(index); }

    void disableAttribute(int index) { glDisableVertexAttribArray(index); }

    template <const int TypeOnGPU, class Type>
    void setAttribute(unsigned int index,
                      unsigned int size = 1,
                      int pointer = 0) {
        glVertexAttribPointer(index, size, TypeOnGPU, false, sizeof(Type),
                              (void*)pointer);
    }

    void draw(){
        glDrawElements(GL_TRIANGLES, sequenceCount, GL_UNSIGNED_INT, NULL);
    }
    
    void release() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &EBO);
        glDeleteBuffers(VBOs.size(), &VBOs[0]);
    }
};

};  // namespace GL

};  // namespace Engine

#endif
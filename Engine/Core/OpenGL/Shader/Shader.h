#ifndef ENGINE_OPENGL_SHADER_INCLUDE
#define ENGINE_OPENGL_SHADER_INCLUDE

namespace Engine {

namespace GL {

class Shader {
   private:
    std::string vertexCode, fragmentCode, extendVertexCode = "",
                                          extendFragmentCode = "";
    unsigned int ID;

    void checkCompileErrors(GLuint shader, const std::string& type) const {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout
                    << "ERROR::Shader_COMPILATION_ERROR of type: " << type
                    << "\n"
                    << infoLog
                    << "\n -- "
                       "--------------------------------------------------- -- "
                    << std::endl;
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout
                    << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                    << infoLog
                    << "\n -- "
                       "--------------------------------------------------- -- "
                    << std::endl;
            }
        }
    }

   public:
    Shader() {}
    Shader(const Shader& shader) { this->ID = shader.ID; }
    void operator=(const Shader& shader) { this->ID = shader.ID; }

    Shader(const std::string& vertexShaderPath,
           const std::string& fragmentShaderPath) {
        setVertex(vertexShaderPath);
        setFragment(fragmentShaderPath);
        compile();
    }

    void setVertex(const std::string& path) {
        vertexCode = Utilities::File::readWholeFile(path);
    }

    void setFragment(const std::string& path) {
        fragmentCode = Utilities::File::readWholeFile(path);
    }

    void vertexExtend(const std::string& path) {
        extendVertexCode = Utilities::File::readWholeFile(path);
    }

    void fragmentExtend(const std::string& path) {
        extendFragmentCode = Utilities::File::readWholeFile(path);
    }

    void compile() {
        vertexCode = extendVertexCode + vertexCode;
        fragmentCode = extendFragmentCode + fragmentCode;
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        vertexCode = "";
        fragmentCode = "";
    }

    void use() const { glUseProgram(ID); }

    unsigned int getUniformPosition(const std::string& varName) const {
        return glGetUniformLocation(ID, varName.c_str());
    }

    void setBool(const std::string& name, bool value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void setBool(unsigned int uniformLocation, bool value) const {
        glUniform1i(uniformLocation, (int)value);
    }

    void setInt(const std::string& name, int value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setInt(unsigned int uniformLocation, int value) const {
        glUniform1i(uniformLocation, (int)value);
    }

    void setFloat(const std::string& name, float value) const {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setFloat(unsigned int uniformLocation, float value) const {
        glUniform1f(uniformLocation, value);
    }

    void setVec2(const std::string& name, const glm::vec2& value) const {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec2(unsigned int uniformLocation, const glm::vec2& value) const {
        glUniform2fv(uniformLocation, 1, &value[0]);
    }

    void setVec2(const std::string& name, float x, float y) const {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }

    void setVec2(unsigned int uniformLocation, float x, float y) const {
        glUniform2f(uniformLocation, x, y);
    }

    void setVec3(const std::string& name, const glm::vec3& value) const {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec3(unsigned int uniformLocation, const glm::vec3& value) const {
        glUniform3fv(uniformLocation, 1, &value[0]);
    }

    void setVec3(const std::string& name, float x, float y, float z) const {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }

    void setVec3(unsigned int uniformLocation,
                 float x,
                 float y,
                 float z) const {
        glUniform3f(uniformLocation, x, y, z);
    }

    void setVec4(const std::string& name, const glm::vec4& value) const {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    void setVec4(const std::string& name,
                 float x,
                 float y,
                 float z,
                 float w) const {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }

    void setVec4(unsigned int uniformLocation, const glm::vec4& value) const {
        glUniform4fv(uniformLocation, 1, &value[0]);
    }

    void setVec4(unsigned int uniformLocation,
                 float x,
                 float y,
                 float z,
                 float w) const {
        glUniform4f(uniformLocation, x, y, z, w);
    }

    void setMat2(const std::string& name, const glm::mat2& mat) const {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,
                           &mat[0][0]);
    }

    void setMat2(unsigned int uniformLocation, const glm::mat2& mat) const {
        glUniformMatrix2fv(uniformLocation, 1, GL_FALSE, &mat[0][0]);
    }

    void setMat3(const std::string& name, const glm::mat3& mat) const {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,
                           &mat[0][0]);
    }

    void setMat3(unsigned int uniformLocation, const glm::mat3& mat) const {
        glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, &mat[0][0]);
    }

    void setMat4(const std::string& name, const glm::mat4& mat) const {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,
                           &mat[0][0]);
    }

    void setMat4(unsigned int uniformLocation, const glm::mat4& mat) const {
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &mat[0][0]);
    }
};

};  // namespace GL

};  // namespace Engine

#endif

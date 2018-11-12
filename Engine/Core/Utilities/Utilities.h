#ifndef ENGINE_UTILITIES_INCLUDE
#define ENGINE_UTILITIES_INCLUDE

namespace Engine {

namespace Utilities {

std::vector<std::string> splitString(const std::string& string,
                                     const std::string& splitter) {
    std::regex regex(splitter);
    std::sregex_token_iterator first{string.begin(), string.end(), regex, -1},
        last;
    return {first, last};
}

template <class Type>
std::string numberToString(Type number) {
    std::ostringstream stringStream;
    stringStream << number;
    return stringStream.str();
}

template <class Type>
Type stringToNumber(const std::string& string) {
    Type number = 0;
    if (!(std::istringstream(string) >> number)) {
        return 0;
    }
    return number;
}

namespace File {

std::string readWholeFile(const std::string& path) {
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        file.open(path);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        return stream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}

};  // namespace File

namespace Vector {

btVector3 toPhysics(glm::vec3& vec) {
    return btVector3(vec.x, vec.y, vec.z);
}

const btVector3 toPhysics(const glm::vec3& vec) {
    return btVector3(vec.x, vec.y, vec.z);
}

glm::vec3 toLinearMath(btVector3& vec) {
    return glm::vec3(vec.x(), vec.y(), vec.z());
}

const glm::vec3 toLinearMath(const btVector3& vec) {
    return glm::vec3(vec.x(), vec.y(), vec.z());
}

};  // namespace Vector

};  // namespace Utilities

};  // namespace Engine

#endif  // ENGINE_UTILITIES_INCLUDE

#ifndef ENGINE_UTILITIES_INCLUDE
#define ENGINE_UTILITIES_INCLUDE

#include <regex>
#include <vector>
#include <fstream>

namespace Engine {

namespace Utilities {
std::vector<std::string> splitString(const std::string& string, const std::string& splitter) {
    std::regex regex(splitter);
    std::sregex_token_iterator first{string.begin(), string.end(), regex, -1}, last;
    return {first, last};
}

template<class Type>
std::string numberToString(Type number) {
    std::ostringstream stringStream;
    stringStream << number;
    return stringStream.str();
}

template<class Type>
Type stringToNumber(const std::string& string) {
    Type number = 0;
    if(!(std::istringstream(string) >> number)) {
        return 0;
    }
    return number;
}

std::string readWholeFile(const std::string& path) {
    std::ifstream file;
    file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
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

btVector3 convertGlmVec3(const glm::vec3& vector){
    return btVector3(vector.x, vector.y, vector.z);
}

glm::vec3 convertBtVector3(const btVector3& btVector){
    return glm::vec3(btVector.x(), btVector.y(), btVector.z());
}

};

};

#endif // ENGINE_UTILITIES_INCLUDE

#version 330 core

uniform sampler2D lightBuffer;
uniform sampler2D diffuseBuffer;

in vec2 fragTexCoords;

out vec4 outColor;

void main(){
    outColor = texture(lightBuffer, fragTexCoords) + texture(diffuseBuffer, fragTexCoords);
}

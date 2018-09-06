#version 330 core

layout(location = 0) in vec2 inVertexPosition;
layout(location = 2) in vec2 inTexCoords;

uniform vec2 translation;

out vec2 fragTexCoords;

void main(){
    gl_Position = vec4(inVertexPosition.x + translation.x, inVertexPosition.y + translation.y, 0, 1);
    fragTexCoords = inTexCoords;
}

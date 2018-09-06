#version 330 core

layout(location = 0) in vec2 inVertexPosition;
layout(location = 2) in vec2 inTexCoords;

uniform float offset;

out vec2 fragTexCoords;

void main(){
    gl_Position = vec4(inVertexPosition.x, inVertexPosition.y, offset, 1);
    fragTexCoords = inTexCoords;
}

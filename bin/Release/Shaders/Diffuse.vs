#version 330 core

layout(location = 0) in vec4 inVertexPosition;
layout(location = 2) in vec2 inTexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec2 fragTexCoords;

void main(){
    gl_Position = projection * view * model * inVertexPosition;
    fragTexCoords = inTexCoords;
}

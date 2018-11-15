#version 330 core

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

layout(location = 0) in vec4 inVertexPosition;
layout(location = 1) in vec3 inNormal;

out vec3 fragVertexPosition;
out vec3 fragNormal;

void main(){
    gl_Position = projection * view * model * inVertexPosition;
    fragNormal = mat3(model) * inNormal;
    fragVertexPosition = (model * inVertexPosition).xyz;
}

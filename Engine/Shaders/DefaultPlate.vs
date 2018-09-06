#version 330 core

layout(location = 0) in vec2 inVertexPosition;
layout(location = 1) in vec2 inTexCoords;

uniform mat4 projection;
uniform mat4 viewSpace;
uniform mat4 modelSpace;
uniform float offset;

out vec3 fragVertexPosition;

void main(){
    gl_Position = projection * viewSpace * modelSpace * vec4(inVertexPosition.x, inVertexPosition.y, offset, 1);
    fragVertexPosition = (modelSpace * vec4(inVertexPosition.x, inVertexPosition.y, offset, 1)).xyz;
}

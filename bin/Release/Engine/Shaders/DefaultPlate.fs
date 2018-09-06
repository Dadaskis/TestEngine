#version 330 core

in vec3 fragVertexPosition;

out vec4 outColor;

void main(){
    outColor = vec4(fragVertexPosition, 1);
}

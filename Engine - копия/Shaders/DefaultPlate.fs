#version 330 core

uniform sampler2D texture_diffuse1;

in vec3 fragVertexPosition;

out vec4 outColor;

void main(){
    outColor = vec4(fragVertexPosition, 1.0);
}

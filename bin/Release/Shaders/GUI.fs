#version 330 core

uniform sampler2D diffuse_texture1;

in vec2 fragTexCoords;

out vec4 outColor;

void main(){
    outColor = texture(diffuse_texture1, fragTexCoords);
}

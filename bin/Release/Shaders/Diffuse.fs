#version 330 core

uniform sampler2D texture_diffuse1;

in vec2 fragTexCoords;

out vec4 outColor;

void main(){
    outColor = texture(texture_diffuse1, fragTexCoords);
}

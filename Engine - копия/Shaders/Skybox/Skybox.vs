#version 330 core

uniform mat4 projection;
uniform mat4 view;

layout(location = 0) in vec4 inVertexPosition;

out vec3 fragTexCoords;

void main(){
    fragTexCoords = inVertexPosition.xyz;
    vec4 position = projection * view * inVertexPosition;
    gl_Position = position.xyww;
}

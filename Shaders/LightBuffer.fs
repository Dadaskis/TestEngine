#version 330 core

#define LIGHT_TYPE_DEFAULT 0
#define LIGHT_TYPE_SUNLIKE 1

struct Light{
    vec3 position,
         color,
         intensive,
         direction;
    int type,
        power;
};

struct Material{
    float shineModifier;
};

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform Material material;
uniform int lightsCount;
uniform Light lights[290];

in vec3 fragVertexPosition;
in vec3 fragNormal;

out vec4 resultColor;


vec3 calculateLighting(in Light light, in vec3 normal){
    vec3 eyeCoords = -view[3].xyz;
    vec3 s;
    if(light.type == LIGHT_TYPE_DEFAULT){
        s = normalize(fragVertexPosition - light.position);
    }else if(light.type == LIGHT_TYPE_SUNLIKE){
        s = normalize(-light.direction);
    }
    vec3 v = normalize(fragVertexPosition - eyeCoords);
    vec3 r = reflect(-s, normal);
    float sDotN = max(dot(-s, normal), 0.0);

    float atten = 1.0;
    if(light.type == LIGHT_TYPE_DEFAULT){
        float divider = length(fragVertexPosition - light.position) / 20;
        atten /= (divider * divider);
    }
    vec3 lightInt = light.color * light.intensive * atten;

    vec3 diffuse = lightInt * sDotN;
    vec3 specular = vec3(0.0);
    if(sDotN > 0.0){
        specular = lightInt * pow(max(dot(r, -v), 0.0), 1);
    }

    vec3 result = diffuse + specular;

    return result;
}

vec3 calculateAllLighting(const int count, in vec3 normal){
    vec3 colorModifier = vec3(0);
    vec3 ambient = vec3(0.1);
    for(int index = 0; index < count; index++){
        colorModifier += calculateLighting(lights[index], normal);
    }
    colorModifier += ambient;
    if(colorModifier.r > 1.0){
        colorModifier.r = 1.0;
    }
    if(colorModifier.g > 1.0){
        colorModifier.g = 1.0;
    }
    if(colorModifier.b > 1.0){
        colorModifier.b = 1.0;
    }
    return colorModifier;
}

void main(){
    vec3 lightsResult = calculateAllLighting(lightsCount, fragNormal);
    resultColor = vec4(lightsResult, 1.0);
}


//
// Roberto Cano (http://www.robertocano.es)
//
#version 330 core

uniform struct Light {
    vec3 position;
    vec3 intensities;
} light;

uniform mat4 view;

in vec3 fragment_vertex;
in vec3 fragment_color;
in vec3 fragment_normal;

out vec3 color;

void main()
{
    mat4 model = mat4(1.0);
    vec3 lightPos = vec3(2, 2, 2);
    vec3 lightColor = vec3(1, 1, 1);

    /* Calculate the normal matrix (excluding scaling and translation, centerd in origin) */
    //mat3 normalMatrix = transpose(inverse(mat3(model)));

    /* And now calculate the final normal */
    //vec3 normal = normalize(fragment_normal * normalMatrix);
    vec3 normal = fragment_normal;

    /* Calculate fragment position in world coordinates */
    vec3 fragmentPos = vec3(model*vec4(fragment_vertex, 1));

    /* Light vector to fragment */
    vec3 surfaceToLight = lightPos - fragmentPos;

    /* Calculate the brightness */
    float brightness = dot(normal, surfaceToLight) / (length(normal) * length(surfaceToLight));
    brightness = clamp(brightness, 0, 1);

    /* Calculate the final color based on the base color of the object (or texture color),
       the brightness and the color of the light */
    vec3 baseColor = vec3(1);

    /* 1.0 / (1.0 + a*dist + b*dist*dist)) */
    float dist = distance(fragment_vertex, lightPos);
    float att = 1.0 / (1.0 + 0*dist + 0.1*dist*dist);

    color = vec3(brightness * lightColor * baseColor.rgb * att);
}

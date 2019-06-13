#version 330 core

in VS_OUT {
  vec2 TexCoord;
  vec3 Color;
} fs_in;

out vec4 FragColor;

uniform sampler2D texture;

void main() {
  FragColor = texture(texture, fs_in.TexCoord) * vec4(fs_in.Color, 1.0f);
}
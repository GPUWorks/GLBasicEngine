#version 330 core
out vec3 color;

uniform float tcol;

void main(){
  color = vec3(0.5,0.8, tcol);
}
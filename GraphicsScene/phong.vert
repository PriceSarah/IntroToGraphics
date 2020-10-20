//classic phone vertex shader
#version 410

layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec4 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 4) in vec4 aColor;

uniform mat4 ProjectionViewModel;

void main() {
	gl_Position = ProjectionViewModel * position;
}
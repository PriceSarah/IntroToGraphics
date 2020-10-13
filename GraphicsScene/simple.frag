// A simple flat color shader
#version 410

in vec4 vertexColor;

out vec4 FragColor;

void main() {
	float red, green, blue;
	if (vertexColor.x > 0.5)
			red = 1.0f;
	else
			red = 0.0;
	if (vertexColor.y > 0.5)
			green = 1.0f;
	else
			green = 0.0;
	if (vertexColor.z > 0.5)
			blue = 1.0f;
	else
			blue = 0.0;

	FragColor = vec4(vertexColor.x, vertexColor.y, vertexColor.z, vertexColor.w);
}
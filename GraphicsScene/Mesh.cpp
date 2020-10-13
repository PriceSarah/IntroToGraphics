#include "Mesh.h"
#include <gl_core_4_4.h>

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);
}

void Mesh::initializeQuad()
{
	//Check that the mesh is not already initialized
	assert(m_vao == 0);

	//Generate buffers
	glGenBuffers(1, &m_vbo);
	glGenVertexArrays(1, &m_vao);

	//Bind buffers
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	//Define 6 vertices for 2 triangles
	Vertex vertices[6];
	//Triangle A
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1 };
	//Triangle B
	vertices[3].position = { -0.5f, 0.0f, -0.5f, 1 };
	vertices[4].position = { 0.5f, 0.0f, 0.5f, 1 };
	vertices[5].position = { 0.5f, 0.0f, -0.5f, 1 };
	//Triangle A
	vertices[0].color = { 0.2f, 0.8f, 0.8f, 1 };//Blue
	vertices[1].color = { 0.8f, 0.2f, 0.8f, 1 };//Magenta
	vertices[2].color = { 0.2f, 0.8f, 0.8f, 1 };//Cyan
	//Triangle B
	vertices[3].color = { 0.2f, 0.8f, 0.8f, 1 };//Cyan
	vertices[4].color = { 0.8f, 0.2f, 0.8f, 1 };//Magenta
	vertices[5].color = { 0.8f, 0.2f, 0.2f, 1 };//Red

	//Fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,
		6 * sizeof(Vertex),
		vertices,
		GL_STATIC_DRAW
	);

	//Enable first element as position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		0
	);
	//Enable second element as color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(GLvoid*)(8 * sizeof(float))
	);

	//Unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Quad has two trianges
	m_triCount = 2;
}

void Mesh::draw()
{
	glBindVertexArray(m_vao);
	//Using indices or just vertices
	if (m_ibo != 0)
		glDrawElements(
			GL_TRIANGLES,
			3 * m_triCount,
			GL_UNSIGNED_INT, 0
		);
	else
		glDrawArrays(
			GL_TRIANGLES,
			0,
			3 * m_triCount
		);
}
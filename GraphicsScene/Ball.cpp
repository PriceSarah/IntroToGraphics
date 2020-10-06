#include "Ball.h"
#include <Gizmos.h>
#include <glm/gtx/transform.hpp>

Ball::Ball()
{
	m_color = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
	m_radius = 1.0f;
}

Ball::Ball(glm::vec4 color, float radius)
{
	m_color = color;
	m_radius = radius;
}

bool Ball::draw()
{
	//build a transform matrix
	glm::mat4 transform = glm::translate(m_position) * glm::toMat4(m_rotation);
	//draw the transform
	aie::Gizmos::addTransform(transform, m_radius * 2.0f);
	//draw  the ball
	aie::Gizmos::addSphere(glm::vec3(0), m_radius, 6 * m_radius, 6 * m_radius, m_color, &transform);
	

	return true;
}
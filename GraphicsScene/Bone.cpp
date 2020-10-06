#include "Bone.h"
#include <GLFW/glfw3.h>
#include <Gizmos.h>

Bone::Bone(Actor startFrame, Actor endFrame)
{
	m_startFrame = startFrame;
	m_endFrame = endFrame;
}

bool Bone::update(double deltaTime)
{
	//Find a time-based value in the range of [0,1]
	float s = glm::cos(glfwGetTime()) * 0.5f + 0.5f;

	//standard linear interpolation
	glm::vec3 startPosition(m_startFrame.getPosition());
	glm::vec3 endPosition(m_endFrame.getPosition());
	glm::vec3 p = (1.0f - s) * startPosition + s * endPosition;

	//Quaternion slerp
	glm::quat startRotation(m_startFrame.getRotation());
	glm::quat endRotation(m_endFrame.getRotation());
	glm::quat r = glm::slerp(startRotation, endRotation, s);

	setPosition(p);
	setRotation(r);

	return true;
}

bool Bone::draw()
{
	glm::mat4 transform = getTransform();

	aie::Gizmos::addAABBFilled(glm::vec3(0.0f), glm::vec3(0.5f), glm::vec4(0.8f, 0.8f, 0.6f, 0.8f), &transform);

	return false;
}

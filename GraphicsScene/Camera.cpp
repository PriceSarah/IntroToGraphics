#include "Camera.h"
#include <glm/ext.hpp>

glm::mat4 Camera::getViewMatrix()
{
	//Convert degrees to radians
	float yawRadians = glm::radians(m_yaw);
	float pitchRadians = glm::radians(m_pitch);
	//Calculate the forward vector
	glm::vec3 forward(
		cos(pitchRadians) * cos(yawRadians),
		sin(pitchRadians),
		cos(pitchRadians) * sin(yawRadians));
	//Return the view matrix
	return glm::lookAt(
		m_position, //Our position
		m_position + forward, //Where we are looking
		glm::vec3(0.0f, 1.0f, 0.0f)); //Our up

}

glm::mat4 Camera::getProjectionMatrix(float width, float height)
{
	return glm::perspective(
		glm::pi<float>() * 0.25f,
		width / height,
		0.1f, 1000.0f
	);
}

bool Camera::update(double deltaTime)
{
	//check inout
	if(glfwGetKey(Game::Get))
}

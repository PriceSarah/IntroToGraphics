#pragma once
#include "Actor.h"
#include <glm/glm.hpp>

class Camera : public Actor
{
public:
	Camera() {}
	~Camera() {}

	glm::mat4 getViewMatrix();

	float getYaw() { return m_yaw; }
	void setYaw(float degrees) { m_yaw = degrees; }
	float getPitch() { return m_pitch; }
	void setPitch(float degrees) { m_pitch = degrees; }

	glm::mat4 getProjectionMatrix(float width, float height);

	bool update(double deltaTime) override;

private: 
	float m_yaw = 0.0f; //Theta
	float m_pitch = 0.0f; //Phi
	glm::vec3 m_position;
};


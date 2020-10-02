#pragma once
#include "Game.h"
#include "Actor.h"

class Camera : public Actor
{
public:
	Camera(Game* instance) { m_instance = instance; }
	~Camera() {}

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(float width, float height);

	float getYaw() { return m_yaw; }
	void setYaw(float degrees) { m_yaw = degrees; }
	float getPitch() { return m_pitch; }
	void setPitch(float degrees) { m_pitch = degrees; }
	glm::vec3 getPosition() { return m_position; }
	void setPosition(glm::vec3 position) { m_position = position; }

	bool update(double deltaTime) override;

private:
	Game* m_instance;

	float m_yaw = 0.0f; //theta
	float m_pitch = 0.0f; //phi

	float m_moveSpeed = 1.0f;
	float m_turnSpeed = 0.04f;

	double m_currentMouseX = 0.0;
	double m_currentMouseY = 0.0;
	double m_previousMouseX = 0.0;
	double m_previousMouseY = 0.0;
};
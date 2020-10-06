#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

class Actor
{
public:
	Actor() {}
	~Actor() {}

	virtual bool update(double deltaTime) { return true; }
	virtual bool draw() { return true; }
	glm::vec3 getPosition() { return m_position; }
	void setPosition(glm::vec3 position) { m_position = position; }
	glm::quat getRotation() { return m_rotation; }
	void setRotation(glm::quat rotation) { m_rotation = rotation; }
	glm::mat4 getTransform();

protected:
	glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
	glm::quat m_rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
};
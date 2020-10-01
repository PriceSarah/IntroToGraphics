#pragma once
class Actor
{
public:
	Actor() {}
	~Actor() {}

	virtual bool update(double deltaTime) {}
	virtual bool draw() {}
};


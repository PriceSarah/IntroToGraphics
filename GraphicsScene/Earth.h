#pragma once
#include <Texture.h>
#include "Actor.h"
#include "Mesh.h"
class Earth : public Actor
{
private:
	Mesh m_mesh;
	aie::Texture m_texture;
};


#include "Brick.h"
#include "kage2dutil/physics.h"
#include "app.h"


Brick::Brick()
{
	brickId = 0;
	colliderCode = 0;
}


Brick::~Brick()
{
}

//Function that sets the texture of the sprite
void Brick::SetSprite(sf::String name)
{
	m_sprite = kage::TextureManager::getSprite(name);
}

//Function that sets the position of the sprite aka gameobject
void Brick::SetPosition(sf::Vector2f position)
{
	m_position = position;
}

void Brick::SetColliders(int sizeX, int sizeY, int x, int y)
{
	if (colliderCode == 1)
		kage::Physics::BoxBuilder().pos(kf::Vector2(3, 15)).size(sizeX, sizeY).build(kage::Physics::getDefaultStatic());
	else
		;
}

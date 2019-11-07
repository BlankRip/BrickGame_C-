#include "Brick.h"
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
#include "Brick.h"
#include "kage2dutil/physics.h"
#include "app.h"


Brick::Brick()
{
	m_physicsStyle = GameObject::e_psBox2D;
	 //Make a Box2D body
	m_body = kage::Physics::BodyBuilder()
		.pos(100, 0)
		.userData(this)	// This lets the body know which GameObject owns it
		.build();
	m_body->SetType(b2BodyType::b2_staticBody);

	brickId = 0;
	colliderCode = 0;
}


Brick::~Brick()
{
}

void Brick::update(float dt)
{
	//std::cout << m_position << std::endl;
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

void Brick::SetColliders()
{
	if (colliderCode == 1)
	{
		//int sizeX, int sizeY, int x, int y
		// Make a fixture (collision shape) for the body
		kage::Physics::BoxBuilder()
			.pos(kf::Vector2(m_position.x / 64.0f + ((160.0f / 64.0f) / 2.0f), m_position.y / 64.0f + ((54.0f / 64.0f) / 2.0f)))
			.size(160.0f / 64.0f, 54.0f / 64.0f)
			.build(kage::Physics::getDefaultStatic());
	}
		//kage::Physics::BoxBuilder().pos(kf::Vector2(3, 15)).size(sizeX, sizeY).build(kage::Physics::getDefaultStatic());

}

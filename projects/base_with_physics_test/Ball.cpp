#include "Ball.h"
#include "Game.h"



Ball::Ball()
{
	m_sprite = kage::TextureManager::getSprite("Assets/Ball.png");
	kage::centreOrigin(m_sprite);

	m_physicsStyle = GameObject::e_psBox2D;

	// Make a Box2D body
	m_body = kage::Physics::BodyBuilder()
		.pos(0, 0)
		.userData(this)	// This lets the body know which GameObject owns it
		.build();

	m_body->SetGravityScale(0);
	m_body->SetType(b2BodyType::b2_dynamicBody);


	// Make a fixture (collision shape) for the body
	kage::Physics::CircleBuilder()
		.radius(0.4f)
		.mass(1)
		.build(m_body); // We need to tell the builder which body to attach to

	moveX = 1;
	moveY = 1;
	force = 2;
	flipX = true;
}


Ball::~Ball()
{
}

void Ball::update(float deltaT)
{
	GameObject::update(deltaT);
	m_body->SetLinearVelocity(
		b2Vec2(
			moveX * force,
			moveY * force));

}

void Ball::onCollision(GameObject* obj)
{
	
}

void Ball::onCollision(b2Fixture* fix)
{
	if (m_sprite->getPosition().x < 35 || m_sprite->getPosition().x > 1875)
		moveX = moveX * -1;
	else
		moveY = moveY * -1;
}

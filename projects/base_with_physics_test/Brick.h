#pragma once
#include "kage2dutil/gameobject.h"

class Brick : public kage::GameObject
{
public:
	int brickId;
	int colliderCode;

	Brick();
	~Brick();
	void update(float dt)override;
	void SetSprite(sf::String name);
	void SetPosition(sf::Vector2f position);
	void SetColliders();
};


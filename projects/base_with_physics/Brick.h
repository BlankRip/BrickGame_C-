#pragma once
#include "kage2dutil/gameobject.h"

class Brick : public kage::GameObject
{
public:
	Brick();
	~Brick();
	void SetSprite(sf::String name);
	void SetPosition(sf::Vector2f position);
};


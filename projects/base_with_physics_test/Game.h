#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "BrickManager.h"
#include "Ball.h"

class Game : public App
{
public:
	Game();
	virtual ~Game();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Game&inst();

	BrickManager makeMap;
};

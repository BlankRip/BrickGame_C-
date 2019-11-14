#pragma once

#include "app.h"
#include "kage2dutil/physics.h"
#include "BrickManager.h"
#include "rabbit.h"

class TheEditor : public App
{
public:
	TheEditor();
	virtual ~TheEditor();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static TheEditor &inst();

	BrickManager makeMap;
};

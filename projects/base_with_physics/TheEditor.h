#pragma once

#include "app.h"
#include "Grid.h"
#include "Brick.h"
#include "BrickManager.h"

class TheEditor : public App
{
public:
	TheEditor();
	virtual ~TheEditor();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	static TheEditor &inst();
	Grid mapEditorGrid;
	BrickManager tilesOnMap;
};

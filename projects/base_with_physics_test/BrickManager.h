#pragma once
#include "Brick.h"

class BrickManager
{
private:
	int cellsX;
	int cellsY;
	int cellWidth;
	int cellHight;
	int arraySize;
	int arrayCounter;
	int loadArrayCounter;
	int loadCharTracker;
	int yLineTracker;
	std::string line;
	std::string checkLine;
	bool drawMap;
	bool drawColliders;
	int stringIndex;
	int firstStringIndex;
	bool firstTime;

public:
	Brick* bricks[240];

	BrickManager();
	~BrickManager();
	void CreateTiles();
	void Load();
};


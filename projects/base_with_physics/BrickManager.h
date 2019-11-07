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
	float mousePositionX;
	float mousePositionY;
	float mousePosDivSpritePosX;
	float mousePosDivSpritePosY;
	int xPlacementIndex;
	int yPlacementIndex;
	int arrayReplaceIndexNo;
	int currentBrickId;
	int currentColliderId;
	std::string currentSprite;
	int saveArrayCounter;
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
	bool onGuiWindow;

	BrickManager();
	~BrickManager();
	void CreateTiles();
	void TileClicked(sf::RenderWindow& window);
	void Save();
	void Load();
	void CreateSpriteChangeButtons();
};


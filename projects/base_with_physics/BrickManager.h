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
	std::string currentSprite;

public:
	Brick* bricks[240];
	bool onGuiWindow;

	BrickManager();
	~BrickManager();
	void CreateTiles();
	void TileClicked(sf::RenderWindow& window);
	void CreateSpriteChangeButtons();
};


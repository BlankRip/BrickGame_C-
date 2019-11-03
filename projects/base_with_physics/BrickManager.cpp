#include "BrickManager.h"



BrickManager::BrickManager()
{
	//Things required to place the tiles in the grid lines
	cellsX = 12;
	cellsY = 20;
	cellWidth = 160;
	cellHight = 54;
	arraySize = cellsX * cellsY;
	arrayCounter = 0;

	//Things required to change tiles on click
	mousePositionX = 0;
	mousePositionY = 0;
	mousePosDivSpritePosX = 0;
	mousePosDivSpritePosY = 0;
	xPlacementIndex = 0;
	yPlacementIndex = 0;
	arrayReplaceIndexNo = 0;
	onGuiWindow = false;

	//For changing sprite type
	currentSprite = "Assets/transparentbrick.png";
}


BrickManager::~BrickManager()
{
}

//Function that creates transparent tiles in each cell
void BrickManager::CreateTiles()
{
	//Looping across the y axis
	for (size_t y = 0; y < cellsY; y++)
	{
		//For every unit y axis looping across the x axis
		for (size_t x = 0; x < cellsX; x++)
		{
			bricks[arrayCounter] = kage::World::build<Brick>();
			bricks[arrayCounter]->SetSprite("Assets/transparentbrick.png");
			bricks[arrayCounter]->SetPosition(sf::Vector2f(cellWidth * x, cellHight * y));
			arrayCounter++;
		}
	}
}

//Function that changes the tile when the tilebolock on the grid is clicked
void BrickManager::TileClicked(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!onGuiWindow)
		{
			//Math to find the index of the cell clicked in the array
			mousePositionX = sf::Mouse::getPosition(window).x;
			mousePositionY = sf::Mouse::getPosition(window).y;
			mousePosDivSpritePosX = mousePositionX / cellWidth;
			mousePosDivSpritePosY = mousePositionY / cellHight;
			xPlacementIndex = (int)mousePosDivSpritePosX;
			yPlacementIndex = (int)mousePosDivSpritePosY;
			arrayReplaceIndexNo = xPlacementIndex + (yPlacementIndex * cellsX);

			//Changing the sprite of that cell
			bricks[arrayReplaceIndexNo]->SetSprite(currentSprite);
		}
		
	}
}


void BrickManager::CreateSpriteChangeButtons()
{
	if (ImGui::Button("Remove Tile"))
	{
		currentSprite = "Assets/transparentbrick.png";
	}
	if (ImGui::Button("Black Tile"))
	{
		currentSprite = "Assets/brick.png";
	}
	if (ImGui::Button("Maybe More added"))
	{
		currentSprite = "Assets/brick.png";
	}
	if (ImGui::Button("Reset"))
	{
		for (size_t i = 0; i < arraySize; i++)
		{
			bricks[i]->SetSprite("Assets/transparentbrick.png");
		}
	}
}

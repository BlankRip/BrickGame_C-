#include <fstream>
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
	currentBrickId = 0;
	currentColliderId = 0;

	//For saving the map to a text file
	saveArrayCounter = 0;
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
			bricks[arrayCounter]->brickId = 0;
			bricks[arrayCounter]->colliderCode = 0;
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

			//Changing the tile's brick id and collider Code
			bricks[arrayReplaceIndexNo]->brickId = currentBrickId;
			bricks[arrayReplaceIndexNo]->colliderCode = currentColliderId;
		}
		
	}
}

//Function that saves details of the map
void BrickManager::Save()
{
	std::ofstream saveFile;
	saveFile.open("SaveMap.txt");
	saveFile << "[Map]" << std::endl;
	for (size_t i = 0; i < cellsY; i++)
	{
		for (size_t i = 0; i < cellsX; i++)
		{
			saveFile << bricks[saveArrayCounter]->brickId << ", ";
			saveArrayCounter++;
		}
		saveFile << std::endl;
	}

	saveFile << std::endl;
	saveFile << std::endl;
	saveFile << "[Colliders]" << std::endl;
	saveArrayCounter = 0;
	for (size_t i = 0; i < cellsY; i++)
	{
		for (size_t i = 0; i < cellsX; i++)
		{
			saveFile << bricks[saveArrayCounter]->colliderCode << ", ";
			saveArrayCounter++;
		}
		saveFile << std::endl;
	}
}

//Function that will load the map previously saved
void BrickManager::Load()
{
}

//UI Buttons in the map editor
void BrickManager::CreateSpriteChangeButtons()
{
	if (ImGui::Button("Remove Tile"))
	{
		currentSprite = "Assets/transparentbrick.png";
		currentBrickId = 0;
		currentColliderId = 0;
	}
	if (ImGui::Button("Brick Tile"))
	{
		currentSprite = "Assets/brick.png";
		currentBrickId = 1;
		currentColliderId = 1;
	}
	if (ImGui::Button("Yellow brick tile"))
	{
		currentSprite = "Assets/yellowBrick.png";
		currentBrickId = 2;
		currentColliderId = 1;
	}
	if (ImGui::Button("Green brick tile"))
	{
		currentSprite = "Assets/greenBrick.png";
		currentBrickId = 3;
		currentColliderId = 1;
	}
	if (ImGui::Button("Save"))
	{
		Save();
	}
	if (ImGui::Button("Load"))
	{

	}
	if (ImGui::Button("Reset"))
	{
		for (size_t i = 0; i < arraySize; i++)
		{
			bricks[i]->SetSprite("Assets/transparentbrick.png");
			bricks[arrayCounter]->brickId = 0;
			bricks[arrayCounter]->colliderCode = 0;
		}
	}
}

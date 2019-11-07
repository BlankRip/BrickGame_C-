#include <iostream>
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

	//For loading the map from the text file
	stringIndex = 0;
	firstStringIndex = 0;
	loadCharTracker = 0;
	yLineTracker = 0;
	line = "";
	checkLine = "";
	drawMap = false;
	drawColliders = false;
	firstTime = true;
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
		if (!onGuiWindow && window.hasFocus())
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
	saveArrayCounter = 0;
	//Writing each line brick ids on the grid
	for (size_t i = 0; i < cellsY; i++)
	{
		for (size_t i = 0; i < cellsX; i++)
		{
			if(i == cellsX - 1)
				saveFile << bricks[saveArrayCounter]->brickId;
			else
				saveFile << bricks[saveArrayCounter]->brickId << ", ";
			saveArrayCounter++;
		}
		saveFile << std::endl;
	}

	saveFile << std::endl;
	saveFile << std::endl;
	saveFile << "[Colliders]" << std::endl;
	saveArrayCounter = 0;                             //Resetting saveArrayCounter value
	//Writing each line collider ids on the grid
	for (size_t i = 0; i < cellsY; i++)
	{
		for (size_t i = 0; i < cellsX; i++)
		{
			if (i == cellsX - 1)
				saveFile << bricks[saveArrayCounter]->colliderCode << ",";
			else
				saveFile << bricks[saveArrayCounter]->colliderCode << ", ";
			saveArrayCounter++;
		}
		saveFile << std::endl;
	}
}

//Function that will load the map previously saved
void BrickManager::Load()
{
	std::ifstream loadFile;
	loadFile.open("SaveMap.txt");
	if (loadFile.is_open())
	{
		while (std::getline(loadFile, line))
		{
			//Checking fro the map line
			if (line == "[Map]")
			{
				drawMap = true;
				saveArrayCounter = 0;
				continue;
			}

			//When reading the map in text it will start drawing
			if (drawMap)
			{
				if (yLineTracker < cellsY)
				{
					for (size_t i = 0; loadCharTracker <= line.length(); i++)
					{
						if (firstTime)
						{
							firstStringIndex = line.find(",");
							checkLine = line.substr(0, firstStringIndex);
							firstTime = false;
						}
						else
						{
							stringIndex = line.find(",", firstStringIndex + 1);
							checkLine = line.substr(firstStringIndex + 2, stringIndex - firstStringIndex - 2);
							firstStringIndex = stringIndex;
							loadCharTracker = stringIndex;
						}

						if (checkLine == "0")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[saveArrayCounter]->SetSprite("Assets/transparentbrick.png");
							bricks[saveArrayCounter]->brickId = 0;
							bricks[saveArrayCounter]->colliderCode = 0;
						}
						else if (checkLine == "1")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[saveArrayCounter]->SetSprite("Assets/brick.png");
							bricks[saveArrayCounter]->brickId = 1;
							bricks[saveArrayCounter]->colliderCode = 1;
						}
						else if (checkLine == "2")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[saveArrayCounter]->SetSprite("Assets/yellowBrick.png");
							bricks[saveArrayCounter]->brickId = 2;
							bricks[saveArrayCounter]->colliderCode = 1;
						}
						else if (checkLine == "3")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[saveArrayCounter]->SetSprite("Assets/greenBrick.png");
							bricks[saveArrayCounter]->brickId = 3;
							bricks[saveArrayCounter]->colliderCode = 1;
						}
						saveArrayCounter++;
					}
					firstTime = true;
					yLineTracker++;
					loadCharTracker = 0;
				}
				else
				{
					yLineTracker = 0;
					drawMap = false;
				}

				//To add colliders to the place where ther is a brick
				for (size_t i = 0; i < arraySize; i++)
				{
					if (bricks[i]->colliderCode == 0)
						std::cout << "This has not collider" << std::endl;
					else if (bricks[i]->colliderCode == 1)
						std::cout << "COLLIDER!!!" << std::endl;
				}
			}
		}
	}
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
		Load();
	}
	if (ImGui::Button("Reset"))
	{
		for (size_t i = 0; i < arraySize; i++)
		{
			bricks[i]->SetSprite("Assets/transparentbrick.png");
			bricks[i]->brickId = 0;
			bricks[i]->colliderCode = 0;
		}
	}
}
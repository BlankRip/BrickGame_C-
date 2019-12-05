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

	//For loading the map from the text file
	loadArrayCounter = 0;
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
				loadArrayCounter = 0;
				continue;
			}

			//When reading the map in text it will start drawing
			if (drawMap)
			{
				if (yLineTracker < cellsY)
				{
					for (; loadCharTracker <= line.length();)
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
							bricks[loadArrayCounter]->SetSprite("Assets/transparentbrick.png");
							bricks[loadArrayCounter]->brickId = 0;
							bricks[loadArrayCounter]->colliderCode = 0;
						}
						else if (checkLine == "1")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[loadArrayCounter]->SetSprite("Assets/brick.png");
							bricks[loadArrayCounter]->brickId = 1;
							bricks[loadArrayCounter]->colliderCode = 1;
						}
						else if (checkLine == "2")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[loadArrayCounter]->SetSprite("Assets/yellowBrick.png");
							bricks[loadArrayCounter]->brickId = 2;
							bricks[loadArrayCounter]->colliderCode = 1;
						}
						else if (checkLine == "3")
						{
							//Changing the sprite of that cell and the brick n collider ids
							bricks[loadArrayCounter]->SetSprite("Assets/greenBrick.png");
							bricks[loadArrayCounter]->brickId = 3;
							bricks[loadArrayCounter]->colliderCode = 1;
						}
						loadArrayCounter++;
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

				arrayCounter = 0;
				//To add colliders to the place where ther is a brick
				for (size_t y = 0; y < cellsY; y++)
				{
					//For every unit y axis looping across the x axis
					for (size_t x = 0; x < cellsX; x++)
					{
						bricks[arrayCounter]->SetColliders();
						arrayCounter++;
					}
				}
			}
		}
	}
}

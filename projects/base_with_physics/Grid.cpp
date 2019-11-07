#include "Grid.h"
#include <iostream>


Grid::Grid()
{
	distanceBtwVertical = 160;
	distanceBtwHorizontal = 54;
}


Grid::~Grid()
{
}

//Function that creats the grid ines
void Grid::CreateGrid(sf::RenderWindow& window)
{
	//Creating vertical lines with a distance of 160 pixels between each line
	int vLines = 0;                                                                                  //Int that keeps track of the list index
	for (size_t i = 0; i < window.getSize().x;)
	{
		virticalLines.emplace_back(sf::RectangleShape(sf::Vector2f(3, window.getSize().y)));
		virticalLines[vLines].setPosition(0 + (distanceBtwVertical * vLines), 0);
		virticalLines[vLines].setFillColor(sf::Color::Yellow);
		i = distanceBtwVertical * vLines;                                                            //Setting the position in pixels based on window size
		vLines++;
	}

	//Creating horizontal lines with a distance of 54 pixels between each line
	int hLines = 0;                                                                                  //Int that keeps track of the list index
	for (size_t i = 0; i < window.getSize().y;)
	{
		horizontalLines.emplace_back(sf::RectangleShape(sf::Vector2f(window.getSize().x, 3)));
		horizontalLines[hLines].setPosition(0, 0 + (distanceBtwHorizontal * hLines));
		horizontalLines[hLines].setFillColor(sf::Color::Yellow);
		i = distanceBtwHorizontal * hLines;                                                            //Setting the position in pixels based on window size
		hLines++;
	}
}

//Function that draws the grid
void Grid::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < virticalLines.size(); i++)
	{
		window.draw(virticalLines[i]);
	}
	for (size_t i = 0; i < horizontalLines.size(); i++)
	{
		window.draw(horizontalLines[i]);
	}
}
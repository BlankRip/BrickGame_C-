#include "Grid.h"
#include <iostream>


Grid::Grid()
{
	distanceBtwVertical = 160;
	distanceBtwHorizontal = 54;
	line.setSize(sf::Vector2f(960, 30));
	line.setPosition(483, 650);
}


Grid::~Grid()
{
}

void Grid::CreateGrid(sf::RenderWindow& window)
{
	int vLines = 0;
	for (size_t i = 0; i < window.getSize().x;)
	{
		virticalLines.emplace_back(sf::RectangleShape(sf::Vector2f(3, window.getSize().y)));
		virticalLines[vLines].setPosition(0 + (distanceBtwVertical * vLines), 0);
		virticalLines[vLines].setFillColor(sf::Color::Yellow);
		i = distanceBtwVertical * vLines;
		vLines++;
	}
	int hLines = 0;
	for (size_t i = 0; i < window.getSize().y;)
	{
		horizontalLines.emplace_back(sf::RectangleShape(sf::Vector2f(window.getSize().x, 3)));
		horizontalLines[hLines].setPosition(0, 0 + (distanceBtwHorizontal * hLines));
		horizontalLines[hLines].setFillColor(sf::Color::Yellow);
		i = distanceBtwHorizontal * hLines;
		hLines++;
	}
}

void Grid::Draw(sf::RenderWindow& window)
{
	window.draw(line);
	for (size_t i = 0; i < virticalLines.size(); i++)
	{
		window.draw(virticalLines[i]);
	}
	for (size_t i = 0; i < horizontalLines.size(); i++)
	{
		window.draw(horizontalLines[i]);
	}
}
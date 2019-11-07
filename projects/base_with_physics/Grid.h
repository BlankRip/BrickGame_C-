#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class Grid
{
private:
	std::vector<sf::RectangleShape> virticalLines;
	std::vector<sf::RectangleShape> horizontalLines;
	int distanceBtwVertical;
	int distanceBtwHorizontal;

public:
	Grid();
	~Grid();
	void CreateGrid(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
};
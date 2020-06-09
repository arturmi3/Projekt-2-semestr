#include "Game.h"
#include <iostream>
int main() 
{
	sf::Vector2u res;

	std::cin >> res.x;
	std::cin >> res.y;
	Game game;
	game.setResolution(res);
	game.run();
	return 0;
}
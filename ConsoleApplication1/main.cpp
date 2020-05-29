#include "Game.h"

int main()
{
	//init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//init game engine
	Game game;

	//game loop
	while (game.getWindowIsOpen())
	{
		//Update
		game.update();
		//Render
		game.render();
	}
	//the end
	return 0;
}

#pragma once
#include "GameObject.h"
class Background : public GameObject
{
	

public:
	void adjust(sf::RenderWindow* target);

	Background() : GameObject(nullptr)
	{};
	~Background() = default;

private:

};


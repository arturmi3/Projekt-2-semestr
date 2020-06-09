#pragma once
#include "GameObject.h"
class Background : public GameObject
{
public:
	void adjust(const sf::Vector2f& target);

	Background() : GameObject(nullptr)
	{};
	~Background() = default;

	void update(const float& deltaTime) {};

private:

};


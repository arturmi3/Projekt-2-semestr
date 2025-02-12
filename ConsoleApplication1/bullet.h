#pragma once
#include "GameObject.h"
#include "Game.h"
class bullet : public GameObject
{
public:
	bullet(Game* game, const sf::Vector2f& direction)
		:GameObject(game), m_direction(direction)
	{}

	~bullet() = default;
	

	virtual void update(const float& deltaTime);

	virtual void onColliosion(GameObject* ptr);

protected:
	sf::Vector2f m_direction;
};


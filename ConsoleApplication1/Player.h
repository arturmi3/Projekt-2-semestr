#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(Game* game)
		:GameObject(game), m_bulletTexture(nullptr)
	{
	};

	virtual void update(const float& deltaTime);

	virtual void onColliosion(GameObject* ptr);

	virtual void setBulletTexture(sf::Texture* bullet);
protected:
	sf::Texture* m_bulletTexture;
	
	bool reload = true;

};

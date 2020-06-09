#pragma once
#include "GameObject.h"

class Spawner : public GameObject
{
public:
	Spawner(int mtime, int mxtime, Game* game);

	virtual void update(const float& deltaTime);

	~Spawner() = default;

	virtual void setEnemyTexture(const sf::Texture& tex);

	virtual void setEnemySpeed(const float s)
	{
		speed = s;
	}
protected:
	int minTime;
	int maxTime;
	float resptime;
	sf::Texture enemyTexture;
	float speed;
};


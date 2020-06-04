#pragma once
#include "GameObject.h"
#include "Game.h"
class Enemy : public GameObject
{
public:
	
	Enemy(Game* game, const float speed = 30.f);
	~Enemy()= default;

	virtual void update(const float& deltaTime);

	virtual void setSpeed(const float& speed);

	virtual void onColliosion(GameObject* ptr);

protected:
	float m_speed;
};

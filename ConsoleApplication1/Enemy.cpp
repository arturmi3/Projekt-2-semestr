#include "Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(Game* game, const float speed)
	:GameObject(game), m_speed(speed)
{
	std::random_device mch;
	std::default_random_engine generator(mch());
	std::uniform_int_distribution<int> distribution(static_cast<int>(m_game->getWindowSize().x * 0.1f), static_cast<int>(m_game->getWindowSize().x * 0.8f));
	int positionX = distribution(generator);

	setPosition(sf::Vector2f(static_cast<float>(positionX), 0.f));

}

void Enemy::update(const float& deltaTime)
{
	move(sf::Vector2f(0.f, m_speed *deltaTime));
}

void Enemy::setSpeed(const float& speed)
{
	m_speed = speed;
}

void Enemy::onColliosion(GameObject* ptr)
{
	if (ptr->getTag() == "PlayerBullet")
	{
		remove();
		m_game->clearNoActive();
		//std::cout << "collision" << std::endl;
	}
}
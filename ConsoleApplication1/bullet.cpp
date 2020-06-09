#include "bullet.h"

void bullet::update(const float& deltaTime)
{
	move(sf::Vector2f(m_direction.x * deltaTime, m_direction.y * deltaTime));

	if (m_position.y < 0)
	{
		remove();
		m_game->clearNoActive();
	}

}

void bullet::onColliosion(GameObject* ptr)
{

}

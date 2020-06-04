#include "bullet.h"

void bullet::update(const float& deltaTime)
{
	move(sf::Vector2f(m_direction.x * deltaTime, m_direction.y * deltaTime));
}

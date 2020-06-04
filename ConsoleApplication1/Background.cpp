#include "Background.h"

void Background::adjust(sf::RenderWindow* target)
{
	auto res =static_cast<sf::Vector2f> (m_sprite.getTexture()->getSize());
	auto win =static_cast<sf::Vector2f> (target->getSize());
	m_sprite.setScale(win.x / res.x, win.y / res.y);
}

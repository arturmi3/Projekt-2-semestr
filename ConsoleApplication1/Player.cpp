#include "Player.h"
#include "Game.h"
#include "bullet.h"

void Player::update(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_position.x + m_sprite.getTexture()->getSize().x * m_scale.x < m_game->getWindowSize().x)
		{ 
			move(sf::Vector2f(150 * deltaTime, 0)); 
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_position.x > 0)
		{
			move(sf::Vector2f(-150 * deltaTime, 0));
		}
	}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (reload) 
			{
				auto k = new bullet(m_game, sf::Vector2f(0.f, -300.f));
				k->setPosition(sf::Vector2f(m_position));
				k->setTexture(*m_bulletTexture);

				m_game->addobject(k);
				//remove();
				//m_game->clearNoActive();
				reload = false;
			}
		}
		else
		{
			reload = true;
		}
}

void Player::onColliosion(GameObject* ptr)
{
	if (ptr->getTag() == "Mob")
	{
		//auto mob = static_cast<Mob*>(ptr);
		//mob->damage(30);


		//ptr->remove();
		//m_game->clearNoActive();
	}

}

void Player::setBulletTexture(sf::Texture* bullet)
{
	m_bulletTexture = bullet;
}
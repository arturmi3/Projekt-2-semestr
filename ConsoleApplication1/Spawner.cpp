#include "Spawner.h"
#include "Enemy.h"

#include <random>
Spawner::Spawner(int mtime, int mxtime, Game* game)
	:GameObject(game),minTime(mtime),maxTime(mxtime),resptime(0.f), speed(30.f)
{
	std::random_device mch;
	std::default_random_engine generator(mch());
	std::uniform_int_distribution<int> distribution(minTime, maxTime);
	resptime = distribution(generator);
}



void Spawner::update(const float& deltatime)
{
	resptime -= deltatime;
	if(resptime<0)
	{
		std::random_device mch;
		std::default_random_engine generator(mch());
		std::uniform_int_distribution<int> distribution(minTime,maxTime);
		resptime = distribution(generator);
		
		Enemy* enemy = new Enemy(m_game);
		enemy->setPosition(m_position);
		enemy->setTexture(enemyTexture);
		enemy->setScale(sf::Vector2f(0.2f, 0.2f));
		enemy->rotate(180);
		enemy->setSpeed(speed);
		m_game->addobject(enemy);

	}
}


void Spawner::setEnemyTexture(const sf::Texture& tex)
{
	enemyTexture = tex;
}

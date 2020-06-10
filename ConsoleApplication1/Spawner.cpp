#include "Spawner.h"
#include "Enemy.h"

#include <random>
Spawner::Spawner(int mtime, int mxtime, float minPosition_, float maxPosition_, Game* game)
	:GameObject(game), minTime(mtime), maxTime(mxtime), resptime(0.f), speed(30.f), minPosition(minPosition_), maxPosition(maxPosition_)
{
	std::random_device mch;
	std::default_random_engine generator(mch());
	std::uniform_int_distribution<int> distribution(minTime, maxTime);
	resptime = distribution(generator);
}



void Spawner::update(const float& deltatime)
{
	resptime -= deltatime;
	if (resptime < 0)
	{
		std::random_device mch;
		std::default_random_engine generator(mch());
		std::uniform_int_distribution<int> distribution(minTime, maxTime);
		resptime = distribution(generator);

		Enemy* enemy = new Enemy(m_game);
		enemy->setTag("Enemy");
		std::uniform_real_distribution<float> x_dist(minPosition, maxPosition);
		// pos_x losowa w zakresie od-do
		sf::Vector2f e_pos = sf::Vector2f(x_dist(generator), 0.0);
		enemy->setPosition(e_pos);
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

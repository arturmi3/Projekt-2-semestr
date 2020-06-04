#pragma once
#include "Player.h"
#include <vector>


class Game 
{
public:
	Game();

	void run();


	void clearNoActive();

	sf::Texture m_texture;

	const sf::Vector2u getWindowSize() const {
		return m_window->getSize();
	}

	void addobject(GameObject* object);

private:

	void insertQueue();

	void clear();

	void updateCollision();

	std::vector<GameObject*> m_container;

	std::vector<GameObject*> m_queue;

	sf::RenderWindow* m_window;

	bool m_cleaned;
};
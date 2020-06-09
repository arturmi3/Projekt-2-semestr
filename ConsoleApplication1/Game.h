#pragma once
#include "Player.h"
#include <vector>
#include <SFML/Audio.hpp>


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

	sf::View& getView() {
		return m_view;
	}

	void die();

	void setResolution(const sf::Vector2u& res)
	{
		m_window->create(sf::VideoMode(res.x,res.y), "Faraon Mumia znowu atakuje caly kosmos");
	}

	void addobject(GameObject* object);

private:

	void dieScreen();

	void insertQueue();

	void clear();

	void updateCollision();

	std::vector<GameObject*> m_container;

	std::vector<GameObject*> m_queue;

	sf::RenderWindow* m_window;

	sf::View m_view;

	bool m_cleaned;

	bool m_die;
};
#pragma once

#include<iostream>
#include<vector>

#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

	//Game engine

class Game
{
private:
	//Variables

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse Position
	sf::Vector2i mouseposWindow;
	sf::Vector2f mousePosView;

	//Game Logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	

	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();
public:
	// Constructor/Destructor
		Game();
		virtual ~Game();
	
	//Accessors
		const bool getWindowIsOpen() const;

	//Functions
		void spawnEnemy();
		void pollEvents();
		void update();
		void updateEnemy();
		void render();
		void renderEnemy();
		void updateMousePos();
};


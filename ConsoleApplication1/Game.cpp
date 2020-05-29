#include "Game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	
	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;

}

void Game::initWindow()
{
	this->videoMode.height = 1200;
	this->videoMode.width = 1080;
	this->window = new sf::RenderWindow(this->videoMode, "Gra", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(0,0);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Black);
}


//Constructor Destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}
Game::~Game()
{
	delete this->window;
}

const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen() ;
}

//Functions

void Game::spawnEnemy()
{
	this->enemy.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x) - (this->enemy.getSize().x)),0.f);
	this->enemy.setFillColor(sf::Color::Green);
	this->enemies.push_back(this->enemy);

}
void Game::renderEnemy()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}


void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}
	}
}



void Game::updateEnemy()
	//updating enemy timer
{
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
	else
		this->enemySpawnTimer += 1.f;
	}
	//move the enemies
	for (int i=0; i < this->enemies.size(); i++ )
	{
		bool deleted = false;

		this->enemies[i].move(0.f, 2.f);

	//checked if clicked upon
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
			{
				this->enemies.erase(this->enemies.begin() + i);
				deleted = true;
			}
		}
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			if(!deleted)
				this->enemies.erase(this->enemies.begin() + i);
			//this->
		}
	}
}

void Game::updateMousePos()
{
	this->mouseposWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mouseposWindow);
}

void Game::update()
{
	this->pollEvents();
	this->updateMousePos();
	this->updateEnemy();
}

void Game::render()
{
	this->window->clear(sf::Color::Cyan);

	//Draw game
	this->renderEnemy();
	this->window->display();
	
}





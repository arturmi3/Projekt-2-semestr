#include "Game.h"
#include "Background.h"
#include "Enemy.h"
#include "Spawner.h"
Game::Game()
	:m_cleaned(true), m_die(false)
{
	//nie ruszac 
	m_view = sf::View(sf::Vector2f(350, 500), sf::Vector2f(700, 1000));

	// tutaj zmieniac rozmiar okna
	m_window = new sf::RenderWindow(sf::VideoMode(1000,1500), "Faraon Mumia znowu atakuje caly kosmos");

	m_window->setFramerateLimit(60);
}

void Game::run()
{
	Player* player = new Player(this);
	player->setTag("Player");

	// load
	sf::Texture tex;
	tex.loadFromFile("Graphic/tuo.png");
	sf::Texture m_player;
	m_player.loadFromFile("Graphic/1.png");
	sf::Texture m_enemy1;
	m_enemy1.loadFromFile("Graphic/2.png");
	sf::Texture m_enemy2;
	m_enemy2.loadFromFile("Graphic/2.png");
	sf::Texture m_enemy3;
	m_enemy3.loadFromFile("Graphic/3.png");
	sf::Texture m_enemy4;
	m_enemy4.loadFromFile("Graphic/4.png");
	sf::Texture m_enemy5;
	m_enemy5.loadFromFile("Graphic/5.png");
	sf::Texture m_enemy6;
	m_enemy6.loadFromFile("Graphic/6.png");
	sf::Texture m_bullet;
	m_bullet.loadFromFile("Graphic/bullet.png");

	
	// set

	//Enemy enemy(this, 50.f);
	//enemy.setTexture(m_enemy1);
	//enemy.setScale(sf::Vector2f(0.2f, 0.2f));
	//enemy.rotate(180);

	Background back;
	back.setTexture(tex);
	back.adjust(m_view.getSize());
	
	player->setTexture(m_player);
	player->setScale(sf::Vector2f(1.5f, 1.5f));
	player->setPosition(sf::Vector2f(m_view.getSize().x/2.f, m_view.getSize().y - (m_player.getSize().y * 2.f-30.f))) ;
	player->setBulletTexture(&m_bullet);

	// difficult
	//m_difficultLevel
	Spawner* spawner = new Spawner(2, 4, this);
	spawner->setEnemyTexture(m_enemy1);
	spawner->setEnemySpeed(200);
	spawner->setPosition(sf::Vector2f(80, 0));
	m_container.push_back(spawner);

	spawner = new Spawner(2, 6, this);
	spawner->setEnemyTexture(m_enemy1);
	spawner->setEnemySpeed(200);
	spawner->setPosition(sf::Vector2f(250, 0));
	m_container.push_back(spawner);

	spawner = new Spawner(2, 6, this);
	spawner->setEnemyTexture(m_enemy1);
	spawner->setEnemySpeed(200);
	spawner->setPosition(sf::Vector2f(350, 0));
	m_container.push_back(spawner);

	spawner = new Spawner(2, 6, this);
	spawner->setEnemyTexture(m_enemy1);
	spawner->setEnemySpeed(200);
	spawner->setPosition(sf::Vector2f(500, 0));
	m_container.push_back(spawner);



	sf::Music ost1;
	ost1.openFromFile("Music/1.wav");
	sf::Music ost2;
	ost2.openFromFile("Music/2.wav");
	ost1.play();
	ost1.setVolume(30.f);

	spawner->setPosition(sf::Vector2f(100, 0));
	//insert
	m_container.push_back(&back);
	m_container.push_back(player);

//	m_container.push_back(&enemy);

	sf::Clock clock;
	float frameStartTime;
	float deltaTime = 1 / 60.f;
	while (m_window->isOpen())
	{
		frameStartTime = clock.getElapsedTime().asSeconds();
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}

		if (ost1.getStatus() != sf::SoundSource::Status::Playing)
		{
			ost2.play();
		}
		// update collision
		updateCollision();

		// update
		for (auto& k : m_container)
		{
			k->update(deltaTime);
		}

		if (!m_cleaned)
			clear();

		//view
		m_view.setCenter(sf::Vector2f(350.f, 500.f));
		m_window->clear();
		m_window->setView(m_view);

		// draw
		for (auto& k : m_container)
		{
			m_window->draw(*k);
		}
		m_window->display();
		deltaTime = clock.getElapsedTime().asSeconds() - frameStartTime;

		insertQueue();

		if  (m_die)
			dieScreen();

	}
	return;
}

void Game::clearNoActive()
{
	m_cleaned = false;
}

void Game::addobject(GameObject* object)
{
	if  (m_queue.size()  <  3)
		m_queue.push_back(object);
}

void Game::insertQueue()
{
	if (m_queue.empty() == false)
	{
		for (auto k : m_queue)
			m_container.push_back(k);
		m_queue.clear();
	}
}

void Game::clear()
{
	if (!m_container.empty())
	{
		auto k = [](GameObject* obj)->bool 
		{
			return !(obj->isActive());
		};

		auto it = std::remove_if(m_container.begin(), m_container.end(), k);

		auto it1 = it;

		if (it1 != m_container.end())
		{
			++it1;
			for (; it1 != m_container.end(); ++it1)
			{
				delete (*it1);
			}

			m_container.erase(it, m_container.end());
		}
	}
	m_cleaned = true;
}

void Game::updateCollision()
{

	for (auto it1 = m_container.begin(); it1 != m_container.end(); ++it1)
	{
		for (auto it2 = it1; it2 != m_container.end(); ++it2)
		{
			if(it1 != it2)
			{
				auto& s1 = (*it1)->getSprite();
				auto& s2 = (*it2)->getSprite();

				auto rect1 = s1.getGlobalBounds();
				auto rect2 = s2.getGlobalBounds();

				
				if(rect1.intersects(rect2)){
					(*it1)->onColliosion(*it2);
					(*it2)->onColliosion(*it1);
				}
			}
		}
	}
}

void Game::dieScreen()
{
	sf::Texture gover;
	gover.loadFromFile("Graphic/gover.png");

	sf::Sprite sprite;
	sprite.setTexture(gover);

	sprite.setScale(m_view.getSize().x / gover.getSize().x, m_view.getSize().y / gover.getSize().y);

	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}
		if (!m_cleaned)
			clear();
		//view
		m_view.setCenter(sf::Vector2f(350.f, 500.f));
		m_window->clear();
		m_window->setView(m_view);

		// draw
		for (auto& k : m_container)
		{
			m_window->draw(*k);
		}
		m_window->draw(sprite);
		m_window->display();
	}
}

void Game::die()
{
	m_die = true;
}
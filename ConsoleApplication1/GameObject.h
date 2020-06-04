#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Game;

class GameObject : public sf::Drawable
{
public:

	GameObject(Game* game)
		:m_isActive(true), m_game(game)
	{

	}

	virtual ~GameObject() = default;


	virtual void setPosition(const sf::Vector2f& pos) 
	{
		m_sprite.setPosition(pos);
		m_position = pos;
	}
	virtual void setScale(const sf::Vector2f& sca) 
	{
		m_sprite.setScale(sca);
		m_scale = sca;
	}

	virtual void update(const float& deltaTime) = 0;

	virtual void setOrigin(const sf::Vector2f& origin)
	{
		m_sprite.setOrigin(origin);
		m_origin = origin;
	}

	virtual void move(const sf::Vector2f& delta)
	{
		m_sprite.move(delta);
		m_position += delta;
	}

	virtual const sf::Vector2f& getPosition() const
	{
		return m_position;
	};

	virtual const sf::Vector2f& getScale() const
	{
		return m_scale;
	};

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		target.draw(m_sprite, states);
	};

	virtual void setTexture(const sf::Texture& tex) 
	{
		m_sprite.setTexture(tex);
	}


	virtual const sf::Sprite& getSprite() const 
	{
		return m_sprite;
	}

	virtual void remove() 
	{
		m_isActive = false;
	}

	virtual bool isActive() const 
	{
		return m_isActive;
	}

	virtual void onColliosion(GameObject* ptr) {};

	virtual const std::string& getTag() const 
	{
		return m_tag;
	}
	virtual void setTag(const std::string& tag) 
	{
		m_tag = tag;
	}
	virtual const sf::Vector2f& getOrigin() const {
		return m_origin;
	}

	virtual void rotate(const float dgr)
	{
		m_sprite.rotate(dgr);
	}

protected:
	std::string m_tag;
	sf::Vector2f m_position;
	sf::Vector2f m_scale;
	sf::Sprite m_sprite;
	sf::Vector2f m_origin;
	bool m_isActive;
	Game* m_game;
};

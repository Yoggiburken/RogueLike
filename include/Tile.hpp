#include<SFML/Graphics.hpp>


#ifndef TILE_HPP
#define TILE_HPP
class Tile : public sf::Drawable {
private:
	sf::Sprite			sprite;
	bool				blocking;
	bool				movable;
public:
	void				setSprite(sf::Sprite& sprite);
	void				setPosition(sf::Vector2f position);
	
	bool				isBlocking();
	bool				isMovable();
	
	sf::Vector2f		getPosition();
};
#endif

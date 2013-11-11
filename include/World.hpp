#include<vector>
#include<SFML/Graphics.hpp>
#include"Tile.hpp"

#ifndef WORLD_HPP
#define WORLD_HPP
class World : public sf::Drawable {
private:
	std::vector<std::vector<std::vector<Tile*> > >	m_tilechunks;
public:
	bool								saveToFile(std::string& mapname);
	bool 								loadFromFile(std::string& mapname);
	bool								generate(std::string& mapname);
};
#endif

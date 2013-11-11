#include<map>
#include<SFML/Graphics.hpp>
#include"Tile.hpp"

#ifndef TILE_BUCKET_HPP
#define TILE_BUCKET_HPP
class TileBucket {
private:
	std::map<std::string, Tile*> tile_types;
public:
	bool						loadFromFile(std::string& filename);
	Tile&						getTile(std::string tilename);
};
#endif

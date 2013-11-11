#include"../include/GrassTile.hpp"
#include"../include/TileBucket.hpp"

extern TileBucket tilebucket;

GrassTile::GrassTile() : Tile(tilebucket.getTile(std::string("GrassTile")))
{}

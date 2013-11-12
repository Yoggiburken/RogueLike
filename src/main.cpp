#include"../include/Game.hpp"
#include"../include/TileBucket.hpp"
#include"../include/MediaBucket.hpp"

sf::RenderWindow 	app(sf::VideoMode(800, 600), "RogueLike!");
TileBucket  		tilebucket;
MediaBucket 		mediabucket;

int main()
{
	app.setVerticalSyncEnabled(true);
	Game 		game;
	Menu_return state = MENU;
	while(app.isOpen())
	{

		if(state == MENU) {
			state = game.menu();
		} else if(state == PLAY) {
			state = game.game();
		} else if(state == EXIT) {
			app.close();
		} 
	}
	return 0;
}

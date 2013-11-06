#include"../include/Game.hpp"


sf::RenderWindow app(sf::VideoMode(800, 600), "RogueLike!");

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

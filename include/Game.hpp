#include<map>
#include<SFML/Graphics.hpp>
#include<SFGUI/SFGUI.hpp>

#ifndef MENU_RETURN
#define MENU_RETURN
enum Menu_return {PLAY, EXIT, MENU};
#endif

#ifndef GAME_HPP
#define GAME_HPP
class Game {
private:
	sfg::SFGUI									sfgui;
	sfg::Desktop								desktop;
	std::map<std::string, sfg::Widget::Ptr>		widgets;
	Menu_return 								state;

	sf::Event									event;
	sf::Clock									clock;
	sf::Time									elapsed_time;
		
	bool										menuInit();
	bool										gameInit(std::string map_name);
	void										setStateMENU();
	void										setStatePLAY();
	void										setStateEXIT();
public:
	Menu_return									menu();
	Menu_return									game();
};
#endif

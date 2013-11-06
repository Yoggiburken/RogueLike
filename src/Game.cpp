#include"../include/Game.hpp"

extern sf::RenderWindow app;

Menu_return Game::menu()
{
	this->menuInit();
	
	/*TEMP*/app.resetGLStates();/*TEMP*/
	
	while(app.isOpen())
	{
		while(app.pollEvent(this->event))
		{
			this->desktop.HandleEvent(event);
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					return EXIT;
				}
			}
			if(this->state != MENU) {
				return this->state;
			}
		}
		this->elapsed_time = this->clock.restart();
		this->desktop.Update(this->elapsed_time.asSeconds());

		app.clear();
		this->sfgui.Display(app);
		app.display();
	}
}

bool Game::menuInit()
{
	this->setStateMENU();
	sfg::Label::Ptr 	t_label(sfg::Label::Create("Menu"));
	sfg::Button::Ptr 	t_button(sfg::Button::Create("Play!"));
						t_button->GetSignal(sfg::Widget::OnLeftClick).Connect(&Game::setStateMENU(), this);
	sfg::Box::Ptr		t_box(sfg::Box::Create(sfg::Box::VERTICAL, 50.f));
						t_box->Pack(t_label);
						t_box->Pack(t_button, false, false);	
	sfg::Window::Ptr	t_window(sfg::Window::Create());
						t_window->SetTitle("Menu!");
						t_window->Add(t_box);
						t_window->SetAllocation(sf::FloatRect(250, 200, 300, 200));
						t_window->SetRequisition(sf::Vector2f(300, 200));
	
	this->widgets.insert(std::pair<std::string, sfg::Widget::Ptr>("Menu_label", t_label));
	this->widgets.insert(std::pair<std::string, sfg::Widget::Ptr>("Menu_button", t_button));
	this->widgets.insert(std::pair<std::string, sfg::Widget::Ptr>("Menu_box", t_box));
	this->widgets.insert(std::pair<std::string, sfg::Widget::Ptr>("Menu_window", t_window));
	
	this->desktop.Add(t_window);
}

Menu_return Game::game()
{}

bool Game::gameInit(std::string map_name)
{}

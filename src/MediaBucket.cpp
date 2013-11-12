#include"../include/MediaBucket.hpp"
#include<fstream>
#include<sstream>
#include<iostream>

void MediaBucket::loadMedia(std::string filename)
{
	std::ifstream 		file;
						file.open(filename.c_str());
	

	std::string 		parse;
	std::stringstream	ss;
	do{
		getline(file, parse);
		ss<<parse;
		ss>>parse;
		if(parse == "TEXTURE") {
			ss>>parse;
			sf::Texture 	t_text;
			t_text.loadFromFile(parse.c_str());
			size_t pos = 	parse.rfind("/");
							parse.erase(0, pos+1);
			this->textures.insert(std::pair<std::string, sf::Texture>(parse, t_text));
		} else if(parse == "SOUNDBUFFER") {
			ss>>parse;
			sf::SoundBuffer 	t_buffer;
			t_buffer.loadFromFile(parse.c_str());
			size_t pos = 		parse.rfind("/");
								parse.erase(0, pos);
			this->soundbuffers.insert(std::pair<std::string, sf::SoundBuffer>(parse, t_buffer));
		} else if(parse == "FONT") {
			ss>>parse;
			sf::Font	 	t_font;
			t_font.loadFromFile(parse.c_str());
			size_t pos = 	parse.rfind("/");
							parse.erase(0, pos);
			this->fonts.insert(std::pair<std::string, sf::Font>(parse, t_font));
		}
		ss.clear();
		parse.clear();
	}while(!file.eof());
}

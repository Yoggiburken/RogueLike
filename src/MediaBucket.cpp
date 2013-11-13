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
			parse.erase(0, parse.rfind("/")+1);
			this->textures.insert(std::pair<std::string, sf::Texture>(parse, t_text));
		} else if(parse == "SOUNDBUFFER") {
			ss>>parse;
			sf::SoundBuffer 	t_buffer;
			t_buffer.loadFromFile(parse.c_str());
			parse.erase(0, parse.rfind("/")+1);
			this->soundbuffers.insert(std::pair<std::string, sf::SoundBuffer>(parse, t_buffer));
		} else if(parse == "FONT") {
			ss>>parse;
			sf::Font	 	t_font;
			t_font.loadFromFile(parse.c_str());
			parse.erase(0, parse.rfind("/")+1);
			this->fonts.insert(std::pair<std::string, sf::Font>(parse, t_font));
		}
		ss.clear();
		parse.clear();
	}while(!file.eof());
}

bool MediaBucket::loadTextureFromFile(std::string filename)
{
	sf::Texture t_text;
	if(!t_text.loadFromFile(filename.c_str())) {
		return false;
	}
	filename.erase(0, filename.rfind("/")+1);
	this->textures.insert(std::pair<std::string, sf::Texture>(filename, t_text));
	return true;
}

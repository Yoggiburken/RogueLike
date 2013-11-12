#include"../include/MediaBucket.hpp"
#include<fstream>
#include<sstream>

bool MediaBucket::loadMedia(std::string filename)
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
							parse.erase(0, pos);
			
			this->textures.insert(std::pair<std::string, sf::Texture>(parse, t_text));
		}
	}while(!file.eof());
}

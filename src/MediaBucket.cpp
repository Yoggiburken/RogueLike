#include"../include/MediaBucket.hpp"
#include<fstream>

bool MediaBucket::loadMedia(std::string filename)
{
	std::ifstream 	file;
					file.open(filename.c_str());
	

	std::string parse;
	do{
		getline(file, parse);
		
	}while(!file.eof());
}

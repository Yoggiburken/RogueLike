#include<map>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


#ifndef MEDIA_BUCKET_HPP
#define MEDIA_BUCKET_HPP
class MediaBucket {
private:
	//	Media
	std::map<std::string, sf::Texture> 		textures;
	std::map<std::string, sf::SoundBuffer>	soundbuffers;
	std::map<std::string, sf::Font>			fonts;

	//	Media Names
	std::vector<std::string> 				texture_names;
	std::vector<std::string>				soundbuffer_names;
	std::vector<std::string>				font_names;
public:
	bool									loadMedia(std::string filename); 				//	Loads media with resource file
	bool									loadTextureFromFile(std::string filename);		
	bool									loadSoundBufferFromFile(std::string filename);
	bool									loadFontFromFile(std::string filename);

	int										getNumberOfTextures() 				const;
	int										getNumberOfSoundBuffers() 			const;
	int										getNumberOfFonts() 					const;

	std::string&							getTextureName(int index) 			const;
	std::string&							getSoundBufferName(int index) 		const;
	std::string&							getFontName(int index) 				const;

	sf::Texture&							getTexture(std::string name) 		const;
	sf::SoundBuffer&						getSoundBuffer(std::string name) 	const;
	sf::Font&								getFont(std::string name) 			const;
};
#endif

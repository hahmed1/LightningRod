#ifndef SMARTTEXTURE_H
#define SMARTTEXTURE_H
#include <SDL2/SDL.h>
#include <string>
class SmartTexture{
	int width;
	int height;
	SDL_Texture *texture;
	bool _break;
	std::string word;
	public:
		SmartTexture(int , int, SDL_Texture*, bool, std::string);
		SmartTexture();

		bool is_break(); 
		
		SDL_Texture* getTexture();
		int getWidth();
		int getHeight();

		std::string getWord();

};	


#endif

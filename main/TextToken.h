#ifndef TEXTTOKEN_H
#define TEXTTOKEN_H
#include <string>
#include <SDL2_ttf/SDL_ttf.h>

/*
 * This class is pretty much a plain old data class.
 *
 * It defines the default params for various types of text 
 * (i.e. color, size, etc).
 *
 */
class TextToken{
	std::string word;
	int size;
	Uint8 rc, gc, bc, ac;
	TTF_Font *font;

	/*	
	bool para;
	bool heading;
	bool link;
	*/	
	
	//TODO DRY this code up...this currently exists in 2 different 
	//places, here and PageViewModel
	static const int para = 1 << 0;
	static const int link = 1 << 1;
	static const int head = 1 << 2;


	public:
		TextToken(std::string w , unsigned int flags);
		~TextToken();
		int getNumLetters();
		std::string getWord();
		int getWidth(); 		//used by pageview to fit
		int getHeight();

		std::string toString();
};

#endif

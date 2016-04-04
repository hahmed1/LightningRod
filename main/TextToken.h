#ifndef TEXTTOKEN_H
#define TEXTTOKEN_H
#include <string>
#include <SDL2_ttf/SDL_ttf.h>
class TextToken{
	std::string word;
	int size;
	Uint8 rc, gc, bc, ac;
	TTF_Font *font;
	
	bool para;
	bool heading;
	bool link;
	
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

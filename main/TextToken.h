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

	bool _para;
	bool _heading;
	bool _link;
	
	bool _break; 
	//TODO DRY this code up...this currently exists in 2 different 
	//places, here and PageViewModel
	static const int para = 1 << 0;
	static const int link = 1 << 1;
	static const int head = 1 << 2;


	public:
		TextToken(std::string w , unsigned int flags);
		TextToken();
		~TextToken();
		int getNumLetters();
		std::string getWord();

		std::string toString();

		bool is_para();
	      	bool is_heading();
		bool is_link();	

		bool is_break();
};

#endif

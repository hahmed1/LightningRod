#ifndef FONT_H
#define FONT_H
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>
class Font{

	int size;
	TTF_Font *font;
	SDL_Texture* texture ;
	SDL_Renderer* renderer;
	int iWidth, iHeight;
	std::string word;
	void free();
	public:
		Font( SDL_Renderer*, TTF_Font* );
		~Font();
		


		/*IMP need to call this before render()
		 *
		 * responsible for setting:
		 * 	texture, 
		 * 	iWidth/Height
		 *
		 */
		bool loadFromRenderedText( std::string , SDL_Color );

		void render( int x, int y );
		int getTextWidth();
		int getTextHeight();
		std::string getWord();

};

#endif

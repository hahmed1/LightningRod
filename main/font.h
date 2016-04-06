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

	int render_x;
	int render_y;
	public:
		Font( SDL_Renderer*, TTF_Font*, int rx, int ry );
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
		void render();
		int getTextWidth();
		int getTextHeight();
		std::string getWord();

};

#endif

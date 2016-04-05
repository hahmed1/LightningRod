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
	Uint8 rc,gc,bc,ac;
	SDL_BlendMode bm;
	int iWidth, iHeight;

	void free();
	public:
		Font( SDL_Renderer*, TTF_Font*, int );
		~Font();
		
		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode(SDL_BlendMode blendMode);
		void setAlpha(Uint8 alpha);


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
};

#endif

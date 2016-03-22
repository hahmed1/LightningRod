#ifndef PAGEVIEW
#define PAGEVIEW
#include <SDL2/SDL.h>
class PageView
{
	//TODO add PageViewModel

	/* assume texture has  
	*  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET flags set
	*  and same height and width as the main window 
	*/ 
	SDL_Texture *texture;
	
	int screen_w , screen_h;

	static const int url_color   = 0x0080FF80;
	static const int blank_color = 0x00000000;
	int url_cur_color;
	SDL_Rect url_bar;
	
	public:
		PageView(SDL_Texture *text, int w, int h);	
		void shiftUp();
		void shiftDown();
		void pageUp();
		void pageDown();
		void showUrlBar();
		void hideUrlBar();
		void showLinksBar();
		SDL_Texture* getTexture();
};
#endif


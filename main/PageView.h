#ifndef PAGEVIEW
#define PAGEVIEW
#include <SDL2/SDL.h>
#include "font.h"
class PageView
{
	//TODO add PageViewModel

	SDL_Renderer *renderer;
	
	int screen_w , screen_h;

	SDL_Rect url_bar;
	SDL_Rect links_bar;

	bool links;	
	bool url;

	Font *default_font;

	public:
		PageView(SDL_Renderer *r, int w, int h);	
		void shiftUp();
		void shiftDown();
		void pageUp();
		void pageDown();
		void showUrlBar();
		void hideUrlBar();
		void showLinksBar();
		void hideLinksBar();
		void loopCall(); 
		void hideAll();
		
};
#endif


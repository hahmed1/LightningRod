#ifndef PAGEVIEW
#define PAGEVIEW
#include <SDL2/SDL.h>
class PageView
{
	//TODO add PageViewModel

	SDL_Renderer *renderer;
	
	int screen_w , screen_h;

	SDL_Rect url_bar;
	
	bool url;

	public:
		PageView(SDL_Renderer *r, int w, int h);	
		void shiftUp();
		void shiftDown();
		void pageUp();
		void pageDown();
		void showUrlBar();
		void hideUrlBar();
		void showLinksBar();
		void loopCall(); 
};
#endif


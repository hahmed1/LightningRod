#include "PageView.h"
PageView::PageView(SDL_Renderer *r, int w, int h)
{
	renderer = r;	

	screen_w = w;
	screen_h = h;

	//SET Url bar params	
	url_bar.x = 0;
	url_bar.y = 0;
	url_bar.w = screen_w;
	url_bar.h = screen_h  / 8;	

	url = false;	
	

	//TODO setup default view range

}

void PageView::loopCall()
{
	if(url){
		//this->showUrlBar();
		SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0xFF, 0x80);
		SDL_RenderFillRect(renderer, &url_bar);
	}
	
}

void PageView::showUrlBar()
{
	url = true;
	SDL_Log("Url Bar set to TRUE");
}

void PageView::hideUrlBar()
{
	url = false;
	SDL_Log("Url Bar set to FALSE");
}



#include "PageView.h"
PageView::PageView(SDL_Texture *text, int w, int h)
{
	texture = text;	

	screen_w = w;
	screen_h = h;

	//SET Url bar params	
	url_bar.x = 0;
	url_bar.y = 0;
	url_bar.w = screen_w;
	url_bar.h = screen_h  / 4;	
	
	url_cur_color = blank_color;

	//TODO setup default view range
}

void PageView::showUrlBar()
{
	url_cur_color = url_color;	
}

void PageView::hideUrlBar()
{
	url_cur_color = blank_color;	
}

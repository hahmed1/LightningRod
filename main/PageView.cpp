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


	//SET links bar params
	
	int box_length = 200;

	links_bar.x = screen_w - box_length ;
	links_bar.y = screen_h - box_length ;
	links_bar.w = box_length;
	links_bar.h = box_length;

	

	url = false;	
	links = false;	

//	default_font = new Font(renderer, ,10);

	//TODO setup default view range

}

void PageView::loopCall()
{
	if(url){
		//this->showUrlBar();
		SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0xFF, 0x80);
		SDL_RenderFillRect(renderer, &url_bar);
	}

	if(links){
		SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0xFF, 0x80);
		SDL_RenderFillRect(renderer, &links_bar);
	
	}
	
}

//TODO add text input
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

//TODO add links to Links bar
void PageView::showLinksBar()
{
	links = true;
	SDL_Log("Links Bar set to TRUE");
}


void PageView::hideLinksBar()
{
	links = false;
	SDL_Log("Links Bar set to FALSE");


}

void PageView::hideAll()
{
	this->hideUrlBar();
	this->hideLinksBar();
}











#ifndef PAGEVIEW
#define PAGEVIEW
#include <SDL2/SDL.h>
#include "font.h"
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "PageViewModel.h"
#include "TextToken.h"
#include <vector>
class PageView
{
	//TODO add PageViewModel

	SDL_Renderer *renderer;
	
	int screen_w , screen_h;

	SDL_Rect url_bar;
	SDL_Rect links_bar;

	bool links;	
	bool url;
	
	//This needs to go
	Font *font;
	Font *font_other;
	Font *font_last;
	PageViewModel *pvm;
	std::vector<TextToken*> first_words;

	// Represents the top-leftmost word on the page. 
	// A pointer to one of the elements of the pvm.
	TextToken *top_word;  


	TTF_Font *font1;

	SDL_Color green   = { 0x00, 0xFF, 0x00 };
	SDL_Color magenta = { 0xFF, 0x00, 0xFF };
	SDL_Color blue    = { 0x00, 0xEE, 0xFF };
	
	void getTextFromModel();
	void renderText();

	// padding 
	static const int dx = 15;
	static const int dy = 5;

	//TODO add links data storage
	
	//TODO add a Color class with various colors 
	// (e.g. green, blue, magenta, etc)	
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
		void setPageViewModel(PageViewModel *p);		
};
#endif


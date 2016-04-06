#ifndef PAGEVIEW
#define PAGEVIEW
#include <SDL2/SDL.h>
#include "font.h"
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "PageViewModel.h"
#include "TextToken.h"
#include <vector>
#include "globals.h"
class PageView
{
	//TODO add PageViewModel

	SDL_Renderer *renderer;
	
	int screen_w , screen_h;

	SDL_Rect url_bar;
	SDL_Rect links_bar;

	bool links;	
	bool url;
	
	PageViewModel *pvm;
	std::vector<TextToken*> first_words;

	// Represents the top-leftmost word on the page. 
	// A pointer to one of the elements of the pvm.
	TextToken *top_word;  


	TTF_Font *font1;    // the default font
	TTF_Font *font2;    // the heading font
		
	void renderText();

	// padding 
	static const int dx = 15;
	static const int dy = 5;

	static const int font1_size = 14;
	static const int font2_size = 22;
	static const int break_size = 40;	
	// rendering position
	int x_pos;
	int y_pos;
	
	void new_line(int amt);
	void advance_xpos(int amt);

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


#include "PageView.h"
#include <iostream>
PageView::PageView(SDL_Renderer *r, int w, int h)
{

	//SETUP
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

	//declare fonts here.  Initalize below.  Pass to constructor for
	// font after that.
	//TTF_Font *font1;	


	int img_flags = IMG_INIT_PNG;
	if( !(IMG_Init(img_flags) & img_flags)){
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR , "Failed to initialize SDL Image: %s\n", SDL_GetError());
	} else{
	
		SDL_Log("Initialized SDL_Image\n");
	}


	if( TTF_Init() == -1){
		SDL_LogCritical( SDL_LOG_CATEGORY_ERROR , "Failed to initialize SDL TTF %s\n", SDL_GetError());
	} else{
		SDL_Log("Initialized SDL_TTF");
	}


	// Initialize fonts here
	font1 = TTF_OpenFont("OpenSans-Bold.ttf", 14);	
	font2 = TTF_OpenFont("OpenSans-Bold.ttf", 18);	
	if(font1 != NULL){
		SDL_Log("Font1 loaded");
	}
	if(font2 != NULL){
		SDL_Log("Font2 loaded");
	}
	// Create the "Font" objects here.
	// These really should not be called Font.
	// They should be called "Word" or something likethat
	// based on the way they are being used.  
	
	//getTextFromModel();	
	//TODO setup default view range

		


}


void PageView::renderText()
{
	int x_pos = dx;
	int y_pos = dy;
	int count = 0;
	std::vector<Font*> words; 
	std::vector<TextToken*> text = pvm->get_text_stream();	
	for(std::vector<TextToken*>::iterator it = text.begin();
			it != text.end();
			++it){
		std::string s;
		s.append((*it)->getWord());
		s.append(" ");

		
		//paragraph text branch	
		if((*it)->is_para()){
		
			Font *cur = new Font(renderer, font1);
			cur->loadFromRenderedText(s, col_green);
			words.push_back(cur);
		}

		//link text branch
		else if((*it)->is_link()){
			Font *cur = new Font(renderer, font1);
			cur->loadFromRenderedText(s, col_blue);	
			words.push_back(cur);
		}	
		// heading text branch
		else if((*it)->is_heading()){

			Font *cur = new Font(renderer, font2);
			cur->loadFromRenderedText(s, col_magenta);	
			words.push_back(cur);
		} 

			
	}

	for(std::vector<Font*>::iterator it = words.begin();
			it != words.end();
			++it){
		/*	
		if((*it) == NULL){
			std::cout << "WTF?" << std::endl;
		}else {
			std::cout << "iterator not null: " << std::endl;
			std::cout << (*it) << std::endl;	

		} */
		
		/*
		SDL_Log("The Word: %s\n" , (*it)->getWord().c_str());
		SDL_Log("Printing font information:\n");
		SDL_Log("width: %d\n" , (*it)->getTextWidth());
		SDL_Log("height: %d\n" , (*it)->getTextHeight());
		*/
		(*it)->render(x_pos, y_pos);

		int textWidth = (*it)->getTextWidth();
		int textHeight = (*it)->getTextHeight();
		//TODO get rid of this magic number	
		if(x_pos + textWidth + 30 < screen_w ){
			x_pos += textWidth;
		} else {
			x_pos = dx;
			y_pos += textHeight; 
		}

	}

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

	// text loading logic goes here
	renderText();	
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


void PageView::setPageViewModel(PageViewModel *p)
{
	/*
	 * Uncomment this when the destructor is implemented.
	 * But for now, memory leak away!
	if(pvm != NULL){
		delete pvm;
	} */
	pvm = p;	
	
}








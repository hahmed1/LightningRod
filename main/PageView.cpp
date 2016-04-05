#include "PageView.h"
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
	font1 = TTF_OpenFont("OpenSans-Bold.ttf", 16);	
	
	if(font1 != NULL){
		SDL_Log("Font loaded");
	}

	// Create the "Font" objects here.
	// These really should not be called Font.
	// They should be called "Word" or something likethat
	// based on the way they are being used.  
	font = new Font(renderer,font1,  30);
	font_other = new Font(renderer, font1, 20);	
	font_last = new Font(renderer, font1, -341);		
	
	//getTextFromModel();	
	//TODO setup default view range

		


}


void PageView::getTextFromModel()
{
	font->loadFromRenderedText("This is some text!", green);

}

void PageView::renderText()
{
	int x_pos = dx;
	int y_pos = dy;

//	std::string word_strs;
	std::vector<Font*> words; 
	std::vector<TextToken*> text = pvm->get_text_stream();	
	for(std::vector<TextToken*>::iterator it = text.begin();
			it != text.end();
			++it){
//		word_strs.append((*it)->getWord());
//		word_strs.append(" ");	
		std::string s;
		s.append((*it)->getWord());
		s.append(" ");
		
		Font *cur = new Font(renderer, font1, 10);
		cur->loadFromRenderedText(s, green);
		words.push_back(cur);
			
	}

	for(std::vector<Font*>::iterator it = words.begin();
			it != words.end();
			++it){
		(*it)->render(x_pos, y_pos);
		x_pos += 100;
		y_pos += 25;

	}

//	font->render(dx,dy);
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








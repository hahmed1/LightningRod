#include "TextRenderer.h"
#include "NonLeafTag.h"
#include <iostream>

TextRenderer::TextRenderer(SDL_Renderer *r, int w, int h)
{
	dx = 10;
	dy = 10;

	x_pos = dx;
	y_pos = dy;

	renderer = r;

	surface_table = new std::vector<SmartTexture*>();
	first_words   = new std::vector<SmartTexture*>();
	screen_w = w;
	screen_h = h;

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
	font1 = TTF_OpenFont("OpenSans-Bold.ttf", font1_size);
	font2 = TTF_OpenFont("OpenSans-Bold.ttf", font2_size);
	if(font1 != NULL){
		SDL_Log("Font1 loaded");
	}
	if(font2 != NULL){
		SDL_Log("Font2 loaded");
	}

	// Set log file
	logfile.open("render-info.txt");

	// TEST
	//

	//color gets flipped
	SDL_Color black = {0x00, 0x00, 0x00};
	SDL_Color red   = {0xFF, 0x00, 0x00};

	SDL_Surface *textSurface = TTF_RenderText_Blended(font2, "Hello, World", col_green);


	SDL_Surface *textSurface2 = TTF_RenderText_Blended(font1, "here it is", red);
	if( textSurface == NULL ){

		SDL_Log( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	texture  = SDL_CreateTextureFromSurface( renderer, textSurface );
	texture2 = SDL_CreateTextureFromSurface( renderer, textSurface2);
	img_w = textSurface->w;
	img_h = textSurface->h;

	img_w2 = textSurface2->w;
	img_h2 = textSurface2->h;

}

/*
 * extract rendering information from the tree here
 */
void TextRenderer::walkTree(Tag *root)
{
	SDL_Surface *textSurface;
	SDL_Texture *curTexture;
	std::vector<Tag*> *children = root->getChildren();

	enum font_type{
		HEADING,
		REGULAR,
		LINK
	};

	int cur_w;
	int cur_h;

	font_type cur_type;



	/*
	 * Loop invariant: text holds the current internal node's
	 * text children
	 */
	for(std::vector<Tag*>::iterator it = children->begin();
			it != children->end();
			++it){
		NonLeafTag *cur = (NonLeafTag *)*it;
		std::vector<std::string> text = cur->getTextChildren();

		std::string cur_node_type = (*it)->getType();
		if(cur_node_type == "HEADING"){
			cur_type = HEADING;
		}

		else if(cur_node_type == "PARA"){
			cur_type = REGULAR;
		}

		else if(cur_node_type == "LINK"){
			cur_type = LINK;
		}
		else continue;

		for(std::vector<std::string>::iterator ut = text.begin();
				ut != text.end();
				++ut){
			std::string cur_text = *ut;
			cur_text.append(" ");
			if(cur_type == HEADING){
				textSurface = TTF_RenderText_Blended(font2, cur_text.c_str(), col_mag);
			}
			else if(cur_type == REGULAR){
				textSurface = TTF_RenderText_Blended(font1, cur_text.c_str(), col_green);
			}

			else{
				textSurface = TTF_RenderText_Blended(font1, cur_text.c_str(), col_blue);
			}

			cur_w = textSurface->w;
			cur_h = textSurface->h;

			curTexture = SDL_CreateTextureFromSurface(renderer , textSurface);
			surface_table->push_back(new SmartTexture(cur_w, cur_h, curTexture , false, cur_text ));
			}

		const char *blank = "BLANK TEXT\n";
		textSurface = TTF_RenderText_Blended(font2, blank, col_blank);
		curTexture= SDL_CreateTextureFromSurface(renderer, textSurface );
		cur_w = textSurface->w;
		cur_h = textSurface->h;

		surface_table->push_back(new SmartTexture(cur_w, cur_h, curTexture, true, "BLANK"));




	}

		/* Setup all the important stuff */
		int position = 0;

		setupDoc();
}


/*
 * This gets called when a page is first created.
 *
 *
 */
void TextRenderer::setupDoc()
{
	x_pos = dx;
	y_pos = dy;

	int cur_w ;
	int cur_h ;

	for(std::vector<SmartTexture*>::iterator it = surface_table->begin();
			it != surface_table->end();
			++it
			){
	if(x_pos == dx){
			first_words->push_back(*it);
		}


	if(!(*it)->is_break()){

			cur_w = (*it)->getWidth();
			cur_h = (*it)->getHeight();

			if(x_pos + cur_w  < screen_w - dx){



				log_render_info(*it, x_pos, y_pos);
				x_pos += cur_w;

			}
			else{
				x_pos = dx;
				y_pos += cur_h;

				log_render_info(*it, x_pos, y_pos);

				x_pos += cur_w;
			}




		}

		//new line
		else{
			cur_h = (*it)->getHeight();
			x_pos = dx;
			y_pos += dy + cur_h;

			log_render_info(*it, x_pos, y_pos);
		}


	}

	
	doc_head = first_words->begin();
}

void TextRenderer::log_render_info(SmartTexture *s, int x, int y)
{

	logfile << "Rendering " << s->getWord() << " at x: " << x << " , y: " << y << std::endl;
}

void TextRenderer::printFirstWords()
{
	for(std::vector<SmartTexture*>::iterator it = first_words->begin();
			it != first_words->end();
			++it){

		std::cout << (*it)->getWord() << std::endl;

	}


}

void TextRenderer::renderCall()
{
	x_pos = dx;
	y_pos = dy;

	int cur_w ;
	int cur_h ;
	
	std::vector<SmartTexture*>::iterator it = surface_table->begin(); 
	for(;
			it != surface_table->end();
			++it){

		if(*it == *doc_head )
			break;
	
	}
	
	/*
	 * Need to do a search with the iterators
	 *
	 */


	for(;
			it != surface_table->end();
			++it
			){

	if(!(*it)->is_break()){

			cur_w = (*it)->getWidth();
			cur_h = (*it)->getHeight();

			if(x_pos + cur_w  < screen_w - dx){

				SDL_Rect curRect = {x_pos, y_pos, cur_w, cur_h};

				SDL_RenderCopyEx(renderer, (*it)->getTexture(), NULL, &curRect, 0.0, NULL, SDL_FLIP_NONE);

				x_pos += cur_w;

			}
			else{
				x_pos = dx;
				y_pos += cur_h;

				SDL_Rect curRect = {x_pos, y_pos, cur_w, cur_h};
				SDL_RenderCopyEx(renderer, (*it)->getTexture(), NULL, &curRect, 0.0, NULL, SDL_FLIP_NONE);

				x_pos += cur_w;
			}




		}

		//new line
		else{
			cur_h = (*it)->getHeight();
			x_pos = dx;
			y_pos += dy + cur_h;

			log_render_info(*it, x_pos, y_pos);
		}


	}
}

void TextRenderer::shiftDown()
{
	// check for valid position
	if(position + 1 < surface_table->size() - 1){
		position += 1;
		doc_head++;	
	
	}
}








#include "TextRenderer.h"
#include "NonLeafTag.h"
#include <iostream>

TextRenderer::TextRenderer(SDL_Renderer *r, int w, int h)
{
	renderer = r;

	surface_table = new std::vector<smart_texture*>();

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
		
		std::string cur_text;	
		for(std::vector<std::string>::iterator ut = text.begin();
				ut != text.end();
				++ut){
			cur_text.append( *ut) ;
			cur_text.append(" ");	
			
		}
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

			ordererd_pair pos = std::pair<int, int>(cur_w, cur_h);
			curTexture = SDL_CreateTextureFromSurface(renderer , textSurface);						
			surface_table->push_back(new smart_texture(curTexture, pos));	
			}

}



/*
void TextRenderer::renderCall()
{
	SDL_Rect renderQuad  = { 0, 0, img_w, img_h};
	SDL_Rect renderQuad2 = { 0, 40+ img_h, img_w2, img_h2};
	int val = SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);

	SDL_RenderCopyEx( renderer, texture2, NULL, &renderQuad2, 0.0, NULL, SDL_FLIP_NONE);


}

*/

void TextRenderer::renderCall()
{
	int x_pos = 10;
	int y_pos = 10;
	
	
	int cur_w;
	int cur_h;
		
	for(std::vector<smart_texture*>::iterator it = surface_table->begin();
			it != surface_table->end();
			++it
			){
		cur_w = (*it)->second.first;
		cur_h = (*it)->second.second;	
		SDL_Rect curRect = {x_pos, y_pos, cur_w, cur_h};		
		SDL_RenderCopyEx(renderer, (*it)->first, NULL, &curRect, 0.0, NULL, SDL_FLIP_NONE);

		if(x_pos + cur_w + 30 < screen_w)
			x_pos += cur_w;
		else{
			x_pos = 10;
			y_pos += 10 + cur_h;
		}
			
	
	}	


}


















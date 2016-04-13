#include "TextRenderer.h"
#include <iostream>

TextRenderer::TextRenderer(SDL_Renderer *r, int w, int h)
{
	renderer = r;

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

	SDL_Surface *textSurface = TTF_RenderText_Blended(font1, "Hello, World", black);
	
	SDL_Surface *textSurface2 = TTF_RenderText_Blended(font2, "here it is", red);
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

void TextRenderer::renderCall()
{
	SDL_Rect renderQuad  = { 0, 0, img_w, img_h};
	SDL_Rect renderQuad2 = { 0, 40+ img_h, img_w2, img_h2};
	int val = SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);

	SDL_RenderCopyEx( renderer, texture2, NULL, &renderQuad2, 0.0, NULL, SDL_FLIP_NONE);


}







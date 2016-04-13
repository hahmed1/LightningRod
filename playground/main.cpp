#include <SDL2/SDL.h>
#include "TextRenderer.h"
bool cur_mode;
bool running;

static const int screen_w = 720;
static const int screen_h = 720;

enum LR_MODES
{
	LR_DEFAULT,
	LR_LINKS,
	LR_URL

};

enum KEYS
{
	LR_L,
	LR_J,
	LR_K,
	LR_F,
	LR_G,
	LR_Q,
	LR_ESC,
	LR_SPACE,
	LR_RETURN,
	LR_UP,
	LR_DOWN
};



int main()
{	// DELCLARATIONS
	SDL_Window   *window;
	SDL_Renderer *renderer;
	SDL_Texture  *texture;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Log("SDL Initialized");

	// ASSIGNMENTS
	window = SDL_CreateWindow("LightningRod", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, (SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI));

	if( window == NULL ){
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create window: %s\n" , SDL_GetError());
	}


	Uint32 render_flags = ( SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC); 

		
	renderer = SDL_CreateRenderer(window, -1, render_flags);
	if( renderer == NULL ){
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create renderer %s\n" , SDL_GetError());
	}
	


	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); 

	


	texture = SDL_CreateTexture(renderer,
		       	SDL_PIXELFORMAT_RGBA8888,
		       	SDL_TEXTUREACCESS_TARGET,
		        screen_w,
			screen_h	);

	running = true;

	TextRenderer *r = new TextRenderer(renderer, screen_w, screen_h);

	// MAINLOOP
	while( running ){

		//TODO input handling
		SDL_Event event;
		while( SDL_PollEvent(&event) ){
			if( event.type == SDL_QUIT){
				running = false;
				break;
		
			}
		}	
		
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
		SDL_RenderClear(renderer);
	//	input_controller(pv);
		r->renderCall();		
		
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);				
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
//	TTF_Quit();
	SDL_Quit();
	return 0;
}
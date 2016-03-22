#include <SDL2/SDL.h>
#include "PageView.h"
// global declaration

#define TRUE  1
#define FALSE 0

int cur_mode;
int running;

static const int screen_w = 1024;
static const int screen_h = 1024;

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


void render_links_tab()
{

}

void shift_down()
{

}

void shift_up()
{


}

void page_down()
{

}

void page_up()
{


}

void show_url_bar()
{


}

void links_up()
{

}

void links_down()
{

}
void navigate()
{

}


/*
*
* By the time this gets called, mode switching already happened.
*
*/
void handle_keypress(int key)
{
	if((key == LR_L) && (cur_mode == LR_LINKS)){
		render_links_tab();
	}

	else if((key == LR_J) && (cur_mode == LR_DEFAULT)){
		shift_down();
	}

	else if((key == LR_K) && (cur_mode == LR_DEFAULT)){
		shift_up();
	}

	else if((key == LR_F) && (cur_mode == LR_DEFAULT)){
		page_down();
	}

	else if((key == LR_G) && (cur_mode == LR_DEFAULT)){
		page_up();
	}

	else if((key == LR_SPACE) && (cur_mode == LR_URL)){
		show_url_bar();
	}

	else if((key == LR_UP) && (cur_mode == LR_LINKS)){
		links_up();
	}

	else if((key == LR_DOWN) && (cur_mode == LR_LINKS)){
		links_down();
	}

	else if((key == LR_RETURN && (cur_mode == LR_LINKS))){
		navigate();
	}

	else{
		SDL_Log("Invalid key combination: %d\n" , key);
	}
}


// updates the mode from cur_mode to mode or throws an error if the request is invalid
void update_mode( const int mode )
{
	if((cur_mode == LR_DEFAULT) && (mode == LR_LINKS)){
		cur_mode = LR_LINKS;
		SDL_Log("Mode Switch from DEFAULT to LINKS\n");
	}

	else if((cur_mode == LR_DEFAULT) && (mode == LR_URL)){
		cur_mode = LR_URL;
		SDL_Log("Mode Switch from DEFAULT to URL\n");
	}


	else if((cur_mode == LR_LINKS) && (mode == LR_DEFAULT)){
		cur_mode = LR_DEFAULT;
		SDL_Log("Mode Switch from LINKS to DEFAULT\n");
	}

	else if((cur_mode == LR_URL) && (mode == LR_DEFAULT)){
		cur_mode = LR_DEFAULT;
		SDL_Log("Mode Switch from URL to DEFAULT\n");
	}

	else{
		SDL_Log("Invalid Mode Switch Attempt, cur mode: %d\n" , cur_mode);
	}
}

void input_controller()
{
	SDL_Event event;
	while( SDL_PollEvent(&event) ){
		if( event.type == SDL_QUIT){
			running = FALSE;
			break;
		}

		else if( event.type == SDL_KEYDOWN ){
			switch( event.key.keysym.sym ){

				case SDLK_l:
				SDL_Log("L key pressed\n");
				update_mode(LR_LINKS);
				handle_keypress(LR_L);
				break;
				case SDLK_j:
				SDL_Log("J key pressed\n");
				handle_keypress(LR_J);
				break;
				case SDLK_k:
				SDL_Log("K key pressed\n");
				handle_keypress(LR_K);
				break;
				case SDLK_f:
				SDL_Log("F key pressed\n");
				handle_keypress(LR_F);
				break;
				case SDLK_g:
				SDL_Log("G key pressed\n");
				handle_keypress(LR_G);
				break;
				case SDLK_SPACE:
				SDL_Log("Space key pressed");
				update_mode(LR_URL);
				handle_keypress(LR_SPACE);
				break;
				case SDLK_q:
				SDL_Log("Q key pressed\n");
				update_mode(LR_DEFAULT);
				break;
				case SDLK_ESCAPE:
				running = FALSE;
				break;

				case SDLK_UP:
				SDL_Log("Up key pressed\n");
				handle_keypress(LR_UP);
				break;
				case SDLK_DOWN:
				SDL_Log("Down key pressed\n");
				handle_keypress(LR_DOWN);
				break;

				case SDLK_RETURN:
				SDL_Log("Return key pressed\n");
				handle_keypress(LR_RETURN);
				break;
			}

		}
	}
}

//TODO
void render(SDL_Renderer *renderer)
{
	SDL_RenderClear(renderer);			

}
int main( int argc, char **argv )
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	PageView *pv;
	
	
	
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Log( "SDL Initialized\n");
	

	

	window = SDL_CreateWindow("Key Press Test", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, SDL_WINDOW_OPENGL );

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

	pv = new PageView(texture, screen_w, screen_h);

	running = TRUE;
	cur_mode = LR_DEFAULT;


	//temp
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = screen_w;
	r.h = screen_h / 8; 
	// program main loop
	while(running){
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		input_controller();
		SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0xFF, 0x80);
		SDL_RenderFillRect(renderer , &r);
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);				
	}



	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Process Complete, exiting \n");
	return 0;

}

#include <iostream>
#include <SDL2/SDL.h>

// global declaration

int cur_mode;
enum LR_MODES
{
		LR_DEFAULT,
		LR_LINKS,
		LR_URL

};

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

int main( int argc, char **argv )
{
	SDL_Window *window;
	int screen_w, screen_h;
	bool running;

	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Log( "SDL Initialized\n");

	screen_w = 1024;
	screen_h = 1024;
	
	window = SDL_CreateWindow("Key Press Test", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, SDL_WINDOW_OPENGL );

	if( window == NULL ){
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create window: %s\n" , SDL_GetError());
	}
	
	running = true;


	
	cur_mode = LR_DEFAULT;

	// program main loop
	while(running){
		SDL_Event event;
		while( SDL_PollEvent(&event) ){
			if( event.type == SDL_QUIT){
				running = false;
				break;
			}
			
			else if( event.type == SDL_KEYDOWN ){
				switch( event.key.keysym.sym ){
					
					case SDLK_l:
						SDL_Log("L key pressed\n");
						update_mode(LR_LINKS);
						break;
					case SDLK_j:
						SDL_Log("J key pressed\n");					
						break;
					case SDLK_k:
						SDL_Log("K key pressed\n");	
						break;
					case SDLK_f:
						SDL_Log("F key pressed\n");	
						break;
					case SDLK_g:
						SDL_Log("G key pressed\n");
						break;
					case SDLK_SPACE:
						SDL_Log("Space key pressed");	
						update_mode(LR_URL);
						break;
					case SDLK_q:
						SDL_Log("Q key pressed\n");
						update_mode(LR_DEFAULT);
						break;	
					case SDLK_ESCAPE:
						running = false;
						break;
				}	
			
			}	
		}
	}
	


	SDL_DestroyWindow(window);
	SDL_Quit();
	printf("Process Complete, exiting \n");
	return 0;
	
}


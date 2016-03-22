#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
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
						break;
					case SDLK_q:
						SDL_Log("Q key pressed\n");
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


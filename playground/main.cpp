#include <SDL2/SDL.h>
#include "TextRenderer.h"
#include "DOMTreeBuilder.h"
#include "StreamBuilder.h"
#include "lex.yy.h"
#include <fstream>
#include <streambuf>
#include <string>
#include <iostream>
#include "globals.h"

bool cur_mode;
bool running;

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
	window = SDL_CreateWindow("LightningRod", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, screen_w, screen_h, (SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI ));

	if( window == NULL ){
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create window: %s\n" , SDL_GetError());
	}


	Uint32 render_flags = ( SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC); 

		
	renderer = SDL_CreateRenderer(window, -1, render_flags);
	if( renderer == NULL ){
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Failed to create renderer %s\n" , SDL_GetError());
	}
	


	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); 



	//TODO write a controller for user input
		
	// read in file to string 'file_str'
	std::ifstream t("example.html");
	std::string file_str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());

	std::ofstream outputfile;
	outputfile.open("trun_lexer_output.txt");
	// invoke lexer with the file string from above
 	YY_BUFFER_STATE cur_buff;
 	cur_buff = yy_scan_string(file_str.c_str());
	yylex();
	yy_delete_buffer(cur_buff);

	std::vector<Tag*> *tags = StreamBuilder::getInstance().getTruncatedStream();

	for(std::vector<Tag*>::iterator it = tags->begin(); 
			it != tags->end();
			++it){
		outputfile  << (*it)->toString() << std::endl;
	} 


	Tag* root = DOMTreeBuilder::buildTree(tags);

	texture = SDL_CreateTexture(renderer,
		       	SDL_PIXELFORMAT_RGBA8888,
		       	SDL_TEXTUREACCESS_TARGET,
		        screen_w,
			screen_h	);

	running = true;

	TextRenderer *r = new TextRenderer(renderer, screen_w, screen_h);
	r->walkTree(root);
	r->setMode(LR_DEFAULT);	
	// MAINLOOP
	int count = 0;
	while( running && count< 1 ){

		//TODO input handling
		SDL_Event event;
		while( SDL_PollEvent(&event) ){
			if( event.type == SDL_QUIT){
				running = false;
				break;
		
			}
			else if( event.type == SDL_KEYDOWN ){
			switch( event.key.keysym.sym ){
				
				case SDLK_q:
					SDL_Log("q key pressed\n");
					r->setMode(LR_DEFAULT);	
				break;	
				case SDLK_j:
					SDL_Log("j key pressed\n");
					r->shiftDown();
				break;	
				case SDLK_k:
					SDL_Log("k key pressed\n");
					r->shiftUp();
				break;
			
				case SDLK_l:
					SDL_Log("l key pressed\n");
					r->setMode(LR_LINKS);
				break;
		
				case SDLK_ESCAPE:
					running = false;
				break;	


				case SDLK_SPACE:
					SDL_Log("space bar pressed\n");
					r->setMode(LR_URL);
			}

			}	
		}	
		
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
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

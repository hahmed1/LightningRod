#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>
#include "Tag.h"
#include <utility>
typedef std::pair<int,int> ordererd_pair;
typedef std::pair<SDL_Texture* , ordererd_pair> smart_texture;
class TextRenderer{
	
	SDL_Renderer *renderer;
	SDL_Texture  *texture;
	SDL_Texture  *texture2;

		
	std::vector<smart_texture*> *surface_table;

	TTF_Font *font1;
	TTF_Font *font2;

	static const int font1_size = 20;
	static const int font2_size = 25;
	static const int break_size = 40;


	const SDL_Color col_green = {0x00, 0xFF, 0x00};
	const SDL_Color col_blue  = {0x00, 0x22, 0xFF};
	const SDL_Color col_mag   = {0xFF, 0x00, 0xFF};

	int screen_w;
	int screen_h;

	int img_w;
	int img_h;

	int img_w2;
	int img_h2;

	public:
		TextRenderer(SDL_Renderer *r, int w, int h);
		void renderCall();
		void walkTree(Tag *root);


};

#endif


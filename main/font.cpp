#include "font.h"

Font::Font(SDL_Texture *tex, SDL_Renderer *ren, TTF_Font *f, int sz )
{
	texture = tex;
	renderer = ren;
	font = f;
	size = sz;

	//set defaults
	rc = 0x00;
	gc = 0xFF;
	bc = 0x00;
	ac = 0xFF;

	bm = SDL_BLENDMODE_NONE;


}
bool Font::loadFromRenderedText(std::string text, SDL_Color c)
{
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), c );
	if( textSurface == NULL )
	{
		SDL_Log( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( renderer, textSurface );
		if( texture == NULL )
		{
			SDL_Log( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			iWidth = textSurface->w;
			iHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );

	
	}

	return texture != NULL;

}
void Font::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, iWidth, iHeight };
	SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}

void Font::free()
{
	if( texture != NULL )
	{
		SDL_DestroyTexture( texture);
		texture = NULL;
		iWidth = 0;
		iHeight = 0;
	}
}

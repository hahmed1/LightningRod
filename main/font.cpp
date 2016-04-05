#include "font.h"

Font::Font( SDL_Renderer *ren, TTF_Font *f   )
{
	renderer = ren;
	texture = NULL;
	font = f;	
	
	//set defaults

	iWidth = 0;
	iHeight = 0;

}
bool Font::loadFromRenderedText(std::string text, SDL_Color c)
{
	free();
	word = text;
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
		
			/*	
			SDL_Log("Width and height set\n");
			SDL_Log("Width: %d\n" , iWidth);
			SDL_Log("Height: %d\n" , iHeight);
			*/
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );

	
	}

	return texture != NULL;

}

int Font::getTextWidth()
{
	return iWidth;
}

int Font::getTextHeight()
{
	return iHeight;
}
void Font::render(int x, int y)
{
	SDL_Rect renderQuad = { x, y, iWidth , iHeight  };

	int val = SDL_RenderCopyEx( renderer, texture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
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

std::string Font::getWord()
{
	return word;
}

#include "SmartTexture.h"



SmartTexture::SmartTexture(int w, int h, SDL_Texture *t, bool b, std::string wo)
{
	width = w;
	height = h;
	texture = t;
	word = wo;
	_break = b;
}

bool SmartTexture::is_break()
{
	return _break;
}

SDL_Texture* SmartTexture::getTexture()
{
	return texture;
}

int SmartTexture::getWidth()
{
	return width;
}


int SmartTexture::getHeight()
{
	return height;
}

std::string SmartTexture::getWord()
{
	return word;
}
/*
bool SmartTexture::operator==(SmartTexture *rhs)
{
	if(word == rhs->getWord()){
		return true;
	}	

	else return false;
}
*/

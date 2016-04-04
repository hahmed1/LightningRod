#include "TextToken.h"

TextToken::TextToken(std::string w, unsigned int flags)
{
	word = w;

	//TODO based on the flags param, set
	//size, rc,gc,bc,ac, and font appropriately, 
	// the bools
}

std::string TextToken::toString()
{
	return word;

}

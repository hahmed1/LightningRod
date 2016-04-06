#include "TextToken.h"

/*
 * For the default constructor, assume a "line break" token
 *
 */
TextToken::TextToken()
{
	_break = true;
}
/* 
 * The flags are set by the tree_traversal algorithm in PageViewModel.
 *
 * It is up to this class to define the policy of what to do 
 * based on these flags.
 */

TextToken::TextToken(std::string w, unsigned int flags)
{
	word = w;
	
	// p branch

	_para = false;
	_heading = false;
	_link = false;
	_break = false;

	if( flags & para ){		
		_para = true; 
	}
	// link branch 
	if( flags & link){
		_link = true;

	}

	// heading branch 	
	if( flags & head ){
		_heading = true;	
	}	


}
/*
 * Mainly for testing purposes
 */
std::string TextToken::toString()
{
	std::string s;
	s.append("TextToken: \n");
	if( !is_break()){
		s.append(word);
		s.append("\n");

	}
	else{
		s.append("linebreak\n");
	}
	return s;
}

std::string TextToken::getWord()
{
	return word;
}

bool TextToken::is_para()
{
	return _para;
}
bool TextToken::is_heading()
{
	return _heading;
}
bool TextToken::is_link()
{
	return _link;
}

bool TextToken::is_break()
{
	return _break;
}



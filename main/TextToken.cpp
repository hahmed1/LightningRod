#include "TextToken.h"

/* 
 * The flags are set by the tree_traversal algorithm in PageViewModel.
 *
 * It is up to this class to define the policy of what to do 
 * based on these flags.
 */

TextToken::TextToken(std::string w, unsigned int flags)
{
	word = w;
	
	/*
	 * TODO finish this up
	 */

	// p branch
	//
	
	if( flags & para ){		
		size = 10; 	
		rc =   0x00;
		gc =   0xFF;
		bc =   0x00;
		ac =   0xFF;
		//font = 	
	}
	// link branch 
	if( flags & link){
	
		size = 10; 
	
	}

	// heading branch 	
	if( flags & head ){
		
		size = 20; 
	}	


}
/*
 * Mainly for testing purposes
 */
std::string TextToken::toString()
{
	std::string s;
	s.append("TextToken: \n");
	s.append(word);
	s.append("\n");
	s.append("Size: " + std::to_string(size));
	s.append("\n");
	return s;

}

std::string TextToken::getWord()
{
	return word;
}


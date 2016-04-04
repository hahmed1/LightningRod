#ifndef PAGEVIEWMODEL_H
#define PAGEVIEWMODEL_H
#include <vector>
#include "TextToken.h"
#include "TokenNode.h" 
#include <fstream>
/*
 * The purpose of this class is essentially just to encapsulate the 
 * algorithm that takes a TokenNode pointer (which reprsents the HTML
 * Document head node) and traverse the tree to make a text_stream, 
 * a stream of TextTokens which contain information about how things
 * (i.e. text) should be displayed.   
 *
 * PageView (which is a singleton) will have a reference to 1 
 * PageViewModel at any given point in time. 
 *
 * The algorithm, which is not part of the public interface, is top-down
 * tree traversal.  It sets various flags for non-leaf nodes and 
 * finally creates a TextToken object for leaf nodes (excluding images)
 * based on those flags.   
 */

class PageViewModel{
	
	std::vector<TextToken*> text_stream;
	void traverse_tree(TokenNode *node, unsigned int flags);



	// flags
	//  
	static const int para = 1 << 0;
	static const int link = 1 << 1;
	static const int head = 1 << 2;

	static const int para_link = para | link;



	public:
		PageViewModel(TokenNode *doc_head);
		
		void save(); // TODO: implement serialization-like mech

};

#endif

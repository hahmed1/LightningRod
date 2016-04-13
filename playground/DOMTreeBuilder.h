#ifndef DOMTREEBUILDER_H
#define DOMTREEBUILDER_H
#include "Tag.h"
#include <vector>
class DOMTreeBuilder{
	
	public:
		/*
		 * This function assumes you are giving it a 
		 * truncated stream, i.e. one starting with a 
		 * body tag
		 *
		 */
		static Tag* buildTree(std::vector<Tag*>*);
};

#endif

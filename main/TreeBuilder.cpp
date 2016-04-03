#include "TreeBuilder.h"

TreeBuilder::TreeBuilder()
{
	tokenStream = new std::vector<TokenNode*>();	
}


/*
 *  Tree construction algorithm implementation
 *
 */

//returns the root node of the tree

TokenNode* TreeBuilder::construct(std::vector<smart_token> tokens)
{
	//clear out the existing stream.
	tokenStream->clear();	


	// loop through the vector of smart tokens to create 
	// the TokenNode objects.  Add these objects to a new 
	// vector in 'queue' order.	
	for(std::vector<smart_token>::iterator it = tokens.begin(); it != tokens.end(); ++it){
		TokenNode *cur = new TokenNode(it->first.first, it->first.second, it->second);	
		tokenStream->push_back(cur);	
	}

	// Now that we are dealing with TokenNode objects 
	// rather than naked vectors, we create a stack 
	// for our parsing algorithm. 
	std::stack<TokenNode*> tmp;



	/*
	 * Parsing algorithm illustration: 
	 *
	 *   stream: 
	 *      * HTML (OPEN)
	 *      * BODY (OPEN)
	 *      * P    (OPEN)
	 *      * Text 
	 *      * P    (CLOSE)
	 *      * BODY (CLOSE)
	 *      * HTML (CLOSE)
	 *
	 *    stack:
	 *    
	 *    iteration 1: 
	 *		HTML (OPEN)
	 *    
	 *    iteration 2:
	 *    		BODY (OPEN)
	 *    		HTML (OPEN)
	 *    
	 *    iteration 3: 
	 *    		P    (OPEN)
	 *    		BODY (OPEN)
	 *    		HTML (OPEN)
	 *    
	 *    iteration 4: 
	 *    		Text 
	 *    		P    (OPEN)
	 *    		BODY (OPEN)
	 *    		HTML (OPEN)
	 *    
	 *    iteration 5:    		
	 *		P    (CLOSE)
	 * 		Text 
	 *    		P    (OPEN)
	 *    		BODY (OPEN)
	 *    		HTML (OPEN)
	 *    
	 *   We've hit the first close tag, so now we pop the stack and
	 *   add the elements onto a queue  like so:
	 *
	 *   queue: 
	 *   		Text
	 *   		P (OPEN) 
	 *   
	 *   At this point we've matched the close tag, so we make 
	 *   everything on the queue a child of the P element, and then
	 *   push the P back onto the original stack (with the newly 
	 *   added children):
	 *
	 *   stack:
	 *   		P    (internal) 
	 *   		BODY (OPEN)
	 *   		HTML (OPEN)
	 *  
	 *  internal means that it's an internal node.  Have to make
	 *  sure that isLeaf and isClose return true on this new P token.   
	 */

	for(std::vector<TokenNode*>::iterator it = tokenStream->begin(); it != tokenStream->end(); ++it){
		if(it->isClose()){
			std::string type = it->getType();	
			TokenNode* tmp;
			do{
				//TODO figure out
				tmp = 	
			} while (tmp->getType != type)
		}	
	}	
}

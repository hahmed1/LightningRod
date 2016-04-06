#include "TreeBuilder.h"
#include <iostream>
TreeBuilder::TreeBuilder()
{
	tokenStream = new std::vector<TokenNode*>();	
}


/*
 *  Tree construction algorithm implementation
 *
 */

//returns the root node of the tree

TokenNode* TreeBuilder::construct(std::vector<smart_token> *tok)
{
	//clear out the existing stream.
	tokenStream->clear();	

	std::vector<smart_token> tokens = *tok;
	

	// loop through the vector of smart tokens to create 
	// the TokenNode objects.  Add these objects to a new 
	// vector in 'queue' order.
	//
	for(std::vector<smart_token>::iterator it = tokens.begin(); it != tokens.end(); ++it){
		TokenNode *cur = new TokenNode(it->first.first, it->first.second, it->second);	
		tokenStream->push_back(cur);	

//		std::cout << *(cur->toString()) << std::endl;	
	}

	

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
	 *   add the elements onto another stack (so that text ordering is
	 *   preserved) like so:
	 
	 *   tmp__stack: 
	 *
	 *   		P (OPEN) 
	 * 		Text
	 *   
	 *   At this point we've matched the close tag, so we make 
	 *   everything on the tmp_stack a child of the P element, and then
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
	
	// Now that we are dealing with TokenNode objects 
	// rather than naked vectors, we create a stack 
	// for our parsing algorithm. 
	std::stack<TokenNode*> parse_stack;

	for(std::vector<TokenNode*>::iterator it = tokenStream->begin(); it != tokenStream->end(); ++it){

		//if the cur element is a close tag...	
				
		// note: 'it' ptr should remain constant for this
		// branch of code (per iteration).
		if((*it)->isClose()){
		
			//html tag type string	
			std::string type = (*it)->getType();
			
		
			// our temporary stack (see above)
			std::stack<TokenNode*> tmp_stack;


	 		TokenNode *next_ele;
		
			do{
			
				next_ele = parse_stack.top();	
				parse_stack.pop();	
				tmp_stack.push(next_ele);
	
		
			} while(next_ele->getType().compare(type) != 0);	
			TokenNode *tmp_head = next_ele;
			
			
			// by this point, tmp_stack contains all the 
			// children of the element

			TokenNode *ele_ptr; 
			
			// pop that sonofabitch to get past the head
			tmp_stack.pop();
			while(!tmp_stack.empty()){

				ele_ptr = tmp_stack.top();
				tmp_stack.pop();
				tmp_head->addChild(ele_ptr);
	
				// more logging
				/*	
				std::cout << "Adding child " << ele_ptr->getValue() << " to parent " << tmp_head->getValue() << std::endl;
			
			*/	
			} 
		
			parse_stack.push(tmp_head);
				
		
		}

		else{
			parse_stack.push(*it);			
		}	
	}

	return parse_stack.top();	

}












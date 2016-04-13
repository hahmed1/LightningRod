#include "DOMTreeBuilder.h"
#include "NonLeafTag.h"
#include <stack>
#include <iostream>
#include <fstream>
/*
 * Tag stream is root of the current tree
 *
 * stack is a stack of nonleaf nodes
 *
 * TODO: exception handling
 *
 */ 
/* HTML tag set:
 * 	*body   - the effective head node 
 *	*h1..h6 - headins
 *	*a      - anchor
 *	*ul/ol  - lists
 *	*li     - list elements
 *	*img    - images
 *	*p      - paragraphs
 *	*text   - raw text
 *
 *	everything is an immediate child of body, except:
 *	 *li    - child of either ol or ul
 *	 *text  - can be child of any of the other tags 
 *	          with the exception of img
 *    
 *       
 *
 */
Tag* DOMTreeBuilder::buildTree(std::vector<Tag*> *tag_stream )
{
	std::vector<Tag*>::iterator it = tag_stream->begin();
	Tag *root = *it;

	// get passed the head
	++it;


	std::ofstream logfile;
	logfile.open("tree-output.txt");
	
	// need a stack of internal nodes for text
	std::stack<Tag*> parents;
	parents.push(root);	
	/* 
	 * Loop invariant: the top of the 'parents' stack always
	 * points to the nearest internal node.  This is where 
	 * children TEXT nodes get added.  If we find a closing tag, 
	 * we pop the stack, and will never need to access that node
	 * again.  
	 *
	 */
	for(;
			it != tag_stream->end();
			it++ ){
	
		std::string cur_type = (*it)->getType();
		Tag *cur_par  = parents.top();
		
		// if text node, add it to the current parent
		if(cur_type == "TEXT"){
			cur_par->addChild(*it);				
			logfile << "Adding text node " << (*it)->getValue() << " to parent " << cur_par->getValue() << ". " << std::endl;	
		}

			
		
	
		// if we get past the above if statment, 
		// we can safely cast to a NonLeafTag type. 
		// BUT, this is ugly, and the class hierarchy 
		// is redundant. TODO: refactor 
		//
		// Anyways, for now, if the tag is an open tag, 
		// add it to the stack and it's parent becomes the
		// root (body) tag. 
		//
		//
		else if(((NonLeafTag *)*it)->is_opening()){
			root->addChild(*it);		
			parents.push(*it);
		
			logfile << "Adding node " << (*it)->getValue() << "to root." << std::endl; 
		}
		
		// for closing tags, just pop the stack. 
		else if(!(((NonLeafTag *)*it)->is_opening())){
			parents.pop();	
			logfile << "Encountered close tag " << (*it)->getValue() << " popping stack. " << std::endl; 	

		}	
	}


	return root;	
}







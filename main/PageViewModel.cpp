#include "PageViewModel.h"
#include <iostream>
//TODO test this with more elaborate trees to make sure that 
// things 'trickle down' as they should, and don't 'trickle down'
// as they shouldn't 
void PageViewModel::traverse_tree(TokenNode *node, unsigned int flags)
{
	/*
	 * base cases: leaf nodes
	 */

	if(node->isText()){
		text_stream.push_back(new TextToken(node->getValue(), flags));						
	}	

	//TODO handle image nodes
	
	
	
	// ---------------------------------	
	/*
	 * recursive case: non-leaf nodes
	 */	
	
	else{
		// handle flags
		// TODO: add whatever other flags we need
		std::string cur_type = node->getType();

		if(cur_type == "P"){
			flags = flags | para; 	
		}		

		else if (cur_type == "LINK"){
			flags = flags | link;
		}

		else if (cur_type == "H1"){
			flags = flags | head;
		}
		
		std::vector<TokenNode*> children = node->getChildren();

		for(std::vector<TokenNode*>::iterator it = children.begin();
			it != children.end(); 
			++it){
		
				traverse_tree(*it , flags);	
				//perhaps we enter a line-break here?
				
		}

		if(cur_type == "P" || cur_type == "H1"){
							
			text_stream.push_back(new TextToken());	
			//std::cout << "inside here" << std::endl;	
		}	
	
	}
	

}

PageViewModel::PageViewModel(TokenNode *doc_head)
{
	traverse_tree(doc_head, 0);	

}

//default constructor
PageViewModel::PageViewModel()
{

}


void PageViewModel::setDocument(TokenNode *doc_head)
{
	text_stream.clear();	
	traverse_tree(doc_head, 0);	
}

void PageViewModel::save()
{
	std::ofstream save_file;
	save_file.open ("PageViewModelSave.txt");


	for(std::vector<TextToken*>::iterator it = text_stream.begin();
			it != text_stream.end();
			++it){
	
		save_file << (*it)->toString();	
		save_file << "\n";
	}

	save_file.close();
}



std::vector<TextToken*> PageViewModel::get_text_stream()
{
	return text_stream;
}




#include "PageViewModel.h"


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

		if(cur_type == "paragraph"){
			flags = flags | para; 	
		}		

		else if (cur_type == "link"){
			flags = flags | link;
		}

		else if (cur_type == "heading"){
			flags = flags | head;
		}
		
		std::vector<TokenNode*> children = node->getChildren();

		for(std::vector<TokenNode*>::iterator it = children.begin();
				it != children.end(); 
				++it){
		
				traverse_tree(*it , flags);	
		}	
	
	}
	

}

PageViewModel::PageViewModel(TokenNode *doc_head)
{
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








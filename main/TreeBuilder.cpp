#include "TreeBuilder.h"

TreeBuilder::TreeBuilder()
{
	tokenStream = new std::vector<TokenNode*>();	
}

//returns the root node of the tree
//

TokenNode* TreeBuilder::construct(std::vector<token> tokens)
{
	tokenStream->clear();	
	
	for(std::vector<token>::iterator it = tokens.begin(); it != tokens.end(); ++it){
		TokenNode *cur = new TokenNode(it-> first, it->second);	
		tokenStream->push_back(cur);	
	}

	std::stack<TokenNode*> tmp;
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

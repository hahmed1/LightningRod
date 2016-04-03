#ifndef TREEBUILDER
#define TREEBUILDER
#include <vector>
#include <utility>
#include <string>
#include <stack>
#include "TokenNode.h"
typedef std::pair<std::string, std::string> token;

class TreeBuilder{

	std::vector<TokenNode*> *tokenStream;
	
	public:
		TreeBuilder();
		TokenNode* construct(std::vector<smart_token> tokens);			

};

#endif

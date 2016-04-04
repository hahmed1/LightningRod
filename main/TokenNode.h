#ifndef TOKENNODE
#define TOKENNODE
#include <string>
#include <vector>
#include "stream.h"
class TokenNode{
	std::string type;
	std::string value;
	int id;	
	std::vector<TokenNode*> children;

	public:
		TokenNode(std::string , std::string, int i);
		~TokenNode();
		void addChild(TokenNode* child);
		
		bool isLeaf();
		bool isClose();	
		std::string getType();
		std::string getValue();
		std::vector<TokenNode*> getChildren();
		std::string* toString();
};


#endif

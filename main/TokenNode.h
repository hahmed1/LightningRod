#ifndef TOKENNODE
#define TOKENNODE
#include <string>
#include <vector>
class TokenNode{
	std::string type;
	std::string value;
	
	std::vector<TokenNode*> children;

	public:
		TokenNode(std::string , std::string);
		~TokenNode();
		void addChild(TokenNode* child);
		
		bool isLeaf();
		bool isClose();	
		std::string getType();
};


#endif

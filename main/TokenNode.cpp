#include "TokenNode.h"

TokenNode::TokenNode(std::string t, std::string v)
{
	type = t;
	value = v;

}

TokenNode::~TokenNode()
{
	for(std::vector<TokenNode*>::iterator it = children.begin(); it != children.end();  ++it){
	
		delete *it;	
	}


}

void TokenNode::addChild(TokenNode* child)
{
	children.push_back(child);
}

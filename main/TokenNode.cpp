#include "TokenNode.h"

TokenNode::TokenNode(std::string t, std::string v, int i)
{
	type = t;
	value = v;
	id = i;
}

TokenNode::~TokenNode()
{
	for(std::vector<TokenNode*>::iterator it = children.begin(); it != children.end();  ++it){
	
		delete *it;	
	}


}

std::string getType()
{
	return type;
}


void TokenNode::addChild(TokenNode* child)
{
	children.push_back(child);
}


/*
 * Values dependent upon stream.h enum
 *
 */
bool isLeaf()
{
	return id == 2;	

}

bool isClose()
{
	return id == 1;	
}

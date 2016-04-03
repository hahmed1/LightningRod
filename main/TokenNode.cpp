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


/*
 * Here we introduce a strict dependency between the lexer module 
 * (i.e. the functions called by the FLEX lexer) and this file.  This
 * is fine so long as this dependency is localized between just these
 * two files.   
 *
 * The dependency is the naming convention used to identify tags. 
 *
 * We have opted to use string comparison to test whether a given token
 * is a leaf or is a closing tag.  
 * Here is the namng convention: 
 *
 * 
 *
 */
bool isLeaf()
{


}

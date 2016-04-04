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

std::string TokenNode::getType()
{
	return type;
}


void TokenNode::addChild(TokenNode* child)
{
	children.push_back(child);
}

std::vector<TokenNode*> TokenNode::getChildren()
{
	return children;
}	



bool TokenNode::isText(){
	return isLeaf() && (type == "TEXT");
}

/*
 * Values dependent upon stream.h enum
 *
 */


bool TokenNode::isLeaf()
{
	return id == 2;	

}

bool TokenNode::isClose()
{
	return id == 1;	
}

std::string TokenNode::getValue()
{
	return value;
}

std::string* TokenNode::toString()
{
	std::string *s = new std::string();
	s->append("Node Information: \n");
	s->append("Tag type : " + type + "\n");
	s->append("Tag value: " + value + "\n");
	s->append("Tag id: " +  std::to_string(id) + "\n");
	s->append("Num children: " + std::to_string(children.size()) + "\n");
	for(std::vector<TokenNode*>::iterator it = children.begin();
			it != children.end();
			++it){
		s->append( *((*it)->toString()) );	
	}
	return s;
}

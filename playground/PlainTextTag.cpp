#include "PlainTextTag.h"
#include <iostream>
#include <vector>
PlainTextTag::PlainTextTag(const char * val)
{
	value = std::string(val);
}

/*
 * Text tags are leafs, so this method should never be called.
 *
 * This subclasses Tag for polymorphism, so that the tree can have
 * all kinds of nodes, but there is probably a better solution
 *
 */
void PlainTextTag::addChild(Tag *t)
{
	std::cout << "Attempted to add child to leaf node" << std::endl;		
}

std::string PlainTextTag::getValue()
{
	return value;
}

std::string PlainTextTag::toString()
{
	std::string s("---------------------\n");
	s.append("plain text: " + value + "\n");
	return s;
}

std::string PlainTextTag::getType()
{
	return "TEXT";
}

std::vector<Tag*>* PlainTextTag::getChildren()
{
	//TODO throw error
	std::cout << "Fatal error occured" << std::endl;
	return nullptr;
}

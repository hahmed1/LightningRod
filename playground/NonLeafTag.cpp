#include "NonLeafTag.h"
#include <iostream>
NonLeafTag::NonLeafTag(const char *val, std::string t, bool o)
{
	value = std::string(val);
	type = t;
	open = o;
	children = new std::vector<Tag*>();
}

std::string NonLeafTag::getValue()
{
	return value;
}

void NonLeafTag::addChild(Tag *t)
{
	// TODO perhaps perform some validation on t
	children->push_back(t);
} 

std::string NonLeafTag::toString()
{
	std::string s("------------------\n");
	s.append("non leaf token: \n");
	s.append(value + "\n");
	s.append(type + "\n");

	if(open){
		s.append("open\n");
	} else {
		s.append("close\n");
	}


	return s;
}

std::string NonLeafTag::getType()
{
	return type;
}

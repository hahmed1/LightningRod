#include "StreamBuilder.h"
#include <iostream> 
StreamBuilder::StreamBuilder()
{
//	buffer = new std::vector<std::string>();
	buffer = new std::vector<Tag*>();
}

StreamBuilder& StreamBuilder::getInstance()
{
	static StreamBuilder instance;	

	return instance;
}
/*
void StreamBuilder::add(const char *text)
{
	std::string tmp(text);
	buffer->push_back("Tag found : " + tmp);
} */

void StreamBuilder::add(Tag *t)
{
	buffer->push_back(t);	

}

void StreamBuilder::clear()
{
	buffer->clear();
}


/*
 * Returns a stream with everything outside the body 
 * tag ignored
 *
 * The caller is responsible for calling delete when they 
 * are finished
 */
std::vector<Tag*>* StreamBuilder::getTruncatedStream()
{
	// make an iterator point to the body tag
	std::vector<Tag*>::iterator it = buffer->begin();
	while((*it)->getType().compare("BODY") != 0){
		++it;
	}

	std::vector<Tag*>* ret_val = new std::vector<Tag*>();
	
	for(; it != buffer->end(); ++it){
		ret_val->push_back(*it);
		// short circuit eval makes this not crash
		if((*it)->getType() == "BODY" && !(((NonLeafTag *)*it)->is_opening()))
			break;
	}

	return ret_val;


}


void StreamBuilder::writebuf( )
{
	for(std::vector<Tag*>::iterator it = buffer->begin();
			it != buffer->end();
			++it){
	
		std::cout << (*it)->toString()  << std::endl; 
	}

} 

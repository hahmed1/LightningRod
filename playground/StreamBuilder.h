#ifndef STREAMBUILDER_H
#define STREAMBUILDER_H
#include <string>
#include <vector>
#include "Tag.h"
#include "NonLeafTag.h"
#include "PlainTextTag.h"
/*
 * A singleton class used by the lexer. 
 *
 * Call clear() before loading a new page
 *
 *
 */
class StreamBuilder{
//	std::vector<std::string> *buffer;
	std::vector<Tag*> *buffer;
	static StreamBuilder *instance;
	StreamBuilder();
	StreamBuilder(StreamBuilder const&);
	void operator=(StreamBuilder const&);

	public:
	//	StreamBuilder();
		static StreamBuilder&  getInstance();	
//		void add(const char *);
		void add(Tag *t);
		void clear();	
		void writebuf();
		std::vector<Tag*>* getTruncatedStream();
};

#endif

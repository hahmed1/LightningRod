#ifndef PLAINTEXTTAG_H
#define PLAINTEXTTAG_H
#include "Tag.h"

class PlainTextTag : public Tag{
	

	public:
		PlainTextTag(const char *);
		void addChild(Tag *t);
		std::string getValue();
		std::string toString();
		std::string getType();
};


#endif

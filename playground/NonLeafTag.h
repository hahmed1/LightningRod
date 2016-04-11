#ifndef NONLEAFTAG_H
#define NONLEAFTAG_H
#include "Tag.h"
#include <vector>
#include <utility>

typedef std::pair<std::string , std::string> attribute;

class NonLeafTag : public Tag {
	std::vector<attribute> attributes;
	std::vector<Tag*> *children;	

	std::string type;
	bool open;
	public:
		NonLeafTag(const char * , std::string , bool );
		
		virtual std::string getValue();
		virtual void addChild(Tag *t);
		std::string toString();
		virtual std::string getType();
};


#endif

#ifndef NONLEAFTAG_H
#define NONLEAFTAG_H
#include "Tag.h"
#include <vector>
#include <utility>
#include <string>
typedef std::pair<std::string , std::string> attribute;

class NonLeafTag : public Tag {
	std::vector<attribute> attributes;
	std::vector<Tag*> *children;	

	std::string type;
	bool open;
	public:
		NonLeafTag(const char * , std::string , bool );
		
		std::string getValue();
		void addChild(Tag *t);
		std::string toString();
		std::string getType();
		bool is_opening();
		std::vector<Tag*>* getChildren();
		std::vector<std::string > getTextChildren();
		
};


#endif

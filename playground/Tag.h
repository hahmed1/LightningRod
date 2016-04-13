#ifndef TAG_H
#define TAG_H
#include <string>
#include <vector>
class Tag{
	protected:
	       	std::string value;

	public:
		virtual void addChild(Tag *t) = 0 ;
		virtual std::string getValue() = 0;
		virtual std::string toString() = 0;
		virtual std::string getType() = 0;
		virtual std::vector<Tag*> *getChildren() = 0;
		
};

#endif

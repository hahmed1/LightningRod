#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "StreamBuilder.h"
#include "lex.yy.h"
#include "DOMTreeBuilder.h"
#include <fstream>

void traverse(Tag* root)
{
	if(root == nullptr){
		std::cout << "null ptr encountered" << std::endl;
	}

	std::string type = root->getType();
	// base case
	if(root->getType() == "TEXT"){
		std::cout << root->getValue() << std::endl;
	}

	else{
		std::vector<Tag*> *children = root->getChildren();
		for(std::vector<Tag*>::iterator it = children->begin();
				it != children->end();
				++it){
			traverse(*it);
		}
	}	
}

int main()
{
	// read in file to string 'file_str'
	std::ifstream t("example.html");
	std::string file_str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());

	std::ofstream outputfile;
	outputfile.open("trun_lexer_output.txt");
	// invoke lexer with the file string from above
 	YY_BUFFER_STATE cur_buff;
 	cur_buff = yy_scan_string(file_str.c_str());
	yylex();
	yy_delete_buffer(cur_buff);

	std::vector<Tag*> *tags = StreamBuilder::getInstance().getTruncatedStream();

	for(std::vector<Tag*>::iterator it = tags->begin(); 
			it != tags->end();
			++it){
		outputfile  << (*it)->toString() << std::endl;
	} 

		
	Tag* root = DOMTreeBuilder::buildTree(tags);


	/* tree traversal */
//	traverse(root);	



	/*
	 * This kind of traversal only works if there are 
	 * no list elements!
	 *
	 */
	std::vector<Tag*> *children = root->getChildren();
	for(std::vector<Tag*>::iterator it = children->begin();
			it != children->end();
			++it){
		std::cout << "Cur internal node: " << (*it)->getValue() << std::endl;
		NonLeafTag *cur = (NonLeafTag *)*it;
		std::vector<std::string> text = cur->getTextChildren();
		for(std::vector<std::string>::iterator ut = text.begin();
				ut != text.end();
				++ut){
		
			std::cout << *ut << " ";
		}

		std::cout << std::endl;
		std::cout << "----------" << std::endl;
	}	




}

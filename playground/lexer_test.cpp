#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "StreamBuilder.h"
#include "lex.yy.h"
int main()
{
	// read in file to string 'file_str'
	std::ifstream t("example.html");
	std::string file_str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());


	// invoke lexer with the file string from above
 	YY_BUFFER_STATE cur_buff;
 	cur_buff = yy_scan_string(file_str.c_str());
	yylex();
	yy_delete_buffer(cur_buff);

	std::vector<Tag*> *tags = StreamBuilder::getInstance().getTruncatedStream();

	for(std::vector<Tag*>::iterator it = tags->begin(); 
			it != tags->end();
			++it){
		std::cout << (*it)->toString() << std::endl;
	}

	/* StreamBuilder class test */	
	//StreamBuilder st_in = StreamBuilder::getInstance();


//	StreamBuilder::getInstance().add("hello, wolrd");
//	StreamBuilder::getInstance().add("this is some text");
//	StreamBuilder::getInstance().writebuf();
//	StreamBuilder::getInstance().clear();
}

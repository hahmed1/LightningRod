#include "lexer.lex.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "stream.h"
#include "TreeBuilder.h"
#include "TokenNode.h"
#include "PageViewModel.h"
std::string semantic_print(int id)
{
	if(id == OPEN){
		return "open";
	}

	else if (id == CLOSE){
		return "close";
	}	

	else if (id == LEAF){
		return "leaf";
	}

	else return "error";

}



int main()
{
	//Test setup: give it an HTML file	
	std::ifstream t("sample.html");
	std::string file_str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());


	// initialize treebuilder	
	TreeBuilder *builder = new TreeBuilder();
	TokenNode *head_node;
	
	//initialize stream TODO: make a namespace or something
	initialize();

	// invoke lexer
 	YY_BUFFER_STATE cur_buff;
 	cur_buff = yy_scan_string(file_str.c_str());
	yylex();
	yy_delete_buffer(cur_buff);
	
	// get the stream and pass the head node to the builder
	std::vector<smart_token> *sm_token_stream = get_smart_stream();
	head_node = builder->construct(sm_token_stream);

	// to string test on builder	
	//	std::cout << *head_node->toString() << std::endl;

	// PageViewModel Test
	PageViewModel *pvm = new PageViewModel(head_node);
	
	// write the doc to a file
	pvm->save();


	// cleanup 	
	delete head_node;
	delete pvm;
	clean_up();
}


#include "stream.h"
#include <iostream>
#include <fstream>
/*
 * use with caution. needs testing
 *
 *
 * C style C++ (wanted pair, vector, string)
 */
std::ofstream *out_file;
std::vector<token> *html_stream;
void initialize()
{
	html_stream = new std::vector<token>();
	out_file = new std::ofstream("lex_output.txt" , std::ofstream::out);
}

void clear()
{
	html_stream->clear();
}


void add(std::string tag, std::string value)
{
	
	token tmp(tag, value);
	html_stream->push_back(tmp);

	*out_file << "--------------------\n";
	*out_file << tag << std::endl;
	*out_file << value << std::endl;

}

void clean_up()
{
	delete html_stream;
}

void print()
{
	for(std::vector<token>::iterator it = html_stream->begin(); it != html_stream->end(); ++it){
		std::cout << it->second << std::endl;
	}
}

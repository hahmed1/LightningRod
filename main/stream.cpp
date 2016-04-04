#include "stream.h"
#include <iostream>
#include <fstream>
/*
 * use with caution. needs testing
 *
 *
 * C style C++ (wanted pair, vector, string)
 */


//Globals

// The file to write to for logging purposes

std::ofstream *out_file;

//should be deprecated
//std::vector<token> *html_stream;

//the actual stream to use
std::vector<smart_token> *smart_stream;


void initialize()
{
//	html_stream = new std::vector<token>();
	smart_stream = new std::vector<smart_token>();

	out_file = new std::ofstream("lex_output.txt" , std::ofstream::out);
}

void clear()
{
//	html_stream->clear();
	smart_stream->clear();
}

/* 
 * Deprecate
 *
 * TODO remove
 */
/*
void add(std::string tag, std::string value)
{
	
	token tmp(tag, value);
	html_stream->push_back(tmp);

	*out_file << "--------------------\n";
	*out_file << tag << std::endl;
	*out_file << value << std::endl;

} */

/*
 * Smart tokens contain information so that no string comparison 
 * is needed to get token information. 
 *
 * The valid values for the added int field are the ones defined in the 
 * TOKEN_TYPE enum: OPEN, CLOSE, LEAF.
 */

void add(std::string tag, std::string value, int id)
{
	token tmp(tag , value);
	smart_token sm_tmp(tmp, id);

	smart_stream->push_back(sm_tmp);

	*out_file << "------------------\n";
	*out_file << "tag: " << tag << std::endl;
	*out_file << "value: " << value << std::endl;
	*out_file << "id: " << id << std::endl;
}

void clean_up()
{
//	delete html_stream;
	delete smart_stream;
}

/* Deprecated
 *
 */
/*
void print()
{
	for(std::vector<token>::iterator it = html_stream->begin(); it != html_stream->end(); ++it){
		std::cout << it->second << std::endl;
	}
}
*/
void smart_print()
{
	for(std::vector<smart_token>::iterator it = smart_stream->begin(); it != smart_stream->end(); ++it){
		std::cout << it->first.second << std::endl;
	}


}

/*
 * Deprecated, use smart stream
 *
 */
/*
std::vector<token>* get_stream()
{
	return html_stream;
}
*/
std::vector<smart_token>* get_smart_stream()
{
	return smart_stream;

}



#ifndef STREAM_H
#define STREAM_H
#include <string>
#include <vector>
#include <utility>
/*
 * The set of functions called by the flex lexer module
 *
 */

enum TOKEN_TYPE{
	OPEN, 
	CLOSE, 
	LEAF
};


typedef std::pair<std::string , std::string> token;
typedef std::pair<token, int> smart_token;
void initialize();
void add(std::string tag, std::string value);
void add(std::string tag, std::string value, int id);
void print();
void smart_print();
void clear();
void clean_up();
std::vector<token>* get_stream();
std::vector<smart_token>* get_smart_stream();
#endif

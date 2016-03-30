#ifndef STREAM_H
#define STREAM_H
#include <string>
#include <vector>
#include <utility>
/*
 * The set of functions called by the flex lexer module
 *
 */

typedef std::pair<std::string , std::string> token;

void initialize();
void add(std::string tag, std::string value);
void print();
void clear();
void clean_up();
std::vector<token>* get_stream();
#endif

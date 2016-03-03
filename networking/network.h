#ifndef NETWORK_H
#define NETWORK_H
#include <stdlib.h>
/*
 *	To use the interface, first call net_initialize();
 *	
 *	Get the HTML webpage using net_get
 *	You are responsible for calling free() on the returned buffer
 * 	Check that the return value is not "EERROR"
 *
 * 	Call net_cleanup() before exiting.  
 *
 *  
 */



void net_initialize();
char *net_get(char *url, size_t *size);
void net_cleanup();


#endif

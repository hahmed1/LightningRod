#ifndef NETWORK_H 
#define NETWORK_H 
/* lookup.h
 *  
 * **************************************
 * *		LightningRod       	*
 * *		Network Module 		*
 * **************************************
 * 
 * This is the interface to the networking module used by the LightningRod browser.   
 *
 * Usage:
 *   
 * Last Modified:
 * 2/25/16
 *
 */

//TODO see which of these can be deleted
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int get(char *domain, char *resource, char *result); 

#define ADDR_NOT_FOUND  -1


#endif

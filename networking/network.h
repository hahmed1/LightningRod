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
 *   int find(const char *name, struct address *head) performs the DNS lookup of the domain 
 *   name 'name'.  The resulting linked list of sockaddr's is then copied to head.
 *   Returns ADDR_NOT_FOUND if the given address could not be found and 0 otherwise.
 *
 *
 *   int simple_find(const char *name, char *address) performs a DNS lookup of the domain 
 *   name 'name' and returns the first IPv4 result in 'address' as a string.
 *   Returns ADDR_NOT_FOUND if the given address could not be found and 0 otherwise.
 *
 * Last Modified:
 * 2/7/16
 *
 */

//TODO see which of these can be deleted
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#define ADDR_NOT_FOUND  -1

// A LL of sockaddr's
struct address{
	struct sockaddr;
	struct address *next;
};

int find(const char *name, struct address *head);
int simple_find(const char *name, char *address);

#endif

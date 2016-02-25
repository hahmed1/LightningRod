#include <string.h>
#include <stdio.h>
#include "network.h"
/*
 * URL processing
 *
 * Here we deine a function that when given a char* representing a URL string returns, in the pass-by-reference arguments
 * *base and *resource the corresponding base URL and specific resource of the URL string.
 *
 * For example, 
 *
 * www.foo.com/bar/ => base = "www.foo.com" , resource = "/bar/"
 *
 * returns 0 upon succes and -1 otherwise
 */


/*
 * Be careful, this function has very strict preconditions.
 *
 * Base and resource must be large enough to hold their respective contents.
 * To be safe, declare them both as char[SUF_LARGE] where SUF_LARGE >= ~100 
 *
 */
int url_parse(char *url, char *base, char *resource)
{
	
	char *c  ;
        int size ;	
	int i    ;
	int index;	
	
	c = NULL;
	size = strlen(url);
	i = 0;

	/* Clear out any garbage */
	memset(base , 0, sizeof(*base));
	memset(resource, 0, sizeof(*resource));
	
	char *stop= strchr(url , '/');
	index = stop - url;

	if(index < 0){
		strcpy(base , url);
		strcpy(resource, "/");
	}

	else{
		
		strncpy(base, url, index);
		base[index] = '\0';
		strcpy(resource, &url[index]);	

	}
	return 0;
}



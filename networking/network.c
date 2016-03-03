#include <stdlib.h>
#include <string.h>
#include "network.h"
#include <curl/curl.h>

//TODO Check for memory leaks

/*
 * Implementation of the network interface
 *
 */

/*
 * Globals
 */
static CURL *curl_handle;
static CURLcode res;

/*
 * A resizable memory chunk.  
 *
 * See example at https://curl.haxx.se/libcurl/c/getinmemory.html
 *
 */  

struct MemoryStruct {
	char *memory;
	size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	 size_t realsize = size * nmemb;
         struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	 mem->memory = realloc(mem->memory, mem->size + realsize + 1);
	 if(mem->memory == NULL) {
	    /* out of memory! */
	    printf("not enough memory (realloc returned NULL)\n");
	    return 0;
	 }

	 memcpy(&(mem->memory[mem->size]), contents, realsize);
	 mem->size += realsize;
	 mem->memory[mem->size] = 0;

	 return realsize;
}

void net_initialize()
{
	 curl_global_init(CURL_GLOBAL_ALL);

	 /* init the curl session */
	 curl_handle = curl_easy_init();
	 
	 /* Handle redirects */
	 curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
	 /* some servers don't like requests that are made without a user-agent
     	  field, so we provide one */
          curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");


}

static void net_seturl(char * url)
{
	
 	 /* specify URL to get */
     	 curl_easy_setopt(curl_handle, CURLOPT_URL, url);
}

char *net_get(char *url, size_t *size)
{
//  	  initialize();
	  net_seturl(url);
 
 	  struct MemoryStruct chunk;

	  chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
	  chunk.size = 0;    /* no data at this point */


	 
       	  /* send all data to this function  */
	  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

   	  /* we pass our 'chunk' struct to the callback function */
	  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

          	  /* get it! */
	  res = curl_easy_perform(curl_handle);

	  /* check for errors */
  	  if(res != CURLE_OK) {
 	  	fprintf(stderr, "curl_easy_perform() failed: %s\n",
	        curl_easy_strerror(res));
	  }
	  else {
	        /*
		 *      * Now, our chunk.memory points to a memory block that is chunk.size
		 *      * bytes big and contains the remote file.
		 *      * Do something nice with it!
		 *                          */

		//printf("%lu bytes retrieved\n", (long)chunk.size);
		//printf("Data: %s\n" , chunk.memory);		 
	  
	  	//memcpy(output, chunk.memory, chunk.size + 1);
	  	int bsize = chunk.size;
		char *buff = (char *)malloc(bsize);
		*size = bsize;  
		//buff = chunk.memory;
		memcpy(buff, chunk.memory, bsize);
		free(chunk.memory);
		return buff;
	  }

	  
	  return "EERROR";

}

void net_cleanup()
{
	/* cleanup curl stuff */
        curl_easy_cleanup(curl_handle);

	/* we're done with libcurl, so clean it up */
  	curl_global_cleanup();


}
#ifdef STANDALONE_TEST
#include <stdio.h>
int main(int argc , char **argv)
{
	
	char *data; 
	size_t size;
	char *url;
	
	if(argc != 2){
		printf("Usage: %s  url\n" , argv[0]);
		exit(1);
	}

	net_initialize();
	url = argv[1];		

	
	data =  net_get(url, &size);
	printf("Size: %zu\n" , size );
	printf("BEGIN DATA: %s\n" , data);
	

	free(data);	
	net_cleanup();	
}
#endif

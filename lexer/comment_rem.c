#include "comment_rem.h"
#include <stdlib.h>
#include <string.h>

/* Helper function
 *
 * Takes a FILE stream and returns a char* with the file  
 * contents.
 *
 *
 */


char* get_file_string(FILE* html_file , long* length)
{
	char* buffer = 0;
	long len;
	if(html_file)
	{
		fseek(html_file, 0, SEEK_END);
		len = ftell(html_file);
		fseek(html_file, 0, SEEK_SET);
		buffer = malloc(len);

		if(buffer)
		{
			fread(buffer, 1, len, html_file);
		}

	}
	
	*length = len;
	return buffer;
}



/* The implementation of the comment_rem interface 
 *
 *
 */

char* remove_comments(FILE* html_file)
{
	long len;
	char* html = get_file_string(html_file, &len);
	
	return scrub(html, len);
	
}




/*      Another helper function. 
 *       
 *	Recursively removes comments from the char* passed.
 *
 * 	TODO As of now, this likely leaks memory!
 *
 */ 
 

char* scrub( char* html_file, long length) 
{
	char* start_key = "<!--";
	char* end_key   = "-->";
	
	char* comment_begin = strstr(html_file, start_key);
	
	//Nothing to do
	if(comment_begin == NULL)
		return html_file;

	else
	{
		char* comment_end = strstr(html_file, end_key);

		// Points arithmetic ! 
		long index1 = comment_begin - html_file ;
		long index2 = comment_end   - html_file + 1;

		// Longer than necessary
		char* substr1[length];
		char* substr2[length];

		strncpy(substr1, html_file, index1);
		
		// to filter out the tag itself, offset by 3
		strcpy(substr2, &html_file[index2 + 3]);
		
		char* str = malloc(length);
		str[0] = '\0';

		strcat(str, substr1);
		strcat(str, substr2);		

		return scrub(str, length);	
	}	

}



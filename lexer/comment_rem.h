#ifndef COMMENT_REM_H
#define COMMENT_REM_H
#include <stdio.h>

/*
 * ************************************************************
 * 	An interface consisting of one function that removes
 * 	comments from an HTML file.
 *
 * ***********************************************************		
 */


/*
 * Included here for testing purposes
 *
 */

char* get_file_string(FILE* html_file, long* length);
char* scrub(char* html_file, long length);


/*
 * ************************************************************
 * 			PUBLIC INTERFACE
 * ***********************************************************		
 */



/*
 * The caller is responsible for:
 *
 * *fclose()ing the html_file
 * *free()ing the char* returned
 *
 *
 */
char* remove_comments(FILE* html_file);
#endif

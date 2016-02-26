/*
* Parse up that response header
*
*/

%{
#include "network.h"
#include <stdio.h>
%}

%%
Content-Length:[ ]*[0-9]+			get_num(yytext); 
\<!doctype\ html\>[^\0]*			get_html(yytext);	
%%

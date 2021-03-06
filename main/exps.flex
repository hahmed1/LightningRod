%{
#include "stream.h"
%}

%%
\<!--[^\0]*--\>	
\<base[^>]*\>
\<\/base\>
\<style[^>]*\>
\<\/style\>
\<title[^>]*\>
\<\/title\>
\<address[^>]*\>
\<\/address\>
\<article[^>]*\>
\<\/article\>
\<footer[^>]*\>
\<\/footer\>
\<header[^>]*\>
\<\/header\>
\<hgroup[^>]*\>
\<\/hgroup\>
\<nav[^>]*\>
\<\/nav\>
\<section[^>]*\>
\<\/section\>
\<dd[^>]*\>
\<\/dd\>
\<div[^>]*\>			
\<\/div.*\>		
\<dl[^>]*\>
\<\/dl\>
\<dt[^>]*\>
\<\/dt\>
\<figcaption[^>]*\>
\<\/figcaption\>
\<figure[^>]*\>
\<\/figure\>
\<hr[^>]*\>
\<\/hr\>
\<li[^>]*\>
\<\/li\>
\<main[^>]*\>
\<\/main\>
\<ol[^>]*\>
\<\/ol\>
\<pre\>
\<\/pre\>
\<ul\>
\<\/ul\>
\<abbr\>
\<\/abbr\>
\<b\>
\<\/b\>
\<bdi\>
\<\/bdi\>
\<bdo\>
\<\/bdo\>
\<br\>
\<\/br\>
\<cite\>
\<\/cite\>
\<code\>
\<\/code\>
\<data\>
\<\/data\>
\<dfn\>
\<\/dfn\>
\<em\>
\<\/em\>
\<i\>
\<\/i\>
\<kbd\>
\<\/kbd\>
\<mark\>
\<\/mark\>
\<q\>
\<\/q\>
\<rp\>
\<\/rp\>
\<rt\>
\<\/rt\>
\<rtc\>
\<\/rtc\>
\<ruby\>
\<\/ruby\>
\<s\>
\<\/s\>
\<samp\>
\<\/samp\>
\<small\>
\<\/small\>
\<span\>
\<\/span\>
\<strong\>
\<\/strong\>
\<sub\>
\<\/sub\>
\<sup\>
\<\/sup\>
\<time\>
\<\/time\>
\<u\>
\<\/u\>
\<var\>
\<\/var\>
\<wbr\>
\<\/wbr\>
\<area\>
\<\/area\>
\<audio\>
\<\/audio\>
\<map\>
\<\/map\>
\<track\>
\<\/track\>
\<video\>
\<\/video\>
\<embed\>
\<\/embed\>
\<object\>
\<\/object\>
\<param\>
\<\/param\>
\<source\>
\<\/source\>
\<canvas\>
\<\/canvas\>
\<noscript\>
\<\/noscript\>
\<script[^>]*\>[^\0]*\<\/script\>	
\<del\>
\<\/del\>
\<ins\>
\<\/ins\>
\<caption\>
\<\/caption\>
\<col\>
\<\/col\>
\<colgroup\>
\<\/colgroup\>
\<table\>
\<\/table\>
\<tbody\>
\<\/tbody\>
\<td\>
\<\/td\>
\<tfoot\>
\<\/tfoot\>
\<th\>
\<\/th\>
\<thead\>
\<\/thead\>
\<tr\>
\<\/tr\>
\<button\>
\<\/button\>
\<datalist\>
\<\/datalist\>
\<fieldset\>
\<\/fieldset\>
\<form\>
\<\/form\>
\<input\>
\<\/input\>
\<keygen\>
\<\/keygen\>
\<label\>
\<\/label\>
\<legend\>
\<\/legend\>
\<meter\>
\<\/meter\>
\<optgroup\>
\<\/optgroup\>
\<option\>
\<\/option\>
\<output\>
\<\/output\>
\<progress\>
\<\/progress\>
\<select\>
\<\/select\>
\<details\>
\<\/details\>
\<dialog\>
\<\/dialog\>
\<menu\>
\<\/menu\>
\<menuitem\>
\<\/menuitem\>
\<summery\>
\<\/summery\>
\<content\>
\<\/content\>
\<element\>
\<\/element\>
\<shadow\>
\<\/shadow\>
\<template\>
\<\/template\>
\<!doctype\ html\>
\<!DOCTYPE\ html\>
\<meta[^>]*\>
\<\/meta\>
\<head\>
\<\/head\>
\<html\>			  add("HTML" , yytext, 0);
\<\/html\>			  add("HTML" , yytext, 1);	
\<h1[^>]*>			  add("H1" , yytext, 0);
\<\/h1\>		          add("H1" , yytext, 1);
\<p[^>]*\> 			  add("P" , yytext, 0);
\<\/p\> 			  add("P", yytext, 1);
\<body[^>]*\>			  add("BODY", yytext, 0);
\<\/body\> 			  add("BODY", yytext, 1);
[[:alnum:]\?;\.!@#$%\^&\*\\\=]+   add("TEXT" , yytext, 2);
\<h2[^>]*\>			  add("H1" , yytext, 0);
\<\/h2\> 			  add("H1" , yytext, 1);
\<h3[^>]*\>			  add("H1" , yytext, 0);	
\<\/h3\> 			  add("H1" , yytext, 1);
\<h4[^>]*\> 		          add("H1" , yytext, 0);
\<\/h4\> 		    	  add("H1" , yytext, 1);
\<h5[^>]*\> 			  add("H1" , yytext, 0);
\<\/h5\>                          add("H1" , yytext, 1);
\<h6[^>]*\> 		    	  add("H1" , yytext, 0);
\<\/h6\> 		          add("H1" , yytext, 1);
%%



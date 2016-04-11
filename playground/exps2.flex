%{
#include "StreamBuilder.h"
#include "Tag.h"
#include "NonLeafTag.h"
#include "PlainTextTag.h"
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
\<html\>			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HTML",    true));
\<\/html\>			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HTML",    false));
\<h1[^>]*>			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true));
\<\/h1\>		          StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false));
\<p[^>]*\> 		 	  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "PARA",    true));
\<\/p\> 			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "PARA",    false));
\<body[^>]*\>		          StreamBuilder::getInstance().add(new NonLeafTag(yytext, "BODY",    true));	
\<\/body\> 			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "BODY",    false));
[[:alnum:]\?;\.!@#$%\^&\*\\\=]+   StreamBuilder::getInstance().add(new PlainTextTag(yytext));
\<h2[^>]*\>			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true));
\<\/h2\> 			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false));
\<h3[^>]*\>			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true));
\<\/h3\> 			  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADIND", false));
\<h4[^>]*\> 		          StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true));
\<\/h4\> 		    	  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false));
\<h5[^>]*\> 		          StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true));
\<\/h5\>                          StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<h6[^>]*\> 		    	  StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h6\> 		          StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
%%



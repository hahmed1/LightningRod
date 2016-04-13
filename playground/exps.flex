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
\<main[^>]*\>
\<\/main\>
\<pre[^>]*\>
\<\/pre\>
\<abbr\>
\<\/abbr\>
\<b\>
\<\/b\>
\<bdi\>
\<\/bdi\>
\<bdo\>
\<\/bdo\>
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
\<ul[^>]*\>			 
\<\/ul\> 	  		
\<ol[^>]*\>		
\<\/ol\>	
\<head\>
\<html\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HTML",    true));
\<\/html\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HTML",    false));
\<body[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "BODY",    true));
\<\/body> 		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "BODY",    false));	
\<h1[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h1\>		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<h2[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h2\>		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<h3[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h3\>		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<h4[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h4\>		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<h5[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h5\>		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<h6[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", true)); 
\<\/h6\>		         StreamBuilder::getInstance().add(new NonLeafTag(yytext, "HEADING", false)); 
\<li[^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "LISTELE", true));
\<\/li\> 			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "LISTELE", false));
\<br\> 				 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "BREAK",   true));
\<br\/\> 			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "BREAK",   true));
\<a\ [^>]*\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "LINK",    true));
\<\/a\> 			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "LINK",    false));
\<img[^>]*\> 			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "IMG",     true));
\<\/img\>			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "IMG",     false));
\<p[^>]*\> 			 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "PARA",    true));
\<\/p\>				 StreamBuilder::getInstance().add(new NonLeafTag(yytext, "PARA",    false)); 
[[:alnum:]\?;\.!@#$%\^&\*\\\=,]+ StreamBuilder::getInstance().add(new PlainTextTag(yytext));



%%

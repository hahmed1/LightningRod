#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "parser.h" 
#define MSG_LEN 1000
#define BUF_SIZE 10000

int content_size;
int html_len;
static void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void get_num(char *text)
{
	char *stop;
	char c;
	int i;

	char number[BUF_SIZE];
	for(i = 0; i < strlen(text); ++i){
		c = text[i];
		if(c == ':')
			break;

	}
	++i;

	
	if(strlen(&text[i]) < BUF_SIZE){
		strcpy(number , &text[i]);	
		content_size = atoi(number);
	}
	
	printf("content size: %d\n" , content_size);
}

void get_html(char *text)
{
	html_len = strlen(text);
	printf("html len: %d\n" , html_len );
}
static void check_buffer(char *buffer, int recvd)
{

	YY_BUFFER_STATE cur_buff;
	cur_buff = yy_scan_string(buffer);

	content_size = 0;	
	yylex();
	if(content_size <= 0){
		printf("ERROR\n");	
	}
	else{
		if(html_len < content_size){
			printf("INCOMPLETE READ\n");	
		}
	}
	yy_delete_buffer(cur_buff);	

}

static void recv_data(int sock )
{
	int recvd;
	char buffer[BUF_SIZE];
	recvd = recv(sock, buffer, sizeof buffer, 0);
	printf("Size: %ld\n" , sizeof buffer);
	printf("receieved %d\n", recvd);
	check_buffer(buffer , recvd);		
	
	printf("%s\n" , buffer);
}

int get(char *domain, char *resource, char *result)
{
	int status, sockfd;
	struct addrinfo hints,   *res;
	size_t sent, recvd;	


	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; 
	hints.ai_socktype = SOCK_STREAM;
	
	 
	if((status = getaddrinfo(domain, "http", &hints, &res )) != 0 ){
		fprintf(stderr, "getaddrinfo: %s\n" , gai_strerror(status));
         	return 1;
	}

	for(; res != NULL; res = res->ai_next){
		if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1){
			fprintf(stderr, "socket error: %s\n" , strerror(errno));
			continue;
		}
		if(connect(sockfd, res->ai_addr, res->ai_addrlen) == -1){
			close(sockfd);
			fprintf(stderr, "failed to create connection: %s\n" , strerror(errno));	
			fprintf(stderr, "errno: %d\n" , errno);
			continue;
		}	

		break;
	}
	if(res == NULL){
		fprintf(stderr, "no valid addresses found\n");
		return 1;
	}
	puts("Connection success");
	char s[INET6_ADDRSTRLEN];
	inet_ntop(res->ai_family, get_in_addr((struct sockaddr *)res->ai_addr), s, sizeof s);
	printf("connection to %s\n" , s);
	
	/*
	 * Create a valid HTTP GET request
	 *
	 */
	
//	char bbuff[BUF_SIZE] = {0};
	char output[BUF_SIZE] = {0};
	char msg[1000] = {0};
	strcat(msg,  "\r\n\r\nGET / HTTP/1.1\r\nHost: ");
	strcat(msg, domain);
	strcat(msg, "\r\n\r\n");	
	
	printf("Message:\n%s\n", msg);
	sent = send(sockfd, msg, strlen(msg), 0);
	printf("%zu of %lu bytes sent\n" , sent ,strlen(msg));
//	recvd = recv(sockfd, bbuff, sizeof bbuff, 0);
	recv_data(sockfd);	

	//TODO parse header to get Content-Length to see if all data sent

	/*
	if(recvd)
		printf("%zu of %lu bytes recieved\n", recvd , sizeof bbuff);	
	else
		printf("Conection dropped unexpectedly\n");
	*/
		
//	printf("Buffer : %s\n" , bbuff);	
	freeaddrinfo(res);
	close(sockfd);	

	return 0;
}


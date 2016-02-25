#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MSG_LEN 1000
#define BUF_SIZE 10000
static void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
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
	
	char bbuff[BUF_SIZE] = {0};
	char output[BUF_SIZE] = {0};
	char msg[1000] = {0};
	strcat(msg,  "\r\n\r\nGET / HTTP/1.1\r\nHost: ");
	strcat(msg, domain);
	strcat(msg, "\r\n\r\n");	
	
	printf("Message:\n%s\n", msg);
	sent = send(sockfd, msg, strlen(msg), 0);
	printf("%zu of %lu bytes sent\n" , sent ,strlen(msg));
	recvd = recv(sockfd, bbuff, sizeof bbuff, 0);
	int total = 0;
	
	
	//TODO parse header to get Content-Length to see if all data sent


	if(recvd)
		printf("%zu of %lu bytes recieved\n", recvd , sizeof bbuff);	
	else
		printf("Conection dropped unexpectedly\n");
	printf("%s\n" , bbuff);
	freeaddrinfo(res);
	close(sockfd);	

	return 0;
}


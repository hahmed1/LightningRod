#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>



/* Perform a DNS lookup of argv[1],
 * make a socket,  
 * establish a TCP connection,
 * Send an HTTP GET req
 */

#define MSG_LEN 500
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main(int argc, char **argv)
{
	int status, sockfd;
	struct addrinfo hints,   *res;
	char *domain;
	char *msg , *buffer;
	size_t sent, recvd;	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; //TODO inspect
	hints.ai_socktype = SOCK_STREAM;
	
	/*
	if(argc != 2){
		fprintf(stderr, "Usage: %s <domain-name>", argv[0]);
		return 1;
	} */
	
	domain = "www.example.com";	
	//domain = argv[1];

	if((status = getaddrinfo(domain, "http", &hints, &res )) != 0 ){
		fprintf(stderr, "getaddrinfo: %s\n" , gai_strerror(status));
         	return 1;
	}

	/*
	 * Loop through res, find first valid IPv4 address
	 */

	/*
	 while(res != NULL && (res->ai_family != AF_INET)){
	     	res = res->ai_next;
		printf("Looping forward\n");
	 }


	//NEXT 4 lines are for debugging
        char temp[INET6_ADDRSTRLEN];
	struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;

	inet_ntop(res->ai_family, &(ipv4->sin_addr), temp, sizeof temp);
	printf("domain : %s\n" , temp);
	
	//check for NULL 
	if(res == NULL){
		fprintf(stderr , "No valid address found\n");
		freeaddrinfo(res);
		return ADDR_NOT_FOUND;
	} */
	
	//Create socket and handle err	
	/*
	if((sockfd =  socket(res->ai_family, res->ai_socktype,  res->ai_protocol)) == -1){
		fprintf(stderr, "failed to create socket: %s\n" , strerror(errno));	
		freeaddrinfo(res);
		
		return 1;

	}	*/
	/*
	struct sockaddr_in test;
	memset(&test, 0, sizeof test);
	test = *(struct sockaddr_in *)(res->ai_addr); 
	int sizz = sizeof res->ai_addr;
	int szz = test.sin_len;
	//test.sin_len = sizeof( struct sockaddr_in);	
	*/
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

	puts("Connection success");
	char s[INET6_ADDRSTRLEN];
	inet_ntop(res->ai_family, get_in_addr((struct sockaddr *)res->ai_addr), s, sizeof s);
	printf("connection to %s\n" , s);
	/*
	while((err = connect(sockfd, res->ai_addr, res->ai_addrlen)) != 0){
		fprintf(stderr, "failed to create connection: %s\n" , strerror(errno));	
		if(res == NULL)
			return 5;
		res = res->ai_next;

	}*/	
	//Create TCP connection and handle err	

	/*
	if( connect(sockfd, (struct sockaddr *)res->ai_addr, res->ai_addrlen) == -1){
		fprintf(stderr, "failed to create connection: %s\n" , strerror(errno));	
		printf("%d\n", errno);
		freeaddrinfo(res);
		close(sockfd);	

		return 1;
	}*/ 

	/*
	 * Create a valid HTTP GET request
	 *
	 */
	char bbuff[1000] = {0};	
	msg = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: keep-alive\r\n\r\n"; 		
	printf("Message:\n%s\n", msg);
	sent = send(sockfd, msg, sizeof msg, 0);
	printf("%d of %d bytes sent\n" , sent , sizeof msg);
	recvd = recv(sockfd, bbuff, sizeof msg, 0);
	if(recvd)
		printf("%d of %d bytes recieved", recvd , sizeof buffer);	
	else
		printf("Conection dropped unexpectedly\n");
	printf("%s\n" , buffer);
	freeaddrinfo(res);
	close(sockfd);	
	return 0;
}






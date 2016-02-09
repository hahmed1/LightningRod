#include "network.h"
#include <string.h>
#include <stdio.h>


//TODO
int find(const char *name, struct address *head)
{
	return 0;	
}

int simple_find(const char *name, char *address)
{
	struct addrinfo hints, *res, *tmp;
	int err;
	//char ipstr[INET6_ADDRSTRLEN];
	char *ipver;
	void *addr;
	//0 out memory and fill-in values
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	//Perform lookup and handle errors
	if((err = getaddrinfo(name, NULL, &hints, &res) != 0)){
		fprintf(stderr, "getaddrinfo: %s\n" , gai_strerror(err));
		return ADDR_NOT_FOUND; 
	}
	
	tmp = res;
	if(tmp->ai_family == AF_INET){
		struct sockaddr_in *ipv4 = (struct sockaddr_in *)tmp->ai_addr;
		
		ipver = "IPv4";
		addr = &(ipv4->sin_addr);	
	} else {
	
		struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)tmp->ai_addr;
		ipver = "IPv6";
		addr = &(ipv6->sin6_addr);
	}
	char temp[INET6_ADDRSTRLEN];
	inet_ntop(tmp->ai_family, addr, temp, sizeof temp);
	strcpy(address, temp);
	return 0;
}


int main(int argc, char **argv)
{
	if(argc != 2){
		fprintf(stderr, "usage: showip hostname\n");
		return 1;
	}
	char address[INET6_ADDRSTRLEN];

	simple_find(argv[1] , address);
	printf("Simple Find on %s\n\n" , argv[1]);
	printf("%s\n" , address);	

}



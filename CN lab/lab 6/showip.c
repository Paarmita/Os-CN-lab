/*
** showip.c -- show IP addresses for a host given on the command line
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];
	int i=0;

	if (argc != 2) {
	    fprintf(stderr,"usage: showip hostname\n");
	    return 1;
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;

	//for(i=1;i<2;i++){
		if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
			return 2;

		}

		printf("\nIP addresses for %s:\n", argv[1]);

		for(p = res;p != NULL; p = p->ai_next) {
			void *addr;
			char *ipver;
			// get the pointer to the address itself,
			// different fields in IPv4 and IPv6:
			if (p->ai_family == AF_INET) { // IPv4
				struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
				addr = &(ipv4->sin_addr);
				ipver = "IPv4";
				//printf("socket no IPv4 -- %d \n",p->ai_family);
				//printf("ai_protocol IPv4 -- %d \n",p->ai_protocol);
				printf("hints.ai_family IPv4 -- %d \n",hints.ai_family);
			} else { // IPv6
				struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
				addr = &(ipv6->sin6_addr);
				ipver = "IPv6";
				//printf("socket no IPv6 -- %d \n",p->ai_family);
				//printf("ai_protocol IPv6 -- %d \n",p->ai_protocol);
				printf("hints.ai_family IPv6 -- %d \n",hints.ai_family);
			}

			// convert the IP to a string and print it:
			inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
			printf("  %s: %s\n", ipver, ipstr);
		}
	//}

	freeaddrinfo(res); // free the linked list

	return 0;
}


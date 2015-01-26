#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotpot.h"

void create_socket()
{
	/*char host[64];
	int s;
	struct hostent *hp, *ihp;
	struct sockaddr_in sin;

	
	gethostname(host, sizeof host);
	hp = gethostbyname(host);
	if ( hp == NULL ) {
		fprintf(stderr, "host not found (%s)\n", host);
		exit(1);
	}

	
	s = socket(AF_INET, SOCK_STREAM, 0);
	if ( s < 0 ) {
		perror("socket:");
		exit(s);
	}

	
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	memcpy(&sin.sin_addr, hp->h_addr_list[0], hp->h_length);

	rc = bind(s, (struct sockaddr *)&sin, sizeof(sin));
	if ( rc < 0 ) {
		perror("bind:");
		exit(rc);
	}*/
}
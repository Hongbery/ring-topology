#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "linked_list.h"
#include "socket_message_parser.h"

MasterInput process_master_inputs(int argc, char *argv[]);

entry *players_list_head = NULL;

main (int argc, char *argv[])
{
	int master_sock_fd, binder, listener;
	int len, player_sock_fd;
	char host[64];
	struct hostent *master_hostent, *ihp;
	struct sockaddr_in sin, incoming;

	if(argc < 3)
	{
		printf("Incorrect format. \nAccepted format: master <port-number> <number-of-players> <hops>\n");
		exit(0);
	}

	//Store inputs for Master
	MasterInput inputs;
	inputs = process_master_inputs(argc, argv);
	
	//custom_print(1);
	
	/* fill in hostent struct for self */
	gethostname(host, sizeof host);
	master_hostent = gethostbyname(host);
	if ( master_hostent == NULL ) {
		fprintf(stderr, "%s: host not found (%s)\n", argv[0], host);
		exit(1);
	}

	/* use address family INET and STREAMing sockets (TCP) */
	master_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if ( master_sock_fd < 0 ) {
		perror("socket:");
		exit(master_sock_fd);
	}

	/* set up the address and port */
	sin.sin_family = AF_INET;
	sin.sin_port = htons(inputs->port_number);
	memcpy(&sin.sin_addr, master_hostent->h_addr_list[0], master_hostent->h_length);

	/* bind socket master_sock_fd to address sin */
	binder = bind(master_sock_fd, (struct sockaddr *)&sin, sizeof(sin));
	if ( binder < 0 ) {
		perror("bind:");
		exit(binder);
	}

	listener = listen(master_sock_fd, 5);
	if ( listener < 0 ) {
		perror("listen:");
		exit(listener);
	}

	int number_of_players = 0;
	while(number_of_players < inputs->players)
	{
		len = sizeof(sin);
	    player_sock_fd = accept(master_sock_fd, (struct sockaddr *)&incoming, &len);
	    if ( player_sock_fd < 0 ) {
	      perror("bind:");
	      exit(listener);
	    }
	    ihp = gethostbyaddr((char *)&incoming.sin_addr, 
				sizeof(struct in_addr), AF_INET);
	    printf("player %d is on %s\n", number_of_players, ihp->h_name);

	    MasterPlayer player = (MasterPlayer) malloc(sizeof(struct master_player_t));
	    player->player_id = number_of_players;
	    player->sockFd = player_sock_fd;
	    add_player(&players_list_head, player);

		number_of_players++;
	}

	printf("Number of players: %d\n", players_list_size(&players_list_head));
	exit(0);
}

MasterInput process_master_inputs(int argc, char *argv[])
{
	if(atoi(argv[2]) <= 1)
	{
		printf("Number of players should be greater than 1\n");
		exit(-1);
	}

	if(atoi(argv[3]) < 0)
	{
		printf("Number of hops should be non-negative\n");
		exit(-1);
	}

	MasterInput inputs = (MasterInput) malloc(sizeof(struct master_input_t));
	inputs -> port_number = atoi(argv[1]);
	inputs -> players = atoi(argv[2]);
	inputs -> hops = atoi(argv[3]);
	
	return inputs;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket_message_parser.h"

char* retrieveNameValuePair(char *message, char *name);

SCWelcomeMsg parseServerClientMessage(char *message)
{
	char *delim;
	char *token;
	char *temp, *temp_input;

    token = (char*)(malloc(sizeof(char)*100));
    temp = (char*)(malloc(sizeof(char)*100));
    delim =(char*)(malloc(sizeof(char)*2));
    temp_input = (char*)(malloc(sizeof(char)*100));

    SCWelcomeMsg welcomeMessage = (SCWelcomeMsg) malloc(sizeof(struct Server_Client_Welcome_Message));
	welcomeMessage->type = ServerClientWelcomeMessage;

    strcpy(delim, ";");
    strcpy(temp_input, message);
    token = strtok(temp_input, delim);
    if(token!=NULL)
    {
    	strcpy(temp, token);
    	char *player_id = (char*)retrieveNameValuePair(temp, "player_id");
    	welcomeMessage->player_id=atoi(player_id);
    }

    return welcomeMessage;
}

CSWelcomeMsg parseClientServerMessage(char *message)
{
	char *delim;
	char *token, *token1;
	char *temp, *temp_input;

    token = (char*)(malloc(sizeof(char)*100));
    delim =(char*)(malloc(sizeof(char)*2));
    temp = (char*)(malloc(sizeof(char)*100));
    temp_input = (char*)(malloc(sizeof(char)*100));

    CSWelcomeMsg welcomeMessage = (CSWelcomeMsg) malloc(sizeof(struct Client_Server_Welcome_Message));
	welcomeMessage->type = ClientServerWelcomeMessage;

    strcpy(delim, ";");
    strcpy(temp_input, message);
    token = strtok(temp_input, delim);
    token1 = strtok(NULL, ";");

    if(token!=NULL)
    {
    	strcpy(temp, token);
    	char *player_id = (char*)retrieveNameValuePair(temp, "player_id");
    	welcomeMessage->player_id=atoi(player_id);
    }
   	
    if(token1!=NULL)
    {
    	strcpy(temp, token1);
    	char *port = (char*)retrieveNameValuePair(temp, "listening_port");
    	welcomeMessage->listening_port=atoi(port);
    }
    
    return welcomeMessage;
}

SCConnectMsg parseServerClientConnectMessage(char *message)
{
	char *delim;
	char *token, *token1;
	char *temp, *temp_input;

    token = (char*)(malloc(sizeof(char)*100));
    delim =(char*)(malloc(sizeof(char)*2));
    temp = (char*)(malloc(sizeof(char)*100));
    temp_input = (char*)(malloc(sizeof(char)*100));

    SCConnectMsg connectMessage = (SCConnectMsg) malloc(sizeof(struct Server_Client_Connect_Message));
	connectMessage->type = ServerClientConnectMessage;

	strcpy(delim, ";");
    strcpy(temp_input, message);
    token = strtok(temp_input, delim);
    token1 = strtok(NULL, ";");

    if(token!=NULL)
    {
    	strcpy(temp, token);
    	char *player_id = (char*)retrieveNameValuePair(temp, "connect_player_id");
    	connectMessage->connect_player_id=atoi(player_id);
    }
   	
    if(token1!=NULL)
    {
    	strcpy(temp, token1);
    	char *port = (char*)retrieveNameValuePair(temp, "connection_port");
    	connectMessage->connection_port=atoi(port);
    }
    
    return connectMessage;
}

char* retrieveNameValuePair(char *message, char *name)
{
	const char delim[2] = "=";
	char *token;
	char *temp;

    token = (char*)(malloc(sizeof(char)*100));
    temp = (char*)(malloc(sizeof(char)*100));
    
    strcpy(temp, message);
    token = strtok(temp, "=");
    
    if(token!=NULL)
    {
    	if(strcmp(name, token)==0)
    	{
    		token = strtok(NULL, "=");
    		return token;
    	}
    }
}

void custom_print(int i){
	printf("printing input %d\n", i);
}

/*int main(int argc, char *argv[])
{
	char *message2="player_id=2;listening_port=2001;";
	char *message="player_id=2";
	char *message3="connect_player_id=2;connection_port=2005;";

	SCWelcomeMsg msg = parseServerClientMessage(message);
	printf("%d\n", msg->player_id);

	CSWelcomeMsg msg2 = parseClientServerMessage(message2);
	printf("%d\t%d\n", msg2->player_id, msg2->listening_port);	

	SCConnectMsg msg3 = parseServerClientConnectMessage(message3);
	printf("%d\t%d\n", msg3->connect_player_id, msg3->connection_port);

}*/
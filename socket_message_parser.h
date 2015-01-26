#include "socket_message.h"

char* retrieveNameValuePair(char *message, char *name);

SCWelcomeMsg parseServerClientMessage(char *message);

CSWelcomeMsg parseClientServerMessage(char *message);

SCConnectMsg parseServerClientConnectMessage(char *message);

void custom_print(int i);
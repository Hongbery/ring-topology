typedef enum {ServerClientWelcomeMessage, ClientServerWelcomeMessage, ServerClientConnectMessage} MessageType;

struct Server_Client_Welcome_Message{
	MessageType type;
	int player_id;
};
typedef struct Server_Client_Welcome_Message *SCWelcomeMsg;

struct Client_Server_Welcome_Message{
	MessageType type;
	int player_id;
	int listening_port;
};
typedef struct Client_Server_Welcome_Message *CSWelcomeMsg;

struct Server_Client_Connect_Message{
	MessageType type;
	int connect_player_id;
	int connection_port;
};
typedef struct Server_Client_Connect_Message *SCConnectMsg;
struct master_input_t {
	int port_number;
	int players;
	int hops;
};
typedef struct master_input_t *MasterInput;

struct player_input_t {
	char* master_machine_name;
	int port_number;
};
typedef struct player_input_t *PlayerInput;

struct master_t {

};
typedef struct master_t * Master;

struct master_player_t {
	int sockFd;
	int player_id;
};
typedef struct master_player_t *MasterPlayer;

struct player_t {

};
typedef struct player_t *Player;
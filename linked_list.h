#include "hotpot.h"

typedef struct entry
{
    MasterPlayer player;
    struct entry* next;
} entry;

void add_player(entry **head, MasterPlayer player);

int players_list_size(entry **head);
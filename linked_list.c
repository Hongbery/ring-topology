#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void add_player(entry **head, MasterPlayer player)
{
    struct entry *elem, *temp;
    elem = malloc(sizeof(struct entry));
    if(elem)
    {
        elem -> player = player;
        elem -> next = NULL;

        if(*head == NULL)
        {
            *head = elem;
        }
        else
        {
            temp=*head;
            while(temp!=NULL)
            {
                if(temp->next==NULL)
                {
                    break;
                }
                temp=temp->next;
            }
            temp->next = elem;
        }
    }

}

int players_list_size(entry **head)
{
    struct entry *temp;
    int size=0;

    temp = *head;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
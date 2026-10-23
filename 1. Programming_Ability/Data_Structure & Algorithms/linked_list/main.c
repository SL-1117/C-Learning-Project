#include "quest_linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include 

int main(void)
{
    char quest_name[80] = {0};
    int quest_id = 0;
    Quest *head = NULL;                 //*

    char player_input[20] = {0};

    do {
        printf("Do u want to add a quest?");
        fgets(player_input, sizeof(player_input), stdin);
        player_input[strlen(player_input) - 1] = '\0';

        if (strcmp(player_input, "ok ok") == 0)
        {
            scanf("%d", &quest_id);

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF){}                 //*

            fgets(quest_name, sizeof(quest_name), stdin);
            quest_name[strlen(quest_name) - 1] = '\0';                  //*

            head = add_quest(head, quest_id, quest_name);                   //*
        }

    } while (strcmp(player_input, "ok ok") == 0);                   //**
        
    complete_quest(head, 3);

    display_quest(head);

    free_quest(head);

    getchar();

    return 0;
}
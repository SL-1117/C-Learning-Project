#ifndef QUEST_H
#define QUEST_H 

#include <stdio.h>
#include <stdint.h>

typedef enum {
    ACTIVE, COMPLETED
} Quest_state;

typedef struct Quest {
    char name[80];
    int id;
    uint8_t state;
    struct Quest *next;
} Quest;

Quest *add_quest(Quest *head, int id, char name[]);
int complete_quest(Quest *head, int id);
void display_quest(const Quest *head);
void free_quest(Quest *head);

#endif
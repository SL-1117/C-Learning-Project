#pragma

#include <stdio.h>
#include <stdint.h>

typedef struct {
    char *name;
    int id;
    uint8_t state;
    Quest *next;
} Quest;

void quest_init();
void complete();
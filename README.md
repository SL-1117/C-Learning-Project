# C-Learning-Project
### I think I might need to change the name to Engineering Training Project

2026/10/5 Monday

This is the eighteenth day I started learning C by making a game.


### C
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn on the Full-C-Courses). 
I think I'm js gonna make something like roadmap tdy after back from camping.

# assert
It's basically a checking/protection mechanism that verifies assumptions the programmer expects to always be true.
if an assumption is false while the program is still running, assert reports the false and stops the program.

assert(player->hp <= PLAYER_MAX_HP);
assert(player->mp <= PLAYER_MAX_MP);
assert(player->level <= PLAYER_MAX_LEVEL);

btw I try to put it in my code

# linked list
it's a sequence of nodes which are connected by pointers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typdef struct Item
{
  char name[30];
  int price;
  int quantity;

  struct Item *next;
} Item;

struct Player player 
{
  char name[20];
  int hp;
  int mp;
  int level;
  struct Item *inventory;
};

addItem(struct Player *player, char name[], int price, int quantity)
{
  // Create Item
  struct Item *newItem = malloc(sizeof(struct Item));

  strcpy(newItem->name, name);
  newItem->price = price;
  newItem->quantity = quantity;

  // Add item
  newItem->next = player->inventory;
  player->inventory = newItem;
}

int main(void) 
{
  struct Player *player;

  player = malloc(sizeof(struct Player));
  player->inventory = NULL;

  addItem(player, char name[], int price, int quantity);

  struct Item current;
  struct Item next;
  current = player->inventory;

  while (current->next != NULL)
  {
    printf("%s\n", current->name);

    next = current->next;

    free(current);

    current = next;
  }

  free(player);
}



# note
btw I js found a new way to use the typdef struct, check the program.

and I replace the old Inventory logic and player status logic with the new things I learnd, which is linked list.

    // // Inventory_items
    // Item *Inventory = malloc(25 * sizeof(Item));
    // Inventory[0] = (Item){"Sword", 1};
    // Inventory[1] = (Item){"Potion", 3};
    // Inventory[2] = (Item){"Hi-Potion", 982982};
    // Inventory[3] = (Item){"Orb", 1};
    // Inventory[4] = (Item){"Hammer", 4};
    // Inventory[5] = (Item){"Dagger", 3};


### MCU
Let's summarize all the MCU concepts and organize them so that I can get a proper roadmap about how am I gonna this shxt.

So basically we got five different part that we can control and learn about how to control them seperately.


# LED


# 7-segment


# Keypad


# Buzzer


# RGB



### Fibonacci sequence


### The roadmap of Data Structure(but dis is not for today tho.)

                           DATA STRUCTURES
                                  │
          ┌───────────────────────┼────────────────────────┐
          │                       │                        │
          ▼                       ▼                        ▼
       LINEAR                HIERARCHICAL              NETWORK
          │                       │                        │
    ┌─────┼─────┐           ┌─────┼─────┐                  │
    │     │     │           │     │     │                  │
    ▼     ▼     ▼           ▼     ▼     ▼                  ▼
  Array  List  Stack       Tree   Heap  Trie              Graph
    │     │     │
    │     │     └── Queue
    │     │          │
    │     │          ├── Circular Queue
    │     │          └── Priority Queue
    │     │
    │     ├── Singly Linked List
    │     ├── Doubly Linked List
    │     └── Circular Linked List
    │
    └── Dynamic Array


                    OTHER IMPORTANT STRUCTURES
                              │
          ┌───────────────────┼───────────────────┐
          ▼                   ▼                   ▼
     Hash Table          Disjoint Set         Advanced
                                               Structures
          │                   │                   │
     Hash Function        Union-Find          AVL Tree
     Collision            DSU                 Red-Black Tree
     Chaining                                  B-Tree
     Open Addressing                           Segment Tree
                                               Fenwick Tree

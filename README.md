# C-Learning-Project

2026/10/11 Sunday

This is the twenty-fourth day I started learning C by making a game.

# note
I'm thinking...so basically I learned how to code interrupt tdy, it was actually not that complicated as what I thought.

### MCU
// Create irq every 1ms
SysTick_Config(SystemCoreClock / 1000);

// It allows CPU to respond to interrupts that are not blocked or disalbed.
__enable_irq();

// Interrupt
An interrupt allows the MCU to handle an event without requiring while(1) loop to constantly check for it
However, an interrupt does temporarily interrupt the main program when its handler executes.


### C
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn in the Full-C-Courses). 

# static 
static int digit = 0;

local variable = remember its value between function calls.

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
and I replace the old Inventory logic and player status logic with the new things I learnd, which is linked list.

    // // Inventory_items
    // Item *Inventory = malloc(25 * sizeof(Item));
    // Inventory[0] = (Item){"Sword", 1};
    // Inventory[1] = (Item){"Potion", 3};
    // Inventory[2] = (Item){"Hi-Potion", 982982};
    // Inventory[3] = (Item){"Orb", 1};
    // Inventory[4] = (Item){"Hammer", 4};
    // Inventory[5] = (Item){"Dagger", 3};


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
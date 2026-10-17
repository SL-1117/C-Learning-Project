# C-Learning-Project
### I think I might need to change the name to Engineering Training Project

2026/10/8 Thursday

This is the twenty-first day I started learning C by making a game.

# note
I'm thinking...so basically I learned how to code interrupt tdy, it was actually not that complicated as what I thought.

### MCU
// Initialize everything
void Init_KeyPad(void)
{
    GPIO_SetMode(PA, BIT0, GPIO_MODE_QUASI);
    GPIO_SetMode(PA, BIT1, GPIO_MODE_QUASI);
    GPIO_SetMode(PA, BIT2, GPIO_MODE_QUASI);
    
    GPIO_SetMode(PA, BIT3, GPIO_MODE_QUASI);
    GPIO_SetMode(PA, BIT4, GPIO_MODE_QUASI);
    GPIO_SetMode(PA, BIT5, GPIO_MODE_QUASI);

    PA0 = 1;
    PA1 = 1;
    PA2 = 1;

    PA3 = 0; 
    PA4 = 0;
    PA5 = 0;

    GPIO_EnableINT(PA, 0, GPIO_INT_BOTH_EDGE);
    GPIO_EnableINT(PA, 1, GPIO_INT_BOTH_EDGE);
    GPIO_EnableINT(PA, 2, GPIO_INT_BOTH_EDGE);

    NVCI_EnableIRQ(GPAB_IRQn);

    GPIO_SET_DEBOUNCE_TIME(
        GPIO_DBCLKSRC_LIRC,
        GPIO_DBCLKSEL_64
    );

    GPIO_ENABLE_DEBOUNCE(
        PA,
        BIT0 | BIT1 | BIT2
    );
}

// Get the key
int GetKey(void)
{
    int key = 0;
    
    PA3 = 0;
    PA4 = 1;
    PA5 = 1;

    if (key == 0)
    {
        if (PA0 == 0) key = 1; 
        else if (PA1 == 0) key = 2;
        else if (PA2 == 0) key = 3;
    }
    
    if (key == 0)
    {
        PA3 = 1;
        PA4 = 0;
        PA5 = 1;

        if (PA0 == 0) key = 4;
        else if (PA1 == 0) key = 5;
        else if (PA2 == 0) key = 6;
    }

    if (key == 0)
    {
        PA3 = 1;
        PA4 = 1;
        PA5 = 0;

        if (PA0 == 0) key = 7;
        else if (PA1 == 0) key = 8;
        else if (PA2 == 0) key = 9;
    }

    PA3 = 0;
    PA4 = 0;
    PA5 = 0;

    PA0 = 1;
    PA1 = 1;
    PA2 = 1;

    return key;
}

// after being interupted
void GPAB_IRQHandler(void) 
{
    if (PA->ISRC & BIT0) PA->ISRC0 = BIT0;
    if (PA->ISRC & BIT1) PA->ISRC1 = BIT1;
    if (PA->ISRC & BIT2) PA->ISRC2 = BTI2;

    key = GetKey();

    if (key != 0) 
    {
        pressed_key = key;
    }

    else
    {
        if ()
        else if ()
        else if ()

        pressed_key == 0;
    }
}


void Init_INT1(void)
{
    GPIO_SetMode(PB, BIT15, GPIO_MODE_INPUT);

    GPIO_EnableEINT1(PB, 15, GPIO_INT_RISING);

    NVCI_EnableIRQ(EINT1_IRQn);

    // Debounce
    GPIO_SET_DEBOUNCE_TIME(
        GPIO_DBCLKSRC_LIRC,
        GPIO_DBCLKSEL_64
    );

    GPIO_ENABLE_DEBOUNCE(
        PB,
        BIT15
    );
}

void EINT1_IRQHandler(void)
{
    GPIO_CLR_INT_FLAG(PB, BIT15);
}

### C
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn on the Full-C-Courses). 


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

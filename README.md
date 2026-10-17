# C-Learning-Project
### I think I might need to change the name to Engineering Training Project

2026/10/6 Tuesday

This is the nighteenth day I started learning C by making a game.


### C
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn on the Full-C-Courses). 

# uint8_t
uint8_t ones;
uint32_t tens;

unsigned means the type cannot represent negative number.

# static 
static int digit = 0;

local variable = remember its value between function calls.

# volatile
volatile int Anumber = 1;

it's telling the compiler DO NOT automatically assume the number stays the same,
read its value when the program needs it, it's basically used when there is a IRQ

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
Let's summarize all the MCU concepts and organize them so that I can get a proper roadmap about how am I gonna learn all them.

So basically we got five different part that we can control and learn about how to control them seperately.


# LED
PC12 = 0;
PC13 = 0;
PC14 = 0;
PC15 = 0;

# 7-segment
ShowSevenSegment(0, d0);
ShowSevenSegment(1, d1);
ShowSevenSegment(2, d2);
ShowSevenSegment(3, d3);

# Keypad
int key = 0;
int last_key = 0;

key = Scankey();

if (last_key scope and key == 0)

btw it's for the debouncing.

# Buzzer
GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT);

# RGB
#define RED PA12
#define GREEN PA13
#define BLUE PA14

GPIO_SetMode(PA, BIT12, GPIO_MODE_OUTPUT);
GPIO_SetMode(PA, BIT13, GPIO_MODE_OUTPUT);
GPIO_SetMode(PA, BIT14, GPIO_MODE_OUTPUT);

RED = 0;
GREEN = 0;
BLUE = 0;

### MCU Lab
// #include <stdio.h>
// #include "NUC100Series.h"
// #include "GPIO.h"
// #include "SYS.h"
// #include "Seven_Segment.h"
// #include "Scankey.h"

#define B 7 
#define C 8 
#define PLUS_KEY 9

int num1 = 0;
int num2 = 0;
int state = 0;

int GetDisplayNum(void);
void Refresh_7seg(int value);
void AddNum(int digit, int *num);

void ClearAll(void);
void BackSpace(int *num);

int main(void)
{
    int key = 0;
    int last_key = 0;

    SYS_Init();

    OpenSevenSegment();
    OpenKeyPad();

    while(1)
    {
        key = Scankey();

        if (last_key >= 1 && last_key <= 6 && key == 0)
        {
            if (state == 0) AddNum(last_key, &num1);
            else if (state == 1) AddNum(last_key, &num2);
        }

        else if (last_key == B && key == 0)
        {
            if (state == 0) BackSpace(&num1);
            else if (state == 1) BackSpace(&num2);
        }

        else if (last_key == C && key == 0)
        {
            ClearAll();
        }

        else if (last_key == PLUS_KEY && key == 0)
        {
            if (state == 0) state = 1;
            else if (state == 1) state = 2;
        }

        Refresh_7seg(GetDisplayNum());

        if (state == 2)
        {
            while (key != C)
            {
                key = Scankey();
            }

            ClearAll();
        }

        last_key = key;
    }
}

void Refresh_7seg(int value)
{
    static int digit = 0;

    int d0 = value % 10;
    int d1 = (value / 10) % 10;
    int d2 = (value / 100) % 10;
    int d3 = (value / 1000) % 10;

    CloseSevenSegment();

    if (digit == 0 && value != 0)           ShowSevenSegment(0, d0);
    else if (digit == 1 && value >= 10)     ShowSevenSegment(1, d1);
    else if (digit == 2 && value >= 100)    ShowSevenSegment(2, d2);
    else if (digit == 3 && value >= 1000)   ShowSevenSegment(3, d3);

    CLK_SysTickDelay(1000);

    digit++;
    
    if (digit >= 4) digit = 0;
}

int GetDisplayNum(void)
{
    if (state == 0) return num1;
    if (state == 1) return num2;

    return num1 + num2;
}

void AddNum(int digit, int *num)
{
    *num = *num * 10 + digit;
}

void ClearAll(void)
{
    state = 0;
    num1 = 0;
    num2 = 0;
    CloseSevenSegment();
}

void BackSpace(int *num)
{
    *num = *num / 10;
}


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

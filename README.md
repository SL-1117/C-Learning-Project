# C-Learning-Project

2026/9/28 Monday

This is the eleventh day I started learning C by making a game.
9/25 - 9/27 was Moon Festival, and I wasn't at home. 


### define
what's #define?
It means we r giving a certain number a name.

#include <stdio.h>

#define PLAYER_MAX_HP 1000
#define PLAYER_MAX_MP 1000
#define PLAYER_MAX_LEVEL 99
#define PLAYER_MAX_ATK 100
#define PLAYER_MAX_DEF 100

typedef struct 
{
  int hp;
  int mp;
  int level;
  int atk;
  int def;
}Player_Status;

int main(void) 
{
  Player_Status player;

  player.hp = PLAYER_MAX_HP;
  player.mp = PLAYER_MAX_MP;
  player.level = PLAYER_MAX_LEVEL;
  player.atk = PLAYER_MAX_ATK;
  player.def = PLAYER_MAX_DEF;

  return 0;
}

### enum 
It's for us to give a meaningful name for a limited set of numbers.

#include <stdio.h>

typedef enum
{
  MAGE, ASSASSIN, WARRIOR, PRIEST, ARCHER
}Class;

int main(void) 
{
  Class Player_class = MAGE;

  if (Player_class == MAGE)
  {
    printf("Your class is mage.\n");
  }
  else if (Player_class == ASSASSIN)
  {
    printf("Your class is ASSASSIN.\n");
  }
  else if (Player_class == PRIEST) 
  {
    printf("Your class is priest.\n");
  }
  else if (Player_class == WARRIOR) 
  {
    printf("Your class is warrior.\n");
  }
  else 
  {
    printf("Your class is archer.\n");
  }
}

### srand 
It's providing the odds for the program.

#include <stdio.h>
#include <time.h>

int main(void) 
{
  srand(time(NULL));

  int event = rand() % 100;

  if (event < 30)
  {
    int enemy = rand() % 4;

    switch(enemy)
    {
      case 0:
        printf("You encountered slime.\n");
        break;

      case 1:
        printf("You encountered goblin.\n");
        break;
      
      case 2:
        printf("You encountered orc.\n");
        break;
      
      case 3:
        printf("You encountered wolf.\n");
        break;
      
      default:
        break;
    }
  }
  else if (event < 40)
  {
    printf("You found the treasure chest!\n");
  }
  else if (event < 45)
  {
    printf("You found the hidden path!\n");
  }
  else 
  {
    printf("The road is quiet.\n");
  }

  return 0;
}

### struct
It's for us storing related types of data.
btw we can even combine it with enum.

#include <stdio.h>
#include <string.h>

typedef enum
{
  MAGE, ASSASSIN, WARRIOR, PRIEST, ARCHER
}Class;

typedef struct 
{
  char name[20];
  Class class;
  int hp;
  int mp;
  int level;
  int atk;
  int def;
}Player_Status;

int main(void) 
{
  Player_Status player;
  player.class = PRIEST;
  strcpy(player.name, "Eren");
  player.hp = 100;
  player.mp = 100;
  player.level = 1;
  player.atk = 10;
  player.def = 10;

  return 0;
}

### malloc 
It's for dynamically allocate the memory.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[20];
  int quantity;
}Item; 

int main(void) 
{
  Item *Inventory = malloc(25 * sizeof(Item));

  Inventory[0] = (Item){"Sword", 1};
  Inventory[1] = (Item){"Hammer", 2};
  Inventory[2] = (Item){"Potion", 5};
  Inventory[3] = (Item){"Hi-Potion", 982982};
  Inventory[4] = (Item){"Dagger", 4};

  free(Inventory);

  return 0;
}

### C
I'mma put these concepts in my main program.
and ofc imma learn them thoroughly before doing that.

srand
#define
typedef enum
Fibonacci sequence
malloc / calloc / realloc
strcmp / strcpy / strlen / strcat

### note
I combined almost everything I've learned into the main program except for Fibonacci bc it's not that important for the moment, I can js combine it later.
And I think I got a general idea about what I'm learning rn and how to use them.
I also think we can start to learn the roadmap of Data Structure tmr, especially tring to put the liked list in my code. 


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
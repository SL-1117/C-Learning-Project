# C-Learning-Project

2026/9/22 Wednesday

The this is the sixth day I start learning C by making a game.

### malloc / calloc / realloc

# malloc

this is for dynamically allocating the memory. 
u can allocate the memory that the player actually needs, instead of js hard-coding it.

what malloc means in the program?
it's not something like pointer, it's an adrress that stored the memory that has been allocated.
that's also what it returns.

so that's why we use "int *Inventory = malloc(Inventory_size * sizeof(int));"
bc the pointer points to the address where we stored our value.

char is one byte, int is four bytes.
so it means "int *Inventroy = malloc(5 * 4 = 20 bytes);"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int Inventory_size = 0;

    printf("How many inventory slots?\n");
    scanf("%d", &Inventory_size);

    int *Inventory = malloc(Inventory_size * sizeof(int));

    if (Inventory == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    Inventory[0] = 1;
    Inventory[1] = 2;
    Inventory[2] = 3;

    printf("%d", Inventory[0]);
    printf("%d", Inventory[1]);
    printf("%d", Inventory[2]);

    free(Inventory);

    return 0;
}



# calloc 

it's used for initializing the values inside the arr we allocated memory for.

so basically when we use 
"int *Inventory = malloc(Inventory_size * sizeof(int));" 
we didn't initialize the values inside the pointer.
we use "int *Inventory = calloc(Inventory_size * sizeof(int));" to do like {0, 0, 0, 0, 0}

and btw I was so confused that why we can use Inventory[0] while we define it as a pointer
but the chatgpt was basically js told me that we js can.


# realloc

it's js used for reallocating the dynamic memory.

Inventory = realloc(Inventory, number * sizeof(int)) 
but don't js do this, we need some protection mechanism.

int *temp = realloc(Inventory, Inventory_size * sizeof(int));

if (temp == NULL) 
{
    printf("Memory allocation failed.\n");
    return 1;
}

Invetory = temp;


### rand() / srand()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));

    int random = rand() % 10 + 1;
    int random = rand() % (Max - min + 1) + min;

    printf("%d", random);

    return 0;

}


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
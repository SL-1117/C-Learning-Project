# C-Learning-Project

2026/10/12 Monday

This is the twenty-fifth day I started learning C by making a game.

### MCU
Finally, I wrapped all the things in my mind around and then figured out all the things that we r doing about the interrput. 

### C
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn in the Full-C-Courses).

# bool
#include <stdbool.h>

bool isAdult(int age)
{
    return age >= 18;
}

bool islocked = true, false;

if (isAdult(19))
    printf("You are an adult.\n");
else
    printf("You are not adult.\n");

# do while
the only difference between do while and while is the order.
the order to execute the program and check the value.

void AttackCheck(void) 
{
    do {
        printf("You are attacked!");
        hp -= 2;
    } while (hp > 0);
}

# float
The way we need to declare the float number.

float num1 = 0.0f;
float num2 = 11.23f;

# double 
The way we need to declare the double number.

double num1 = 0.0;
double num2 = 20.34;

# char array
char name[20] = "";
char choice = '\0';

# fget
js for reviewing

char name[20] = "";

fget(name, sizeof(name), stdin);
name[strlen[name] - 1] = '\0';

printf("%s", name);

# static 
static int digit = 0;

local variable = remember its value between function calls.

# Fibonnaci 
#include <stdio.h>

void Fibonnaci(int num_of_sequence, int arr[])
{
    if (num_of_sequence <= 0)
    {
        printf("Invalid num\n");
        return;
    }

    if (num_of_sequence >= 1) arr[0] = 1;
    if (num_of_sequence >= 2) arr[1] = 1;

    if (num_of_sequence >= 3)
    {

            for (int j = 0; j < num_of_sequence; j++)
            {
                arr[j + 2] = arr[j + 1] + arr[j]; 
            }

    }
}

int main(void)
{
    int num_of_sequence = 0;
    int arr[30];

    printf("Pls enter the number of the Fibonnaci that You wish down below.\n");
    scanf("%d", &num_of_sequence);

    Fibonnaci(num_of_sequence, arr);

    for (int i = 0; i < num_of_sequence; i++)
    {
        printf("%d\n", arr[i]);
    }
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

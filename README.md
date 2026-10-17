# C-Learning-Project

2026/9/28 Tuesday

This is the twelveth day I started learning C by making a game.
9/25 - 9/27 was Moon Festival, and I wasn't at home. 

### fgets
This is basically the same as scanf, but it keeps the spaces that the user enters

# strcspn
It's finding the pos of the first character in a string that matches any character from another string.

fgets(noun, sizeof(noun), stdin);
noun[strlen(noun) - 1] = '\0';

    char *messages = malloc(25 * sizeof(char));

    if (messages == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    fgets(messages, 25, stdin);
    messages[strcspn(messages, "\n")] = '\0';

    printf("%s\n", messages);

    free(messages);
    getchar();

    return 0;

### math

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int a = 2;
  float b = 3.39;
  int c = -3;
  double d = 5;

  a = sqrt(a);
  a = pow(a, 3);
  b = round(b);
  b = ceil(b);
  b = floor(b);
  c = abs(c);
  d = log(d);

  printf("%d\n", a);
  printf("%f\n", b);
  printf("%d\n", c);
  printf("%lf\n", d);

  return 0;
}

### circle calculator

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  int radius;
  double area;
  double surfaceArea;
  double volume;
}Circle;

int main(void)
{
  Circle circle;
  circle.radius = 3;
  const float PI = 3.14159;

  circle.area = PI * pow(circle.radius, 2);
  circle.surfaceArea = 4.0 * PI * pow(circle.radius, 2);
  circle.volume = (4.0 / 3.0) * PI * pow(circle.radius, 3);

  printf("The circle's area is %lf.\n"
         "The circle's surfaceArea is %lf.\n"
         "The circle's volume is %lf.\n", 
          circle.area, circle.surfaceArea, circle.volume);
  
  return 0;
}


Fibonacci sequence


### note
I combined almost everything I've learned into the main program except for Fibonacci bc it's not that important for the moment, I can js combine it later.
And I think I got a general idea about what I'm learning rn and how to use them.
I also think we can start to learn the roadmap of Data Structure tmr, especially try to put the liked list in my code. 


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

# C-Learning-Project

2026/10/13 Tuesday

This is the twenty-sixth day I started learning C by making a game.


### C
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn in the Full-C-Courses).

# static 
static int digit = 0;
local variable = remember its value between function calls.

# continue / break
for (int i = 0; i < 20; i++)
{
    if (i == 16)
    {
        continue;
    }

    printf("%d\n", i);
}

for (int i = 0; i < 20; i++)
{
    if (i == 16)
    {
        break;
    }

    printf("%d\n", i);
}

# char declare
int num[] = {0};
int num[] = {1, 2, 3, 4, 5};

char num[] = '\0';
char num[] = "Thomas";

char phone_keypad[][20] = {{'1', '2', '3'},
                           {'4', '5', '6'},
                           {'7', '8', '9'}, 
                           {'*', '0', '#'}};
char fruits[][100] = {"Apple", 
                      "Banana", 
                      "Coconut"};

fruits[0][0] = 'e';
fruits[0][4] = 'A';

# include <ctype.h>
int main(void) 
{
    char guess = '\0';

    scanf(" %c", &guess);

    guess = toupper(guess);

    printf("%c", guess);
}

# scanf(" %c", guess);

# printf("%4d", num);
   2


###
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>

guess = toupper(guess);
guess = tolower(guess);

scanf(" %s", name);
printf("%3d", name;)

for (int i = 0; i < 10; i++)
{
    if (i == 5)
    {
        break;
    }

    printf("%d", i);
}

for (int i = 0; i < 10; i++)
{
    if (i == 5)
    {
        continue;
    }

    printf("%d", i);
}

int numbers[5] = {0};
int numbers[5] = {1, 2, 3, 4, 5};

char guess = '\0';
char characters[] = {'A', 'B', 'C', 'D', 'E'}; 
char characters2[] = "HelloWorld";

char keypad[][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'},
                    {'*', '0', '#'}};
char fruits[][3] = {"Apple", 
                    "Banana",
                    "Coconut"};

fruits[0][0] = 'e';
fruits[0][4] = 'A';

fruits[1][0] = 'a';
fruits[1][5] = 'B';

fruits[2][0] = 't';
fruits[2][6] = 'C';

// when we enter 10 at the first scanf, we press "enter" 
// so the program is actually received 10\n
scanf("%d", &num);
scanf(" %c", &choice);

bool age18Check(int age)
{
    if (age >= 18) return true;
    else return false;
}

bool age18Check2(int age)
{
    return age >= 18;
}

char AttackCheck(void) 
{
    int hp = 10;

    do {
        printf("Attack!\n");
        hp -= 1;
        Sleep(1000);
    } while (hp > 0);
}

int main(void) 
{
    bool islocked = true;

    char name[20] = "";
    char operator = '\0';

    float weight = 0.0f;
    float height = 0.0f;
    float rnum = 10.00;

    double num1 = 0.0;
    double num2 = 21.34;
    double result = 0.0;

    int age = 3;

    printf("Enter ur name: \n");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("ur name is %s\n", name);
    printf("ur age is %.2lf\n", age);

    if (islocked == true)
    {
        if (age18Check2(18))
        {
            printf("You are already 18.\n");
        }

        else 
        {
            printf("You are not 18 yet.\n");
        }

        printf("You ara locked.\n");
    }

    else if (islocked == false)
    {
        printf("You are not a locked.\n");
    }

    printf("num1's value is %lf\n", num1);
    printf("num2's value is %.2f\n", num2);

    AttackCheck();

    getchar();
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

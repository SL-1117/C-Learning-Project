# C-Learning-Project

2026/10/16 Friday

This is the twenty-nineth day I started learning C by making a game.

# C note
I'm gonna take the things that I learned from MCU into my main RPG project(include the new things I'mma learn in the Full-C-Courses).

# static 
static int digit = 0;
local variable = remember its value between function calls.

# fopen "r"
```c
#include <stdio.h>

int main(void)
{
    FILE *pFile = fopen("C:\\Users\\liwei\\OneDrive\\桌面\\Coding\\C\\Engineering_Technical_Skills\\1. Programming_Ability\\C\\RPG_LOST_KINGDOM\\readTest.txt", "r");

    if (pFile == NULL)
    {
        printf("Could not open the file.");
        return 1;
    }

    char buffer[1024] = {0};
    char player_input[20] = {0};

    while (fgets(buffer, sizeof(pFile), pFile))
    {
        printf("%s", buffer);
    }

    printf("\n");

    fgets(player_input, sizeof(player_input), stdin);
    player_input[sizeof(player_input) + 1] = '\0';

    printf("%s", player_input);

    getchar();
    
    return 0;
}
```


# fopen "w"
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    FILE *pFile = fopen("C:\\Users\\liwei\\OneDrive\\桌面\\Coding\\C\\Engineering_Technical_Skills\\1. Programming_Ability\\C\\RPG_LOST_KINGDOM\\output.c", "w");
    
    if (pFile == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    bool isPlayerLucky = false;

    char words[] = "// \"You have found the very secret path...\"";
    char *messages = malloc(strlen(words) * sizeof(char));
    strcpy(messages, words);

    char player_input[] = {0};

    printf("Pls enter \"Yes\" if hope you are lucky.\n");
    scanf("%s", player_input);
    for (int i = 0; player_input[i] != '\0'; i++)
    {
        player_input[i] = tolower(player_input[i]);
    }

    if (strcmp(player_input, "yes") == 0)
    {
        isPlayerLucky = true;
    }

    else 
    {
        printf("You didn't allow us to switch ur state.\n");
    }

    fprintf(pFile, "%s", (isPlayerLucky) ? messages : "Nope");

    printf("File open successfully!");

    fclose(pFile);

    getchar();

    return 0;
}
```


# array_of_struct / pointer
```c 
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *name;
    char *race;
    int hp;
    int mp;
    int atk;
    int def;
    int level;
}Mob;

void plusPlayerGold(int *gold);

int main(void) 
{   
    int Gold = 1000;
    int *gold  = &Gold;

    *gold++;
    (*gold)++;

    Mob mobs[] = {{"Charlie", "Wolf", 100, 100, 10, 10, 1},
                  {"Hokkins", "Slime", 50, 50, 1, 1, 1},
                  {"Steve", "Orc", 200, 200, 100, 100, 50}};

    int size = sizeof(mobs) / sizeof(mobs[0]);              

    for (int i = 0; i < size; i++)
    {
        printf("Name: %-7s\nRace: %-7s\nHP: %-7d\nMP: %-7d\nATK: %-7d\nDEF: %-7d\nLevel: %-7d\n\n",
            mobs[i].name, mobs[i].race, mobs[i].hp, mobs[i].mp, mobs[i].atk, mobs[i].def, mobs[i].level);
    }


    printf("%d\n", Gold);

    printf("%d\n", &Gold);
    printf("%d\n", gold);

    getchar();
}

void plusPlayerGold(int *gold)
{
    (*gold)++;
}

# typedef 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef int HelloNumber;
typedef uint8_t HelloLnumber;
typedef char HelloTest[3];
typedef char *HelloPointer;

int main(void)
{
    HelloNumber Anumber = 8387;
    HelloLnumber anumber = 98;
    HelloTest name = "BT";
    HelloPointer name2 = "SP";

    printf("%d\n", Anumber);
    printf("%d\n", anumber);
    printf("%s\n", name);
    printf("%s\n", name2);
    
    getchar();
}
```


# Main
```c
#include <stdio.h>
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

int main(void)
{
    int num = 0;
    bool online = true;
    int age = 18;
    int number = 100;

    int minutes = 2;
    int hours = 17;
    char *meridium = (hours <= 12) ? "AM" : "PM";

    printf("%s\n", (num == 0) ? "Yes" : "No");
    printf("%s\n", (online == true) ? "The player is online." : "The player is not online.");
    printf("%s\n", (age >= 18) ? "Adult" : "Children");
    printf("%s\n", (number % 2 == 0) ? "Odd" : "Even");
    printf("%02d:%02d %s", hours, minutes, meridium);

    getchar();
}

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *name;
    char *race;
    int hp;
    int mp;
    int atk;
    int def;
    int level;
}Mob;

void plusPlayerGold(int *gold);

int main(void) 
{   
    int Gold = 1000;
    int *gold  = &Gold;

    *gold++;
    (*gold)++;

    Mob mobs[] = {{"Charlie", "Wolf", 100, 100, 10, 10, 1},
                  {"Hokkins", "Slime", 50, 50, 1, 1, 1},
                  {"Steve", "Orc", 200, 200, 100, 100, 50}};

    int size = sizeof(mobs) / sizeof(mobs[0]);              

    for (int i = 0; i < size; i++)
    {
        printf("Name: %-7s\nRace: %-7s\nHP: %-7d\nMP: %-7d\nATK: %-7d\nDEF: %-7d\nLevel: %-7d\n\n",
            mobs[i].name, mobs[i].race, mobs[i].hp, mobs[i].mp, mobs[i].atk, mobs[i].def, mobs[i].level);
    }


    printf("%d\n", Gold);

    printf("%d\n", &Gold);
    printf("%d\n", gold);

    getchar();
}

void plusPlayerGold(int *gold)
{
    (*gold)++;
}
```


### The roadmap of Data Structure(but dis is not for today tho.)
```c
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
```
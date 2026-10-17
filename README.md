# C-Learning-Project

2026/9/22 Tuesday

The this is the fifth day I start learning C by making a game.

### How to use typedef of struct

# And remember to put the quotations at both sides of the string.

typedef struct {

    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;

}Wolf;

int main(void) {

    Wolf Charlie = {
        "Charlie", "Wolf", 99, 10000, 10000, 1000, 1000
    };

    printf("%d is Charlie's HP.\n", Charlie.hp);

}

### How to use enum and typedef of it

# If we don't put the value for the constant we set, then the first one is gonna start from 0.
# Remember to put the quotation for the switch logic.

typedef enum {

    SUCCESS = 1, FAILURE = 2, PENDING = 3

}Connection_Status;

int main() {

    Connection_Status Connection_Status = SUCCESS;
    
    switch (Connection_Status) 
    {
        case 1:
            printf("\"Connection successful.\"\n");
            break;

        case 2:
            printf("\"Connection falied.\"\n");
            break;

        case 3:
            printf("\"Connection is Pending...\".\n");
            break;

        default:
            printf("\"Unknown status.\"\n");
            break;
    }
}

### Fibonacci

void Fibonacci(int num, int Fibonacci_arr[]);

int main(void) {

    int Fibonacci_num = 4;
    int Fibonacci_arr[100];

    Fibonacci(30, Fibonacci_arr);

    return 0;

}

void Fibonacci(int num, int Fibonacci_arr[])
{

    if (num < 1) {
        printf("Invalid number.\n");
        return;
    }
    
    if (num >= 1) Fibonacci_arr[0] = 1;
    if (num >= 2) Fibonacci_arr[1] = 1;

    for (int i = 0; i < num - 2; i++) 
    {
        Fibonacci_arr[i + 2] = Fibonacci_arr[i + 1] + Fibonacci[i];
    }

}

### define

#define NOVICE_SWORD 1
#define FLAME_SWORD 2
#define DRAGON_SLAYER 3

int main() {

    int weapon = 1;

    if (weapon == DRAGON_SLAYER)
    {
        printf("You are holding dragon slayer!");
    }

    return 0;
}

### strcmp/  strcpy/  strlen/  strcat

# strcmp, it can compare two different strings.
# strcpy, it can copy a string to another char[].
# strlen, it can get the length of a string.
# strcat, it can connect two strings.

#include <stdio.h>
#include <string.h>

int main(void) {

    char Player_Location[100] = {"Dark Forest"};

    char message[100] = {"You entered "};
    char message_change[100] = {"Dark Forest"};

    if (strcmp(Player_Location, message_change) == 0) 
    {

        strcat(message, message_change);
        printf("%s\n", message);
        printf("You are now at ");
        strcpy(message, message_change);
        printf("%s\n", message);
        printf("And the string len of "%s" is %d\n", message, strlen(message));

    }

}

### how to do the fade in/out on windows
### how to clean the screen and delay the program.

# so basically when we use \"printf\", we are not just sending something directly.
# we put the message to the buffer and then wait a proper timing to send them out.
# and fflush(stdout) means do not wait, js send anything inside the terminal out.

#include <stdio.h>
#include <windows.h>

void Typetext(char message[]);

int main(void) {

    char message[100] = {"Welcome to the LOST KINGDOM!"};

    Typetext("Hello Player!\n");
    Sleep(1000);
    system("cls");

    Typetext(message);
    Sleep(1000);

    getchar();

}

void Typetext(char message[])
{

    for (int i = 0; message[i] != '\0'; i++)
    {
        printf("%c", message[i]);
        fflush(stdout);
        Sleep(50);
    }

}

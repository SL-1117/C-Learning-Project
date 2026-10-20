# Prgramming-Ability-Project

2026/10/20 Tuesday

# note
Finished the c courses, imma learn the data structure for now.
I put the roadmap here for a pretty long time, finally I can learn it.

I'm gonna js organize and sort out my mind about what I'm going to learn and how I'm gonna do it after finishing all the things I got rn.


# debug / breakpoints 
```c
def sum_of_list(x: list):
    sum = 0

    for i in x:
        sum += i

    return sum

input_list = [10,20,30,40]
res_sum = sum_of_list(input_list)

print(res_sum)
```


# debug / watch_panel
```c
def calcualate_average(grades: list):

    total_items = len(grades)
    total_sum = 0

    for grade in grades:
        total_sum += grade

    return total_sum / total_items

def is_passed(avg):
    return avg >= 91


grades = [80, 70, 65, 35, 50]

average = calcualate_average(grades)
status = is_passed(average)

print(f'Average: {average}')
print(f'Status: {status}')

'''
data = {
'name': '',
cart_items : {
    [], ''
}
}
'''
```


# debug / call_stack
```c
def apply_discount(price):

    return price * 0.05

def checkout(item_price, tax):

    discounted_price = apply_discount(item_price)
    return discounted_price + tax

filnal_price = checkout(1000, 100)
print(f'Final price: (final_price)')
```


# debug / conditional breakpoints
```c
def square_list(numbers: list):

    for number in numbers:
        res = number ** 2

        print(f'Square of {number} is - {res}')

numbers = {1, 2, 3, 4, 5, 6, 7, 8}
square_list(numbers)
```


# debug / logpoint
```c
def square_list(numbers: list):

    for number in numbers:
        res = number ** 2

        print(f'Square of {number} is - {res}')

numbers = {1, 2, 3, 4, 5, 6, 7, 8}
square_list(numbers)
```


# debug / exceptions
```c
# try:
#     x = 10 / 0
# except ZeroDivisionError:
#     print("Handled error")

x = 10/0
```


# debug / assert
```c
#include <stdio.h>
#include <assert.h>

int main(void)
{
    int player_hp = 0;

    assert(player_hp > 0);

    return 0;
}
```


# debug / exception handle
```c
#include <stdio.h>

int main(void)
{
    int player_weight = 0;

    if (scanf("%d", &player_weight) != 1)
    {
        printf("Invalid input.");
        return 1;
    }

    printf("Player weight is %d", player_weight);

    return 0;
}
```

# debug / log
```c
#include <stdio.h>
#include <time.h>

void game_log(const char *log_type, const char *log_messages)
{
    FILE *file = fopen("game.log", "a");

    if (file == NULL)
    {
        perror("fopen: ");
        return;
    }

    time_t now = time(NULL);

    struct tm *time_info = localtime(&now);

    if (time_info != NULL)
    {
        fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] ", 
                time_info->tm_year + 1900,
                time_info->tm_mon + 1,
                time_info->tm_mday,
                time_info->tm_hour,
                time_info->tm_min,
                time_info->tm_sec);
    }

    fprintf(file, "[%s] %s", log_type, log_messages);

    if (fclose(file) == EOF)
    {
        perror("fclose: ");
    }
}

int main(void)
{

    game_log("ERROR", "Invalid input.");

    return 0;
}
```


# The roadmap of Data Structure(but dis is not for today tho.)
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



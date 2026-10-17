#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define PLAYER_MAX_HP 1000
#define PLAYER_MAX_MP 1000
#define PLAYER_MAX_LEVEL 99
#define PLAYER_MAX_ATK 100
#define PLAYER_MAX_DEF 100

#define MOB_MAX_HP 1000
#define MOB_MAX_MP 1000
#define MOB_MAX_LEVEL 99

typedef enum
{
    MAGE,
    WARRIOR,
    ARCHER,
    ASSASSIN,
    PRIEST
} Class;

typedef enum
{
    WOLF = 1,
    SLIME = 2,
    GOBLIN = 3,
    ORC = 4
} MOB;

typedef struct Item
{
    char name[30];
    int price;
    int quantity;

    struct Item *next;
} Item;

typedef struct
{
    char name[20];
    const char *race;
    Class player_class;
    int hp;
    int mp;
    int level;
    int gold;
    int atk;
    int def;
    Item *inventory;
} status;

typedef struct
{
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
} Wolf;

typedef struct
{
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
} Slime;

typedef struct
{
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
} Goblin;

typedef struct
{
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
} Orc;

// ===== Functions declaration =====

void Menu(void);
void Character_Status(status *player);
void Inventory_UI(status *player, int number_of_items);
void Shop(const char *Shop_items_names[], const int Shop_items_prices[], int Shop_number_of_items);
void Battle(void);
void Explore(void);
void Settings(void);
void Save_Load(void);
void BubbleSort(status *player, int number_of_items);
void Fibonacci(int Fibonacci_num, int Fibonacci_arr[]);
void clearScreen(void);
void Typetext(const char text[]);
void AddItem(status *player, char name[], int price, int quantity);

// ===== Main =====

int main()
{
    srand(time(NULL));

    // Player_Choose
    int Menu_Choice = 0;
    int Shop_Choice = 0;
    char Inventory_Choice[20] = {0};

    // Delay

    // Player_Stats
    status *player = malloc(sizeof(status));
    if (player == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for player.\n");
        return 1;
    }
    
    assert(player != NULL);
    assert(player->hp <= PLAYER_MAX_HP);
    assert(player->mp <= PLAYER_MAX_MP);

    // Inventory_items
    AddItem(player, "Sword", 150, 1);
    AddItem(player, "Potion", 50, 3);
    AddItem(player, "Hi-Potion", 100, 982982);
    AddItem(player, "Hammer", 150, 4);
    AddItem(player, "Dagger", 150, 3);
    AddItem(player, "Sword", 150, 1);

    int number_of_items = 6;

    // Shop_items
    const char *Shop_items_names[] = {
        "Sword", "Orb", "Hammer", "Dagger", "Potion", "Hi_Potion"};
    const int Shop_items_prices[] = {
        150, 150, 150, 150, 50, 100};
    int Shop_number_of_items = sizeof(Shop_items_prices) / sizeof(Shop_items_prices[0]);

    // Battle
    Wolf wolf = {
        "Hokkin", "Wolf", 2, 30, 10, 3, 1};
    Slime slime = {
        "Rimuru", "Slime", 1, 10, 10, 1, 1};
    Orc orc = {
        "Do", "Orc", 5, 50, 10, 20, 10};
    Goblin goblin = {
        "Diabulo", "Goblin", 1, 10, 10, 1, 1};

    // Fibonacci variables
    int Fibonacci_num = 20;
    int Fibonacci_arr[100];

    // The odds
    int enemy = 0;
    int event = 0;

    // Main Logic
    // Typetext("You woke up from your sleep\n");
    // Sleep(1000);
    // clearScreen();

    // Typetext("Press enter to continue...\n");
    // getchar();
    // clearScreen();
    // Sleep(1000);

    // Typetext("Please enter your name:\n");
    // scanf("%19s", player->name);

    // int length_player_name = strlen(player->name);
    // char massage[] = {"Your name is "};

    // strcat(massage, player->name);

    // printf("You have %d characters in ur name.\n", length_player_name);
    // Typetext(massage);
    // Sleep(2000);

    // clearScreen();

    // Typetext("Do u want to change ur name?\n");

    // // char player_input[4];
    // // scanf("%4s", player_input);

    // while (strcmp(player_input, "yes") != 0 || strcmp(player_input, "no") != 0)
    // {
    //     printf("Invalid input.\n");
    //     scanf("%4s", player_input);

    //     if (strcmp(player_input, "yes") == 0)
    //     {
    //         clearScreen();
    //         Typetext("Please enter your name:\n");

    //         char player_new_name[20];

    //         scanf("%19s", player_new_name);
    //         strcpy(player->name, player_new_name);

    //         printf("Your new name is \"%s\".\n");
    //         Sleep(2000);

    //         clearScreen();
    //         break;
    //     }
    //     if (strcmp(player_input, "no") == 0)
    //     {
    //         clearScreen();
    //         break;
    //     }
    // }

    while (1)
    {

        Menu();

        Typetext("Choose: ");
        scanf("%d", &Menu_Choice);

        switch (Menu_Choice)
        {
        case 1:
            Character_Status(player);

            Typetext("Enter \"Leave\" if u are sure u want to leave.\n");

            char Character_Status_Choice[6] = {0};

            scanf("%s", Character_Status_Choice);

            if (strcmp(Character_Status_Choice, "Leave") == 0)
            {
                clearScreen();
                break;
            }
            else
            {
                printf("Invalid input.\n");
            }

        case 2:
            Inventory_UI(player, number_of_items);

            printf("If u want to sort ur inventory(change ur item's quantity) by quantity using BubbleSort, pls enter \"ok\".\n");

            scanf("%9s", Inventory_Choice);

            if (strcmp(Inventory_Choice, "ok") == 0)
            {
                BubbleSort(player, number_of_items);
                Inventory_UI(player, number_of_items);

                Typetext("Enter \"Leave\" if u are sure u want to leave.\n");

                scanf("%6s", Inventory_Choice);

                while (strcmp(Inventory_Choice, "Leave") != 0)
                {
                    printf("Invalid input.\n");

                    scanf("%6s", Inventory_Choice);
                }

                clearScreen();
                break;
            }
            else
            {
                Typetext("Invalid input.\n");

                Sleep(1000);
                clearScreen();
                break;
            }

        case 3:
            Shop(Shop_items_names, Shop_items_prices, Shop_number_of_items);

            printf("Choose: ");
            scanf("%d", &Shop_Choice);

            if (Shop_Choice == 7)
            {
                printf("You left the Shop.");
            }
            else if (Shop_Choice >= 1 && Shop_Choice <= 6)
            {
                int item = Shop_Choice - 1;
                if (player->gold >= Shop_items_prices[item])
                {
                    player->gold -= Shop_items_prices[item];
                    printf("You bought %s successfully.\n"
                           "You've left %d G.\n",
                           Shop_items_names[item], player->gold);
                }
                else
                {
                    printf("You don't have enough money.\n");
                }
            }
            else
            {
                printf("Invalid number.\n");
            }
            break;

        case 4:
            enemy = rand() % 5;

            switch (enemy)
            {
            case 0:
                printf("You encountered slime!\n");
                break;

            case 1:
                printf("You encountered goblin!\n");
                break;

            case 2:
                printf("You encountered orc!\n");
                break;

            case 3:
                printf("You encountered wolf!\n");
                break;

            default:
                printf("Invalid input.\n");
                break;
            }

            getchar();
            break;

        case 5:
            event = rand() % 100;

            if (event < 30)
            {
                int random = rand() % 5;

                switch (random)
                {
                case 0:
                    printf("You encountered slime!\n");
                    break;

                case 1:
                    printf("You encountered goblin!\n");
                    break;

                case 2:
                    printf("You encountered orc!\n");
                    break;

                case 3:
                    printf("You encountered wolf!\n");
                    break;

                default:
                    printf("Invalid input.\n");
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
                Typetext("The road is queit...");
            }

            getchar();
            break;

        case 6:
            Settings();
            break;

        case 7:
            Save_Load();
            break;

        case 8:
            printf("╔═══════════════════════════════════════╗\n"
                   "║    Are you sure you want to leave?    ║\n"
                   "╚═══════════════════════════════════════╝\n");

            Typetext("Enter \"Yes\" if u are sure u want to leave.\n");

            char Exit_Choice[4];

            scanf("%4s", Exit_Choice);

            while (strcmp(Exit_Choice, "Yes") != 0)
            {
                printf("Invalid input.\n");

                scanf("%4s", Exit_Choice);
            }

            clearScreen();
            return 0;

        default:
            printf("Invalid number.\n");
            break;
        }

        getchar();
    }

    free(player);
}

// ===== Functions =====
void Menu(void)
{

    printf("╔══════════════════════════════╗\n"
           "║       THE LOST KINGDOM       ║\n"
           "╠══════════════════════════════╣\n"
           "║                              ║\n"
           "║ 1. Character Stats           ║\n"
           "║ 2. Inventory                 ║\n"
           "║ 3. Shop                      ║\n"
           "║ 4. Battle                    ║\n"
           "║ 5. Explore                   ║\n"
           "║ 6. Settings                  ║\n"
           "║ 7. Save / Load               ║\n"
           "║ 8. Exit                      ║\n"
           "║                              ║\n"
           "╚══════════════════════════════╝\n");
}

void Character_Status(status *player)
{
    printf("╔══════════════════════════════╗\n"
           "║          Characters          ║\n"
           "╠══════════════════════════════╣\n"
           "║ Name: %-23s║\n"
           "║ HP: %-25d║\n"
           "║ MP: %-25d║\n"
           "║ Level: %-22d║\n"
           "╠══════════════════════════════╣\n"
           "║ ATK: %-24d║\n"
           "║ DEF: %-24d║\n"
           "╠══════════════════════════════╣\n"
           "║ Gold: %-23d║\n"
           "╚══════════════════════════════╝\n",
           player->name, player->hp, player->hp, player->level, player->atk, player->def, player->gold);
}

void Inventory_UI(status *player, int number_of_items)
{
    printf("╔══════════════════════════════╗\n"
           "║          INVENTORY           ║\n"
           "╠══════════════════════════════╣\n");
    for (int i = 0; i < number_of_items; i++)
    {
        printf("║ %d. %-12s: %-12d║\n", i + 1, player->inventory[i].name, player->inventory[i].quantity);
    }

    printf("╚══════════════════════════════╝\n");
}

void Shop(const char *Shop_items_names[], const int Shop_items_prices[], int Shop_number_of_items)
{
    printf("╔══════════════════════════════╗\n"
           "║             SHOP             ║\n"
           "╠══════════════════════════════╣\n");

    for (int i = 0; i < Shop_number_of_items; i++)
    {
        printf("║ %d. %-12s: %-12d║\n", i + 1, Shop_items_names[i], Shop_items_prices[i]);
    }

    printf("╚══════════════════════════════╝\n");
}

void Battle(void)
{
    printf("╔══════════════════════════════╗\n"
           "║            Battle            ║\n"
           "╠══════════════════════════════╣\n"
           "║ 1. Sword: 150 G              ║\n"

           "╚══════════════════════════════╝\n");
}

void Explore(void)
{
    printf("╔══════════════════════════════╗\n"
           "║           Explore            ║\n"
           "╠══════════════════════════════╣\n"
           "║ 1. Sword: 150 G              ║\n"
           "║ 2. Orb: 150 G                ║\n"
           "║ 3. Hammer 150 G              ║\n"
           "║ 4. Dagger 150 G              ║\n"
           "║ 5. Potion: 50 G              ║\n"
           "║ 6. Hi-Potion: 100 G          ║\n"
           "║ 7. exit                      ║\n"
           "╚══════════════════════════════╝\n");
}

void Settings(void)
{
    printf("╔══════════════════════════════╗\n"
           "║           Settings           ║\n"
           "╠══════════════════════════════╣\n"
           "║ 1. Sword: 150 G              ║\n"
           "║ 2. Orb: 150 G                ║\n"
           "║ 3. Hammer 150 G              ║\n"
           "║ 4. Dagger 150 G              ║\n"
           "║ 5. Potion: 50 G              ║\n"
           "║ 6. Hi-Potion: 100 G          ║\n"
           "║ 7. exit                      ║\n"
           "╚══════════════════════════════╝\n");
}

void Save_Load(void)
{
    printf("Save / Load is not implemented yet.\n");
}

void BubbleSort(status *player, int number_of_items)
{

    for (int i = 0; i < number_of_items - 1; i++)
    {
        for (int j = 0; j < number_of_items - 1; j++)
        {
            if (player->inventory[j].quantity > player->inventory[j + 1].quantity)
            {
                Item temp = player->inventory[j + 1];
                player->inventory[j + 1] = player->inventory[j];
                player->inventory[j] = temp;
            }
        }
    }
}

void Fibonacci(int Fibonacci_num, int Fibonacci_arr[])
{
    if (Fibonacci_num < 1)
    {
        printf("Invalid number.");
        return;
    }

    if (Fibonacci_num >= 1)
        Fibonacci_arr[0] = 1;
    if (Fibonacci_num >= 2)
        Fibonacci_arr[1] = 2;

    for (int i = 0; i < Fibonacci_num - 2; i++)
    {
        Fibonacci_arr[i + 2] = Fibonacci_arr[i + 1] + Fibonacci_arr[i];
    }
}

// Not for menu
void Typetext(const char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(50);
    }
}

void clearScreen(void)
{
    system("cls");
}

void AddItem(status *player, char name[], int price, int quantity)
{
    // Create item
    Item *NewItem = malloc(sizeof(Item));

    strcpy(NewItem->name, name);
    NewItem->price = price;
    NewItem->quantity = quantity;
    
    // Add item into the inventory
    NewItem->next = player->inventory;
    player->inventory = NewItem;
}

// Damn we can use array here?
// why did I even ask AI after typing these word by word.
/*
if (Shop_Choice == 1)
    player->gold >= Sword
        ? (player->gold -= Sword,
           printf("You bought a Sword Successfully.\nYou've left %d G.\n", player->gold))
        : (printf("Ummm...I think u don't have enough money..."));
else if (Shop_Choice == 2)
        player->gold >= Orb
            ? (player->gold -= Orb,
               printf("You bought an Orb successfully.\nYou've left %d G.\n", player->gold))
            : (printf("I don't think u have enough money.\n"));
else if (Shop_Choice == 3)
        player->gold >= Hammer
                ? (player->gold -= Hammer,
                   printf("You bought a Hammer successfully.\nYou've left %d G.\n", player->gold))
                : (printf("I don't think u have enough money..."));
else if (Shop_Choice == 4)
        player->gold >= Dagger
                ? (player->gold -= Dagger,
                   printf("You bought a Dagger successfully.\nYou've left %d G", player->gold))
                : (printf("I don't think u have enough money..."));
else if (Shop_Choice == 5)
        player->gold >= Potion
                ? (player->gold -= Potion,
                   printf("You bought a Potion successfully.\nYou've left %d G", player->gold))
                : (printf("I don't really think u got enough money."));
else if (Shop_Choice == 6)
        player->gold >= Hi_Potion
                ? (player->gold -= Hi_Potion,
                   printf("You bought a Hi-Potion successfully.\nYou've left %d G", player->gold))
                : (printf("I don't really think u got enough money."));
else if (Shop_Choice == 7)
        printf("You left the store.");
*/
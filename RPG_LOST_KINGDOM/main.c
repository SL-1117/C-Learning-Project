#include <stdio.h>
#include <string.h>
#include <windows.h>

#define NOVICE_SWORD 1
#define FLAME_SWORD 2
#define DRAGON_SLAYER 3

typedef struct 
{
    char name[20];
    const char *race;
    int hp;
    int mp;
    int level;
    int gold;
    int atk;
    int def;
}status;

typedef struct {
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
}Wolf;

typedef struct {
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
}Slime;

typedef struct {
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
}Goblin;

typedef struct {
    const char *name;
    const char *race;
    int level;
    int hp;
    int mp;
    int atk;
    int def;
}Orc;

typedef enum   
{
    SUCCESS, FAILIURE, PENDING
}Connection_Status;

// ===== Functions declaration =====

void Menu(void);
void Character_Status(status player);
void Inventory(const char *Inventory_items_names[], int Inventory_quantity[], int number_of_items);
void Shop(const char *Shop_items_names[], const int Shop_items_prices[], int Shop_number_of_items);
void Battle(void);
void Explore(void);
void Settings(void);
void Save_Load(void);
void BubbleSort(int Inventory_quantity[], int number_of_items);
void Fibonacci(int Fibonacci_num, int Fibonacci_arr[]);
void clearScreen(void);
void Typetext(const char text[]);

// ===== Main =====

int main()
{

    // Player_Choose

    int Menu_Choice = 0;
    int Shop_Choice = 0;
    char Inventory_Choice[] = {};

    // Delay
    

    // Player_Stats

    status player = {
        "Eren", "Human", 100, 100, 1, 2000, 10, 10};

    // ===== Test =====
    int Player_weapon = 3;
    char Player_Weapon[20];
    char Player_location[20];
    char message[] = {"You entered "};
    Connection_Status Connection_Status = PENDING; 

    if (Connection_Status == PENDING)
    {
        Typetext("Creating your World...\n");
        Sleep(1000);
    }

    if (Player_weapon = DRAGON_SLAYER)              
    {
        Typetext("The player is hoding the Dragon slayer.\n");
    }

    strcpy(Player_location, "Dark Forest");
    strcat(message, Player_location); 
    Typetext(message);
    // ===== Test =====

    // Inventory_items

    const char *Inventory_items_names[] =
        {
            "Sword", "Potion", "Hi-Potion", "Orb", "Hammer", "Dagger"};
    int Inventory_quantity[] =
        {
            1, 3, 982982, 1, 4, 3};
    int number_of_items = sizeof(Inventory_quantity) / sizeof(Inventory_quantity[0]);

    // Shop_items

    const char *Shop_items_names[] = {
        "Sword", "Orb", "Hammer", "Dagger", "Potion", "Hi_Potion"};
    const int Shop_items_prices[] = {
        150, 150, 150, 150, 50, 100};
    int Shop_number_of_items = sizeof(Shop_items_prices) / sizeof(Shop_items_prices[0]);

    // Battle
    Wolf wolf = {
        "Hokkin", "Wolf", 2, 30, 10, 3, 1
    };
    Slime slime = {
        "Rimuru", "Slime", 1, 10, 10, 1, 1
    };
    Orc orc = {
        "Do", "Orc", 5, 50, 10, 20, 10
    };
    Goblin goblin = {
        "Diabulo", "Goblin", 1, 10, 10, 1, 1
    };

    // Fibonacci variables
    int Fibonacci_num = 20;
    int Fibonacci_arr[100];
    

    // Main Logic

    Typetext("You woke up from your sleep.\n");
    Sleep(1000);
    clearScreen();

    Typetext("Press enter to continue...\n");
    getchar();
    clearScreen();
    Sleep(1000);

    Typetext("Please enter your name:\n");
    scanf("%19s", player.name);
    clearScreen();

    Menu();

    Typetext("Choose: ");
    scanf("%d", &Menu_Choice);

    switch (Menu_Choice)
    {
    case 1:
        Character_Status(player);
        break;

    case 2:
        Inventory(Inventory_items_names, Inventory_quantity, number_of_items);

        printf("If u want to sort ur inventory(change ur item's quantity) by quantity using BubbleSort, pls enter \"ok\".\n");

        scanf("%9s", &Inventory_Choice);

        if (strcmp(Inventory_Choice, "ok") == 0)
        {   
            BubbleSort(Inventory_quantity, number_of_items);
            Inventory(Inventory_items_names, Inventory_quantity, number_of_items);
        }
        else 
        {
            printf("Invalid input.");
        }

        break;

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
            if (player.gold >= Shop_items_prices[item])
            {
                player.gold -= Shop_items_prices[item];
                printf("You bought %s successfully.\n"
                       "You've left %d G.\n",
                       Shop_items_names[item], player.gold);
            }
            else
            {
                printf("You don't have enough money.");
            }
        }
        else
        {
            printf("Invalid number.");
        }
        break;

    case 4:
        Battle();
        break;

    case 5:
        Explore();
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
        break;

    default:
        printf("Invalid number.");
        break;
    }

    getchar();

    return 0;
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

void Character_Status(status player)
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
           player.name, player.hp, player.mp, player.level, player.atk, player.def, player.gold);
}

void Inventory(const char *Inventory_items_names[], int Inventory_quantity[], int number_of_items)
{
    printf("╔══════════════════════════════╗\n"
           "║          INVENTORY           ║\n"
           "╠══════════════════════════════╣\n");
    for (int i = 0; i < number_of_items; i++)
    {
        printf("║ %d. %-12s: %-12d║\n", i + 1, Inventory_items_names[i], Inventory_quantity[i]);
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

void BubbleSort(int Inventory_quantity[], int number_of_items)
{   

    for (int i = 0; i < number_of_items - 1; i++) 
    {
        for (int j = 0; j < number_of_items - 1; j++)
        {
            if (Inventory_quantity[j] > Inventory_quantity[j + 1]) 
            {
                int temp = Inventory_quantity[j + 1];
                Inventory_quantity[j + 1] = Inventory_quantity[j];
                Inventory_quantity[j] = temp;
            }
        }
    }
}

void Fibonacci (int Fibonacci_num, int Fibonacci_arr[]) 
{
    if (Fibonacci_num < 1) 
    {
        printf("Invalid number.");
        return;
    }

    if (Fibonacci_num >= 1) Fibonacci_arr[0] = 1;
    if (Fibonacci_num >= 2) Fibonacci_arr[1] = 2;

    for (int i = 0; i < Fibonacci_num - 2; i++)
    {
        Fibonacci_arr[i + 2] = Fibonacci_arr[i + 1] + Fibonacci_arr[i];
    }

}

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

// Damn we can use array here?
// why did I even ask AI after typing these word by word.
/*
if (Shop_Choice == 1)
    player.gold >= Sword
        ? (player.gold -= Sword,
           printf("You bought a Sword Successfully.\nYou've left %d G.\n", player.gold))
        : (printf("Ummm...I think u don't have enough money..."));
else if (Shop_Choice == 2)
        player.gold >= Orb
            ? (player.gold -= Orb,
               printf("You bought an Orb successfully.\nYou've left %d G.\n", player.gold))
            : (printf("I don't think u have enough money.\n"));
else if (Shop_Choice == 3)
        player.gold >= Hammer
                ? (player.gold -= Hammer,
                   printf("You bought a Hammer successfully.\nYou've left %d G.\n", player.gold))
                : (printf("I don't think u have enough money..."));
else if (Shop_Choice == 4)
        player.gold >= Dagger
                ? (player.gold -= Dagger,
                   printf("You bought a Dagger successfully.\nYou've left %d G", player.gold))
                : (printf("I don't think u have enough money..."));
else if (Shop_Choice == 5)
        player.gold >= Potion
                ? (player.gold -= Potion,
                   printf("You bought a Potion successfully.\nYou've left %d G", player.gold))
                : (printf("I don't really think u got enough money."));
else if (Shop_Choice == 6)
        player.gold >= Hi_Potion
                ? (player.gold -= Hi_Potion,
                   printf("You bought a Hi-Potion successfully.\nYou've left %d G", player.gold))
                : (printf("I don't really think u got enough money."));
else if (Shop_Choice == 7)
        printf("You left the store.");
*/
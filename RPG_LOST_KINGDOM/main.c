#include <stdio.h>
#include <string.h>

struct status
{
    char name[20];
    int hp;
    int mp;
    int level;
    int gold;
    int atk;
    int def;
};

// ===== Functions declaration =====

void Menu(void);
void Character_Status(struct status player);
void Inventory(const char *Inventory_items_names[], int Inventory_quantity[], int number_of_items);
void Shop(const char *Shop_items_names[], const int Shop_items_prices[], int Shop_number_of_items);
void Battle(void);
void Explore(void);
void Settings(void);
void Save_Load(void);

// ===== Main =====

int main()
{

    // Player_Choose

    int Menu_Choose = 0;
    int Shop_Choose = 0;

    // Player_Stats

    struct status player = {
        "Eren", 100, 100, 8, 1000, 10, 100};

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

    // Main Logic

    printf("You woke up from your sleep.\n");
    printf("Press enter to continue...\n");
    getchar();

    printf("Please enter your name:\n");
    scanf("%19s", player.name);

    Menu();

    printf("Choose: ");
    scanf("%d", &Menu_Choose);

    switch (Menu_Choose)
    {
    case 1:
        Character_Status(player);
        break;

    case 2:
        Inventory(Inventory_items_names, Inventory_quantity, number_of_items);
        break;

    case 3:
        Shop(Shop_items_names, Shop_items_prices, Shop_number_of_items);

        printf("Choose: ");
        scanf("%d", &Shop_Choose);

        if (Shop_Choose == 7)
        {
            printf("You left the Shop.");
        }
        else if (Shop_Choose >= 1 && Shop_Choose <= 6)
        {
            int item = Shop_Choose - 1;
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
           "║ 1. Character Stats           ║\n"
           "║ 2. Inventory                 ║\n"
           "║ 3. Shop                      ║\n"
           "║ 4. Battle                    ║\n"
           "║ 5. Explore                   ║\n"
           "║ 6. Settings                  ║\n"
           "║ 7. Save / Load               ║\n"
           "║ 8. Exit                      ║\n"
           "╚══════════════════════════════╝\n");
}

void Character_Status(struct status player)
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
           "║ 2. Orb: 150 G                ║\n"
           "║ 3. Hammer 150 G              ║\n"
           "║ 4. Dagger 150 G              ║\n"
           "║ 5. Potion: 50 G              ║\n"
           "║ 6. Hi-Potion: 100 G          ║\n"
           "║ 7. exit                      ║\n"
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

// Damn we can use array here?
// why did I even ask AI after typing these word by word.
/*
if (Shop_Choose == 1)
    player.gold >= Sword
        ? (player.gold -= Sword,
           printf("You bought a Sword Successfully.\nYou've left %d G.\n", player.gold))
        : (printf("Ummm...I think u don't have enough money..."));
else if (Shop_Choose == 2)
        player.gold >= Orb
            ? (player.gold -= Orb,
               printf("You bought an Orb successfully.\nYou've left %d G.\n", player.gold))
            : (printf("I don't think u have enough money.\n"));
else if (Shop_Choose == 3)
        player.gold >= Hammer
                ? (player.gold -= Hammer,
                   printf("You bought a Hammer successfully.\nYou've left %d G.\n", player.gold))
                : (printf("I don't think u have enough money..."));
else if (Shop_Choose == 4)
        player.gold >= Dagger
                ? (player.gold -= Dagger,
                   printf("You bought a Dagger successfully.\nYou've left %d G", player.gold))
                : (printf("I don't think u have enough money..."));
else if (Shop_Choose == 5)
        player.gold >= Potion
                ? (player.gold -= Potion,
                   printf("You bought a Potion successfully.\nYou've left %d G", player.gold))
                : (printf("I don't really think u got enough money."));
else if (Shop_Choose == 6)
        player.gold >= Hi_Potion
                ? (player.gold -= Hi_Potion,
                   printf("You bought a Hi-Potion successfully.\nYou've left %d G", player.gold))
                : (printf("I don't really think u got enough money."));
else if (Shop_Choose == 7)
        printf("You left the store.");
*/
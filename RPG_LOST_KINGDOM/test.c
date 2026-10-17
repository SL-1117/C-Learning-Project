#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player 
{
    char name[20];
    int hp;
    int mp;
    int race;
    struct Item *inventory;
};

struct Item
{
    char name[30];
    int price;
    int quantity;

    struct Item *next;
};

void AddItem(struct Player *player, char name[], int price) 
{
    // Create item
    struct Item *NewItem;

    NewItem = malloc(sizeof(struct Item));
    
    strcpy(NewItem->name, name);
    NewItem->price = price;
    NewItem->quantity = 1;

    // Add item into the inventory
    NewItem->next = player->inventory;
    player->inventory = NewItem;
}

int main(void) 
{
    struct Player *player;
    
    // Create player
    player = malloc(sizeof(struct Player));
    player->inventory = NULL;

    // Add items
    AddItem(player, "Potion", 50);
    AddItem(player, "Sword", 100);
    AddItem(player, "Orb", 100);

    // Print the linked list
    struct Item *current;
    struct Item *next;
    current = player->inventory;

    while (current != NULL)
    {
        printf("%s\n", current->name);

        next = current->next;

        free(current);
        
        current = next;
    }

    free(player);

    return 0;

}

    // // Inventory_items
    // Item *Inventory = malloc(25 * sizeof(Item));
    // Inventory[0] = (Item){"Sword", 1};
    // Inventory[1] = (Item){"Potion", 3};
    // Inventory[2] = (Item){"Hi-Potion", 982982};
    // Inventory[3] = (Item){"Orb", 1};
    // Inventory[4] = (Item){"Hammer", 4};
    // Inventory[5] = (Item){"Dagger", 3};
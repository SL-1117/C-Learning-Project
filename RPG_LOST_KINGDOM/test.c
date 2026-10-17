#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int Inventory_quantity[] = {
        10, 9, 330, 20898, 29
    };

    int Inventory_num = sizeof(Inventory_quantity) / sizeof(Inventory_quantity[0]);

    int *Inventory = malloc(Inventory_num * sizeof(int));

    if (Inventory == NULL)
    {
        printf("Allocation failed.\n");
        return 1;
    }

    Inventory[0] = 1;
    Inventory[1] = 2;
    Inventory[2] = 3;

    for (int i = 0; i < Inventory_num; i++) 
    {
        printf("%d\n", Inventory[i]);
    }

    free(Inventory);

    return 0;
}
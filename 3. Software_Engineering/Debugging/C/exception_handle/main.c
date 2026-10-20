#include <stdio.h>

int main(void)
{
    int player_hp = 1;

    if (scanf("%d", &player_hp) != 1)
    {
        printf("Invalid input.");
        return 1;
    }

    return 0;
}
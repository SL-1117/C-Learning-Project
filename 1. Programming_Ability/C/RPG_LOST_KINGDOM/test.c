#include <stdio.h>

int main(void)
{
    int player_height = 170;
    int player_weight = 0;

    if (scanf("%d", &player_weight) != 1)
    {
        printf("Invalid input.");
        return 1;
    }

    printf("%d", player_height);
    printf("Player weight is %d", player_weight);

    return 0;
} 
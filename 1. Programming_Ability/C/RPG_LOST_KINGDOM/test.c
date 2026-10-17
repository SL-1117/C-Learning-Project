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
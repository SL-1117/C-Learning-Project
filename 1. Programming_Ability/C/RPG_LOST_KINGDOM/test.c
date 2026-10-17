#include <stdio.h>
#include <stdbool.h>

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
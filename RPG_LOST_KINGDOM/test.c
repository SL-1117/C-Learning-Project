#include <stdio.h>
#include <string.h>

struct status {
    int age;
    int salary;
};

int main(void) {
    
    struct status Player;
    struct status Player_2;

    Player.age = 22;
    Player_2.age = 30;

    printf("%d", Player.age);

    return 0;
}
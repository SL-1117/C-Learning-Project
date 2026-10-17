#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

bool age18Check(int age)
{
    if (age >= 18) return true;
    else return false;
}

bool age18Check2(int age)
{
    return age >= 18;
}

char AttackCheck(void) 
{
    int hp = 10;

    do {
        printf("Attack!\n");
        hp -= 1;
        Sleep(1000);
    } while (hp > 0);
}

int main(void) 
{
    bool islocked = true;

    char name[20] = "";
    char operator = '\0';

    float weight = 0.0f;
    float height = 0.0f;
    float rnum = 10.00;

    double num1 = 0.0;
    double num2 = 21.34;
    double result = 0.0;

    int age = 3;

    printf("Enter ur name: \n");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("ur name is %s\n", name);
    printf("ur age is %.2lf\n", age);

    if (islocked == true)
    {
        if (age18Check2(18))
        {
            printf("You are already 18.\n");
        }

        else 
        {
            printf("You are not 18 yet.\n");
        }

        printf("You ara locked.\n");
    }

    else if (islocked == false)
    {
        printf("You are not a locked.\n");
    }

    printf("num1's value is %lf\n", num1);
    printf("num2's value is %.2f\n", num2);

    AttackCheck();

    getchar();
}

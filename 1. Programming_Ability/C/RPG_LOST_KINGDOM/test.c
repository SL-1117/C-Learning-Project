#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef int HelloNumber;
typedef uint8_t HelloLnumber;
typedef char HelloTest[3];
typedef char *HelloPointer;

int main(void)
{
    HelloNumber Anumber = 8387;
    HelloLnumber anumber = 98;
    HelloTest name = "BT";
    HelloPointer name2 = "SP";

    printf("%d\n", Anumber);
    printf("%d\n", anumber);
    printf("%s\n", name);
    printf("%s\n", name2);
    

    getchar();
}
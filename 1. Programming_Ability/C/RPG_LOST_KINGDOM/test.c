#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    
    int num = 0;

    scanf("%d", &num);

    printf("%-4d", num);
    printf("2");

    getchar();

}
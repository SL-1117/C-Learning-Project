#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int input = 0;

    scanf("%d", &input);

    int *memory = calloc(input, sizeof(int));

    if (memory == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < input; i++)
    {
        printf("%d ", memory[i]);
    }

    return 0;
}
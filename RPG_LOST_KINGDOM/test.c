#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int radius;
    double area;
    double surfaceArea;
    double volume;
} Circle;

int main(void)
{
    Circle circle;
    circle.radius = 3;
    const float PI = 3.14159;

    circle.area = PI * pow(circle.radius, 2);
    circle.surfaceArea = 4.0 * PI * pow(circle.radius, 2);
    circle.volume = (4.0 / 3.0) * PI * pow(circle.radius, 3);

    printf("The circle's area is %lf.\n"
           "The circle's surfaceArea is %lf.\n"
           "The circle's volume is %lf.\n",
           circle.area, circle.surfaceArea, circle.volume);

    char *messages = malloc(25 * sizeof(char));

    if (messages == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    fgets(messages, 25, stdin);
    messages[strcspn(messages, "\n")] = '\0';

    printf("%s\n", messages);

    free(messages);
    getchar();

    return 0;
}
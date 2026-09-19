#include <stdio.h>
#include <string.h>

int main() {

    int user_input1 = 0;
    int user_input2 = 0;
    char user_operator = 0;

    printf("Please enter the first integer: \n");
    scanf("%d", &user_input1);

    printf("Please enter the operator: \n");
    scanf(" %c", &user_operator);

    printf("Please enter the second integer: \n");
    scanf("%d", &user_input2);

    if (user_operator == '+') {
        printf("The result is: %d\n", user_input1 + user_input2);
    } else if (user_operator == '-') {
        printf("The result is: %d\n", user_input1 - user_input2);
    } else if (user_operator == '*') {
        printf("The result is: %d\n", user_input1 * user_input2);
    } else if (user_operator == '/') {
        printf("The result is: %d\n", user_input1 / user_input2);
    } else if (user_operator == '%') {
        printf("The result is: %d\n", user_input1 % user_input2);
    } else {
        printf("Invalid operator entered.\n");
    }

    return 0;
    
}
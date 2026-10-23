#include "history_stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int player_hp = 10;
    int potion_restore = 30;
    
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return 0;

    Init_stack(stack);

    BattleAction action = {
        .name = "Drink Potion",
        .old_value = 100,
        .new_value = potion_restore
    };

    if (push(stack, action) != 0)
    {
        fprintf(stderr, "Failed to push action onto history stack.\n");
        return 1;
    }
    
    printf("[Action]: %s\n"
           "[Player_hp]: %d",
            action.name, action.new_value);

    free(stack);
    
    return 0;
}
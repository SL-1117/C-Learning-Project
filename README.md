# C-Learning-Project

2026/9/20 Saturday

The second day learning C by making a RPG game.

# getchar()

### Learned what is pointer and array

# const 
is for fixed strings, means that it's not gonna be changed.

# pointer
it makes the variable store the address of the value and point to them.

# char item_names = 'A';
it's only for one character.

# char item_names[][20] = {
    "Sword", "Orb"
};
it's for the string and define the lenghs on ur own.

# char *item_names[] = {
    "Sword", "Orb"
};
Also works bc it's a pointer that point to the address of the variable "item_names[]"

## what I used for

const char *item_names[] = {
    "Sword", "Dagger", "Orb", "Hammer", "Potion", "Hi_Potion"
};

int item_prices[] = {
    150, 150, 150, 150, 50, 100
};


### How to use Struct to make a template.
struct status {
    const char *name;
    const char *profession;
    int level;
    int hp;
    int mp;
    int gold;
};

int main(void) {
    sturct status player;
    player.name = "";
    player.profession = "";
    player.level = 99;
    player.hp = 100000;
    player.mp = 100000;
    player.gold = 1000;
    
    scanf("%19s", &player.name);

    printf("%s %d %d", player.name, player.level, player.hp);
}

# We can also use struct as something like the array.
struct status {
    const char *name;
    const char *profession;
    int level;
    int hp;
    int mp;
    int gold;
};

int main(void) {
    struct status player = {
        "Eren", "Warrior", 99, 100000, 100000, 1000
    };

    scanf("%s", &player.name);

    printf("%s %d %d", player.name, player.level, player.hp);

}

# Btw we also need to put & inside while using scanf.

scanf("%19s", &player.name);
 
### How to declare the functions to make them easier to manage.
void Menu(void);
void Character_Status(struct status player);
void Battle(viod);
void Shop(const char *Shop_items_names, const char *Shop_items_prices, int Shop_number_of_items);

int main(void)
{
    ...
}

And then put the functions right after the main code is pretty good.

*We need to define its variable type here but we don't need to do that when using them in the main program.
We only need to put the variable like Shop_items_names inside the parenthesis(brackets in British English).

### How to know how many numbers in an array.

Shop_number_of_items = sizeof(Shop_items_prices) / sizeof(Shop_items_prices[0]); 

The sizeof(Shop_items_prices) is calculating the total bits inside the array, which is 8 times 4 equals to 32 if we got 4 items inside.;
And the sizeof(Shop_items_prices[0]) is calculating the size of first thing in that array, which is basically 8 bits.
Btw 1 byte = 8 bits

### How to do an easy logic to make the menu list items and format all by itself.
##  And also how to use %-12s and %-12d to align.

printf("╔══════════════════════════════╗\n"
       "║             SHOP             ║\n"
       "╠══════════════════════════════╣\n");


for (int i = 0; i < Shop_number_of_items; i++) 
{  
    printf("║ %d. %-12s: %-12d║\n", i + 1, Shop_items_name[i], Shop_items_prices[i]);
}

printf("╚══════════════════════════════╝\n");

This is amazing actually.

### Oh I also learned how to determine whether to use switch or if else logic

switch(Menu_Choose) 
{
    case 1:
        Character_Status();
        break;
    
    case 2:
        Shop();
        break;

    case 3:
        Inventory();
        break;

    default:
        printf("Invalid...");
        break;
}

# See we r checking one value against a bunch of exact choices, or we r checking conditions

### How to use "void" and what it is.
so basically it means literally nothing.

void Menu(void) {
    ...
}

the former void means there is nothing going to be output.
the latter void means there is nothing going to be input.
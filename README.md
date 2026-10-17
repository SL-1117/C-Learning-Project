# C-Learning-Project

2026/9/19 

This is my first day learning C by making a RPG game.

### How define variables correctly.

int         (%d) 
Float       (%.2f) 
Double      (%.3lf)
char        (%c)
char[]      (%s)

//Definitely wrong.
int Sword, Orb, Hammer, Dagge = 150;   

int Sword = 150, Orb = 150, Hammer = 150, Dagger = 150;  
char[] = "";

### How to use basic logic.

scanf("", &)

# How to use \n
printf("%d\n", Player_Gold)

# How to short Player_Gold = Player - Sword;
Player_Gold -= Sword;

if () {}
else if () {}



### How to use one printf to make this.

        printf("╔══════════════════════════════╗\n"
               "║         Save / Load          ║\n"
               "╠══════════════════════════════╣\n"
               "║ 1. Sword: 150 G              ║\n"
               "║ 2. Orb: 150 G                ║\n" 
               "║ 3. Hammer 150 G              ║\n" 
               "║ 4. Dagger 150 G              ║\n" 
               "║ 5. Potion: 50 G              ║\n" 
               "║ 6. Hi-Potion: 100 G          ║\n" 
               "║ 7. exit                      ║\n"
               "╚══════════════════════════════╝\n",
               and if we r gonna put some varibles here);



### How to make the program shorter without using {}

if ()
    The inside "if" logic 
        : (The first logic, 
           The second logic)
        ? (The inside else if logic);

else if ()
    Same logic


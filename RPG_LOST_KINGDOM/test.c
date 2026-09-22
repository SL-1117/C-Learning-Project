#include <stdio.h>
#include <windows.h>

void Typetext(char message[]);

int main(void) {

    char message[100] = {"Welcome to the LOST KINGDOM!"};

    Typetext("Hello Player!");
    Sleep(1000);
    system("cls");

    Typetext(message);
    Sleep(1000);

    getchar();

}

void Typetext(char message[])
{

    for (int i = 0; message[i] != '\0'; i++)
    {
        printf("%c", message[i]);
        fflush(stdout);
        Sleep(50);
    }

}
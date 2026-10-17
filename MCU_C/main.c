// #include "NUC100Series.h"
// #include "MCU_init.h"
// #include "SYS_init.h"
// #include "Seven_Segment.h"
// #include "Scankey.h"

#define BUZZER PB11
#define RED PA14
#define GREEN PA13
#define BLUE PA12

#define C 8
#define R 9

void Show_7segment(int num);
void Buzz(void);

int IsPrime(int num);

void ClearALL(void);

int main(void)
{
    int key = 0;
    int last_key = 0;
    int num = 0;
    
    SYS_Init();

    OpenSevenSegment();
    OpenKeyPad();

    GPIO_SetMode(PA, BIT12, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PA, BIT13, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PA, BIT14, GPIO_MODE_OUTPUT);

    GPIO_SetMode(PB, BIT11, GPIO_MODE_OUTPUT);

    BUZZER = 1;

    srand(SysTick -> VAL);

    while (1)
    {
        key = Scankey();

        if (last_key == C && key == 0)
        {
            num = 0;
            ClearALL();
        }

        if (last_key == R && key == 0)
        {
            num = rand() % 99 + 1;

            if (IsPrime(num))
            {
                RED = 0;

                if (num % 2 == 0) BLUE = 0;
                if (num % 3 == 0) GREEN = 0;
                
                Buzz();
            }

            else 
            {
                if (num % 2 == 0) BLUE = 0;
                if (num % 3 == 0) GREEN = 0;
            }
        }

        Show_7segment(num);

        last_key = key;
    }

}

void Show_7segment(int num)
{
    static int digit = 0;

    int d0 = num % 10; 
    int d1 = (num / 10) % 10;

    CloseSevenSegment();

    if (digit == 0 && num != 0) ShowSevenSegment(0, d0);
    if (digit == 1 && num >= 10) ShowSevenSegment(1, d1);

    digit++;

    if (digit >= 2) digit = 0;
}

void Buzz(void)
{
    BUZZER = 0;
    CLK_SysTickDelay(2000);

    BUZZER = 1;
    CLK_SysTickDelay(2000);
}

int IsPrime(int num)
{
    if (num < 2) return 0;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void ClearALL(void)
{
    BUZZER = 1;
    RED = 1;
    BLUE = 1;
    GREEN = 1;
    CloseSevenSegment();
}
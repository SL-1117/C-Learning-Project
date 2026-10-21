#include <stdio.h>
#include <stdint.h>
#include "NUC100Series"

#define S_A BIT3
#define S_B BIT4
#define S_C BIT0
#define S_D BIT5
#define S_E BIT6
#define S_F BIT2
#define S_G BIT7
#define S_DOT BIT1

#define CH_1   SEG(S_B | S_C)
#define CH_2   SEG(S_A | S_B | S_D | S_E | S_G)
#define CH_3   SEG(S_A | S_B | S_C | S_D | S_G)
#define CH_4   SEG(S_B | S_C | S_F | S_G)
#define CH_5   SEG(S_A | S_C | S_D | S_F | S_G)
#define CH_6   SEG(S_A | S_C | S_D | S_E | S_F | S_G)
#define CH_7   SEG(S_A | S_B | S_C)
#define CH_8   SEG(S_A | S_B | S_C | S_D | S_E | S_F | S_G)
#define CH_9   SEG(S_A | S_B | S_C | S_F | S_G)

#define CHAR_i (S_C)
#define CHAR_E (S_A|S_D|S_E|S_F|S_G)
#define CHAR_C (S_A|S_D|S_E|S_F)
#define CHAR_S (S_A|S_C|S_D|S_F|S_G)

volatile int press_count = 0;

void display(uint32_t segment)
{
    PE->DOUT = (PE->DOUT & 0xFFu) | (0xFF & segment);
}

int main(void)
{
    SYS_UnlockReg();
    SYS_Init();
    SYS_LockReg();

    GPIO_SetMode(PE, 0xFF, GPIO_MODE_OUTPUT);

    while (1)
    {
        key = keypad();

        if (pressed_key == 3)
        {
            press_count++;

            if (press_count <= 8)
            {
                // The digit is not gonna show at each 7segment
                
                for (int i = press_count; i < press_count + 4; i++)
                {
                    PE->DOUT |= seg[i];
                    CLK_SysTickDelay(2000);
                    CloseSevenSegment();
                }
            }

            else 
            {
                press_count = 0;

                for (int i = press_count; i < press_count + 4; i++)
                {
                    PE->DOUT |= seg[i];
                    CLK_SysTickDelay(2000);
                    CloseSevenSegment();
                }
            }
        }

        else if (pressed_key == 1) 
        {
            press_count--;

            if (press_count >= 0)
            {
                for (int i = press_count; i < press_count + 4; i++)
                {
                    PE->DOUT |= seg[i];
                    CLK_SysTickDelay(2000);
                    CloseSevenSegment();
                }
            }

            else
            {
                press_count = 8;

                for (int i = press_count; i < press_count + 4; i++)
                {
                    PE->DOUT |= seg[i];
                    CLK_SysTickDelay(2000);
                    CloseSevenSegment();
                }
            }
        }

        key = pressed_key;
    }
}
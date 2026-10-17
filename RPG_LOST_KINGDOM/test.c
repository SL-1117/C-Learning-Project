#include <stdio.h>
#include <string.h>

struct status
{
    int age;
    int salary;
};

void BubbleSort(int arr[], int Total_num);

int main(void)
{

    struct status Player;
    struct status Player_2;

    Player.age = 22;
    Player_2.age = 30;

    int arr[] =
        {
            10,
            9,
            928,
            490,
            1,
            0,
            -100,
            3,
            0,
    };

    int Total_num = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, Total_num);

    for (int i = 0; i < Total_num; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void BubbleSort(int arr[], int Total_num)
{

    for (int i = 0; i < Total_num - 1; i++)
    {

        for (int j = 0; j < Total_num - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
# C-Learning-Project

2026/9/20 Sunday

The this is the third day I start learning C by making a game.

### The basic Git workflow for managing code.

let's start from the notes

So basically never use git init in the same project twice, that's gonna mess the whole thingy in the folder up.

# git add . 

# git commit -m "Day_3"

# git push -u origin Day_3

We did this bc the branch Day_3 still didn't know which remote repository to push to.

Now we can use git push/pull to manage.

If we pushed the wrong version that still doesn't finish yet, js delete it and push the finished version.

# git checkout 

# git diff

# git log (--oneline)

# git reflog 

use this when we used git checkout but js feel going back to some past saving point

I think I know pretty much abt git




### strcmp and 

# \"ok\" ===> "ok"

it's used to compare two strings

if (strcmp(Player_input, "ok") == 0) 
{
    printf("The player entered \"ok\".\n");
}




### BubbleSort 

it's used to sort the number in ascending order.
as for why do we use void here is bc that the code js modified the main program,
it's not seperately generate other outputs.
and also, we need to define the "total_num" outside the function,
bc the input "int arr[]" is js a pointer that point to the arr.
it cannot be used to calculate the number in the arr.

void BubbleSort (int arr[], int total_num)
{
    for (int i = 0; i < total_num - 1; i++)
    {
        for (int j = 0; i < total_num -1; j++)
        {
            if (arr[j] > arr[j + 1])   
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr [j + 1] = temp;
            } 
        }
    }
}
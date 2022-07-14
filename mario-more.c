#include <stdio.h>
#include<cs50.h>
int main(void)
{
    int n;
    do
    {
        //this will take input from user between [1,8]
        n = get_int("ENTER THE HEIGHT(1-8):");
        if (n >= 1 && n <= 8)  // to setlle the limits
        {
            break;
        } 


    }

    while (n != 1); //to create a set A{1,2,3,4,5,6,7,8}

    for (int i = 1 ; i <= n ; i ++) // for the rows
    {
        for (int j = 0; j < (n - i); ++j) //to print the spaces
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++) //to print the columns
        {
            printf("#");
        }
        printf("  "); // to get 2 unit space between 2 pyramids
        for (int k = 0; k < i; k++)
        {
            printf("#"); //to print the columns
        }
        printf("\n");
    }
}



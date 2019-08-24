#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Enter the desired height : ");

    int ht = get_int();
    //To ensure that the user entered a number only between 0 and 23.
    while (ht < 0 || ht > 23)
    {
        printf("Enter a number between 0 and 23 only\nEnter:");
        ht = get_int();
    }

    //The printing starts.
    for (int i = 1; i <= ht; i++)
    {
        //To print the rows of first pyramid.
        for (int j = ht - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        //Two spaces of gap between the rows of the set of pyramids.
        printf("  ");

        //To print the rows of the second pyramid.
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//END OF PROGRAM
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO
    printf("How much amount do I owe you?\nEnter: ");

    //Initialising variables and setting their values
    float owe = get_float();
    int cents = rint(owe * 100);
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int count = 0;

    //Ensuring the user entered value is valid.
    while (cents < 0)
    {
        printf("Enter valid value\nEnter: ");
        owe = get_float();
        cents = rint(owe * 100);
    }


    //While loop to count the number of coins down till pennies.
    while (cents != 0)
    {
        //To count the quarters.
        if (cents >= quarter)
        {
            count++;
            cents = cents - quarter;
        }
        //To count the dimes.
        else if (cents >= dime && cents < 25)
        {
            count++;
            cents = cents - dime;
        }
        //To count the nickels.
        else if (cents >= nickel && cents < 10)
        {
            count++;
            cents = cents - nickel;
        }
        //To count the pennies.
        else if (cents >= penny && cents < 5)
        {
            count++;
            cents -= penny;
        }
    }

    //To print the counted number of coins.
    printf("%i\n", count);

}














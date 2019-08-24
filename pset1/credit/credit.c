#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    //Initialising the variables.
    long long num;
    int scc, checkSum = 0, i = 0, j = 0;
    int cc[20], cc_number[20];

    printf("Number: ");
    num = get_long_long();

    //to convert and store the given number in an array backwards.
    while (num != 0)
    {

        cc[i] = num % 10;
        num = num / 10;
        i++;
    }

    int length = i;
    j = i - 1;
    i = 0;

    /*To store the numbers of cc array in cc_number array from the back
    so that it's stored forwards in array format*/
    while (i < length && j >= 0)
    {
        cc_number[i] = cc[j];
        i++, j--;
    }

    /*Multiplying every other digit by 2, starting with the number’s second-to-last digit,
    and then adding those product's digits together.*/
    for (i = length - 2; i >= 0; i -= 2)
    {
        scc = cc_number[i] * 2;

        if (scc > 9)
        {
            checkSum += scc % 10;
            scc = scc / 10;
        }
        checkSum = checkSum + scc;
    }

    //Adding the remaining digits which weren't multiplied by 2 to the previous sum.
    for (i = length - 1; i >= 0; i -= 2)
    {
        checkSum += cc_number[i];
    }

    //Checking if its VALID or INVALID.
    if (checkSum % 10 == 0)
    {
        //Checking if its an AMEX card.
        if (length == 15 && cc_number[0] == 3)
        {
            if (cc_number[1] == 4 || cc_number[1] == 7)
            {
                printf("AMEX\n");
            }

        }
        //Checking if its a MASTERCARD.
        else if (length == 16 && cc_number[0] == 5)
        {
            if (cc_number[1] == 1 || cc_number[1] == 2 || cc_number[1] == 3 || cc_number[1] == 4
                || cc_number[1] == 5)
            {
                printf("MASTERCARD\n");
            }
        }
        //Checking if its a VISA card.
        else if ((length == 13 || length == 16) && cc_number[0] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("VALID\nCannot determine the company.\n");
        }


    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

//END OF PROGRAM.